// Ejercicio 3.25 b: N terminos incluyen el termino inicial 1 (k = 0).
#include <iomanip>
#include <iostream>

int main() {
    int n;
    std::cout << "Numero de terminos (al menos 1): ";
    if (!(std::cin >> n) || n < 1) {
        std::cerr << "Entrada no valida.\n";
        return 1;
    }
    long double suma = 1.0L, termino = 1.0L;
    int k = 1;
    while (k < n) {
        termino /= k; // De 1/(k-1)! a 1/k!.
        suma += termino;
        ++k;
    }
    std::cout << std::setprecision(18) << "e aproximado = " << suma << '\n';
}
