// Ejercicio 3.26: cifrado. Se conservan los ceros iniciales en la salida.
#include <iomanip>
#include <iostream>

int main() {
    int n;
    std::cout << "Introduce un entero de cuatro cifras (1000 a 9999): ";
    if (!(std::cin >> n) || n < 1000 || n > 9999) {
        std::cerr << "Entrada no valida.\n";
        return 1;
    }
    const int a = (n / 1000 + 7) % 10;
    const int b = (n / 100 % 10 + 7) % 10;
    const int c = (n / 10 % 10 + 7) % 10;
    const int d = (n % 10 + 7) % 10;
    const int cifrado = 1000 * c + 100 * d + 10 * a + b;
    std::cout << "Cifrado: " << std::setfill('0') << std::setw(4) << cifrado << '\n';
}
