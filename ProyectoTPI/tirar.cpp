#include <iostream>
#include <cstdlib>
#include "dados.h"
#include "tiradainicial.h"
#include "Limpiar.h"
#include "rlutil.h"

using namespace std;

int tirar(int pasardados) {
    cout << "2 dados de 12 caras" << endl;
    int dados12[2],suma12 = 0;
    cargarDados12(dados12, 2);
    mostrarDados(dados12, 2);
    for (int i = 0; i <= 1; i++){
        suma12 += dados12[i];
    }

    cout << endl;
    cout << "Numero Objetivo: " << suma12 << endl;
    cout << endl;

    cout << "6 dados de 6 caras" << endl;
    int dados6[6];
    cargarDados6(dados6, 6);
    mostrarDados(dados6, 6);

    cout << endl << "Seleccionar los dados stock para alcanzar el numero objetivo (Selecciona 0 para cerrar la suma): "<< endl;

    int dados6suma = 0;
    bool dados6usados[6] = {false};
    int dados6valor;
    int cont = 0;

    while (true) {
        cin >> dados6valor;
        if (dados6valor == 0) break;

        bool encontrado = false;
        for (int i = 0; i < 6; i++) {
            if (!dados6usados[i] && dados6[i] == dados6valor) {
                dados6usados[i] = true;
                dados6suma += dados6valor;
                encontrado = true;
                cont++;
                break;
            }
        }

        if (!encontrado) {
            cout << "No se encuentro ese valor de dado" << endl;
        } else {
            cout << "Suma actual: " << dados6suma << endl;
        }
    }
    cout << endl << "Suma final seleccionada: " << dados6suma << endl;
    if (dados6suma == suma12) {
        cout << "Alcanzaste el Numero Objetivo" << endl;
    } else if (dados6suma < suma12) {
        cout << "No alcanzaste el número objetivo!!" << endl;
    } else {
        cout <<"Te pasaste!!" << endl;
    }

    limpiarPantalla();
    return cont;
}
