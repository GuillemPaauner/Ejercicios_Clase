// Ejercicio 5.2: tarifas para los tres clientes de ayer.
#include <algorithm>
#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>

double calculateCharges(double horas) {
    if (horas <= 3.0) {
        return 20.0;
    }
    return std::min(50.0, 20.0 + 5.0 * std::ceil(horas - 3.0));
}

int main() {
    std::array<double, 3> horas{};
    for (int i = 0; i < 3; ++i) {
        std::cout << "Horas del cliente " << i + 1 << " (mayor que 0 y hasta 24): ";
        if (!(std::cin >> horas[i]) || !std::isfinite(horas[i]) || horas[i] <= 0.0 || horas[i] > 24.0) {
            std::cerr << "Horas no validas.\n";
            return 1;
        }
    }
    double totalHoras = 0.0, totalImporte = 0.0;
    std::cout << '\n' << std::left << std::setw(8) << "Car" << std::right
              << std::setw(10) << "Hours" << std::setw(12) << "Charge" << '\n';
    for (int i = 0; i < 3; ++i) {
        const double importe = calculateCharges(horas[i]);
        totalHoras += horas[i];
        totalImporte += importe;
        std::cout << std::left << std::setw(8) << i + 1 << std::right << std::fixed
                  << std::setprecision(1) << std::setw(10) << horas[i]
                  << std::setprecision(2) << std::setw(12) << importe << '\n';
    }
    std::cout << std::left << std::setw(8) << "TOTAL" << std::right
              << std::setprecision(1) << std::setw(10) << totalHoras
              << std::setprecision(2) << std::setw(12) << totalImporte << '\n';
}
