// Ejercicio 5.21: flip no recibe argumentos; devuelve 0 (cruz) o 1 (cara).
#include <iostream>
#include <random>

int flip() {
    static std::mt19937 generador(std::random_device{}());
    static std::uniform_int_distribution<int> distribucion(0, 1);
    return distribucion(generador);
}

int main() {
    int caras = 0, cruces = 0;
    for (int i = 1; i <= 100; ++i) {
        const int resultado = flip();
        std::cout << i << ": " << (resultado == 1 ? "Heads" : "Tails") << '\n';
        if (resultado == 1) {
            ++caras;
        } else {
            ++cruces;
        }
    }
    std::cout << "Heads (caras): " << caras << "\nTails (cruces): " << cruces
              << "\nTotal: " << caras + cruces << '\n';
}
