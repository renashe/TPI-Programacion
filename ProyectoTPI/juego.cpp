#include <iostream>
#include <cstdlib>

#include "dados.h"
#include "juego.h"

using namespace std;

void comenzarJuego() {
    ronda1();
    system("pause");
}


void limpiarPantalla(){
    system("pause");
    system("cls");
}

int tiradaInicial(string nombrejugador1,string nombrejugador2) {
        int Jugador1 = 0, Jugador2 = 0, JugadorP = 0;
        while(Jugador1 == Jugador2){
            int dados6[1];

            cout << "Primer dado: " << endl;
            cargarDados6(dados6, 1);
            mostrarDados(dados6, 1);

            Jugador1 = dados6[0];

            system("pause");
            cout << endl;

            cout << "Segundo dado: " << endl;
            cargarDados6(dados6, 1);
            mostrarDados(dados6, 1);

            Jugador2 = dados6[0];

            limpiarPantalla();

            if (Jugador1 == Jugador2){
                cout << "Tirar de vuelta...." << endl;
                limpiarPantalla();
            }

        }

        if (Jugador1 > Jugador2){
            JugadorP = 1;
            cout << "Empieza " << nombrejugador1 << ": [" << Jugador1 << "]" << endl;
            cout << "Sigue " << nombrejugador2 << ": [" << Jugador2 << "]" << endl;
        } else {
            JugadorP = 2;
            cout << "Empieza " << nombrejugador2 << ": [" << Jugador2 << "]" << endl;
            cout << "Sigue " << nombrejugador1 << ": [" << Jugador1 << "]" << endl;
        }

        limpiarPantalla();
        return JugadorP;
}

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

void ronda1(){
        cout << "========================================="  << endl;
        cout << "== El jugador con mayor tirada empieza ==" << endl;
        cout << "=========================================" << endl;
        string nombrejugador1, nombrejugador2;
        limpiarPantalla();

        cout << "Ingrese Nombre: " << endl;
        cin >> nombrejugador1;
        cout << endl;
        cout << "Ingrese Nombre: " << endl;
        cin >> nombrejugador2;
        system("cls");

       int JugadorP = tiradaInicial(nombrejugador1, nombrejugador2);

    if (JugadorP == 1){
        cout << nombrejugador1 <<": " << endl;
        cout << endl;
        int pasardados = tirar(0);
        cout << nombrejugador2 << ": " << endl;
        cout << endl;
        tirar(pasardados);
    } else {
        cout << nombrejugador2 << ": " << endl;
        cout << endl;
        int pasardados = tirar(0);
        cout << nombrejugador1 << ": " << endl;
        cout << endl;
        tirar(pasardados);
    }

    }
