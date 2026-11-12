// Ejercicio 3.25 a: factorial exacto con while, sin bibliotecas externas.
// Cada elemento del vector guarda una cifra decimal, de menor a mayor peso.
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cout << "Introduce un entero no negativo: ";
    if (!(std::cin >> n) || n < 0) {
        std::cerr << "Entrada no valida.\n";
        return 1;
    }
    std::vector<int> cifras(1, 1);
    int factor = n;
    while (factor > 1) {
        unsigned long long acarreo = 0;
        std::size_t j = 0;
        while (j < cifras.size()) {
            const unsigned long long producto =
                static_cast<unsigned long long>(cifras[j]) * factor + acarreo;
            cifras[j] = static_cast<int>(producto % 10);
            acarreo = producto / 10;
            ++j;
        }
        while (acarreo > 0) {
            cifras.push_back(static_cast<int>(acarreo % 10));
            acarreo /= 10;
        }
        --factor;
    }
    std::cout << n << "! = ";
    std::size_t j = cifras.size();
    while (j > 0) {
        --j;
        std::cout << cifras[j];
    }
    std::cout << '\n';
}
