// Ejercicio 4.15: imprime las 200000 aproximaciones solicitadas.
#include <iomanip>
#include <iostream>

int main() {
    constexpr int limite = 200000;
    long double pi = 0.0L, signo = 1.0L, primeraAproximacion = 0.0L;
    int primero = 0;
    std::cout << "Accuracy set at: " << limite << "\n\n"
              << std::setw(8) << "term" << std::setw(16) << "pi" << '\n';
    for (int k = 1; k <= limite; ++k) {
        pi += signo * 4.0L / (2.0L * k - 1.0L);
        signo = -signo;
        std::cout << std::setw(8) << k << std::setw(16)
                  << std::fixed << std::setprecision(8) << pi << '\n';
        // "Empieza por" se interpreta por sus cifras, sin redondear.
        if (primero == 0 && pi >= 3.14159L && pi < 3.14160L) {
            primero = k;
            primeraAproximacion = pi;
        }
    }
    std::cout << "\nPrimer numero de terminos que produce el prefijo 3.14159: "
              << primero << "\nAproximacion: " << std::setprecision(15)
              << primeraAproximacion << '\n';
}
