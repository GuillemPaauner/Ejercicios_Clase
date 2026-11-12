// Ejercicio 3.26: descifrado. El cifrado puede empezar por cero.
#include <algorithm>
#include <iostream>
#include <string>

int main() {
    std::string texto;
    std::cout << "Introduce las cuatro cifras del cifrado: ";
    if (!(std::cin >> texto) || texto.size() != 4 ||
        !std::all_of(texto.begin(), texto.end(), [](char c) { return c >= '0' && c <= '9'; })) {
        std::cerr << "Debes introducir exactamente cuatro cifras.\n";
        return 1;
    }
    const int a = (texto[2] - '0' + 3) % 10;
    const int b = (texto[3] - '0' + 3) % 10;
    const int c = (texto[0] - '0' + 3) % 10;
    const int d = (texto[1] - '0' + 3) % 10;
    std::cout << "Original: " << a << b << c << d << '\n';
}
