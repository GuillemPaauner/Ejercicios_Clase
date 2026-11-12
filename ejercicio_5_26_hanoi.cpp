// Ejercicio 5.26: funcion recursiva con los cuatro parametros solicitados.
#include <iostream>

void hanoi(int discos, int origen, int destino, int auxiliar) {
    if (discos == 1) {
        std::cout << origen << " -> " << destino << '\n';
        return;
    }
    hanoi(discos - 1, origen, auxiliar, destino);
    std::cout << origen << " -> " << destino << '\n';
    hanoi(discos - 1, auxiliar, destino, origen);
}

int main() {
    int discos;
    std::cout << "Numero de discos (al menos 1): ";
    if (!(std::cin >> discos) || discos < 1) {
        std::cerr << "Entrada no valida.\n";
        return 1;
    }
    std::cout << "Movimientos de la varilla 1 a la 3:\n";
    hanoi(discos, 1, 3, 2);
}
