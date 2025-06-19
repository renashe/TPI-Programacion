#include <iostream>
#include <cstdlib>

#include "dados.h"

using namespace std;

void comenzarJuego() {
    cout << "2 dados de 12 caras" << endl;
    int dados12[2];
    cargarDados12(dados12, 2);
    mostrarDados(dados12, 2);

    cout << "6 dados de 6 caras" << endl;
    int dados6[6];
    cargarDados6(dados6, 6);
    mostrarDados(dados6, 6);

    system("pause");
}
