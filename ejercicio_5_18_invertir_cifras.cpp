// Ejercicio 5.18: invierte cifras y conserva el signo de los negativos.
#include <iostream>
#include <limits>
#include <stdexcept>

long long invertirCifras(long long numero) {
    long long invertido = 0;
    while (numero != 0) {
        const int cifra = static_cast<int>(numero % 10);
        // Comprobacion previa a la multiplicacion para no desbordar long long.
        constexpr long long maximo = std::numeric_limits<long long>::max();
        constexpr long long minimo = std::numeric_limits<long long>::min();
        if (invertido > maximo / 10 || (invertido == maximo / 10 && cifra > maximo % 10) ||
            invertido < minimo / 10 || (invertido == minimo / 10 && cifra < minimo % 10)) {
            throw std::overflow_error("El numero invertido no cabe en long long.");
        }
        invertido = invertido * 10 + cifra;
        numero /= 10;
    }
    return invertido;
}

int main() {
    long long numero;
    std::cout << "Introduce un entero: ";
    if (!(std::cin >> numero)) {
        std::cerr << "Entrada no valida.\n";
        return 1;
    }
    try {
        const long long resultado = invertirCifras(numero);
        std::cout << "Invertido: " << resultado << '\n';
    } catch (const std::overflow_error& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
