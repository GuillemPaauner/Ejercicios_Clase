// Ejercicio 3.25 c: suma desde k = 0 hasta N - 1 mediante while.
#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    long double x;
    int n;
    std::cout << "Introduce x y el numero de terminos (al menos 1): ";
    if (!(std::cin >> x >> n) || !std::isfinite(x) || n < 1) {
        std::cerr << "Entrada no valida.\n";
        return 1;
    }
    long double suma = 1.0L, termino = 1.0L;
    int k = 1;
    while (k < n) {
        termino *= x / k; // x^k/k! a partir del termino anterior.
        suma += termino;
        if (!std::isfinite(termino) || !std::isfinite(suma)) {
            std::cerr << "El calculo supera el rango numerico disponible.\n";
            return 1;
        }
        ++k;
    }
    std::cout << std::setprecision(18) << "e^x aproximado = " << suma << '\n';
}
