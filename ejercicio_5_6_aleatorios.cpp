// Ejercicio 5.6: cada instruccion asigna un entero aleatorio a n.
#include <iostream>
#include <random>

int main() {
    std::mt19937 generador(std::random_device{}());
    int n;
    n = std::uniform_int_distribution<int>(1, 2)(generador);       // a)
    std::cout << "a) " << n << '\n';
    n = std::uniform_int_distribution<int>(1, 100)(generador);     // b)
    std::cout << "b) " << n << '\n';
    n = std::uniform_int_distribution<int>(0, 9)(generador);       // c)
    std::cout << "c) " << n << '\n';
    n = std::uniform_int_distribution<int>(1000, 1112)(generador);  // d)
    std::cout << "d) " << n << '\n';
    n = std::uniform_int_distribution<int>(-1, 1)(generador);      // e)
    std::cout << "e) " << n << '\n';
    n = std::uniform_int_distribution<int>(-3, 11)(generador);     // f)
    std::cout << "f) " << n << '\n';
}
