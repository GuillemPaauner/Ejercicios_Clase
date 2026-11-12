// Ejercicio 4.8: producto de los impares entre 1 y 15, ambos incluidos.
#include <iostream>

int main() {
    long long producto = 1;
    for (int i = 1; i <= 15; i += 2) {
        producto *= i;
    }
    std::cout << "Producto = " << producto << '\n';
}
