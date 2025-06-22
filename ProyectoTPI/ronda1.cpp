#include <iostream>
#include <cstdlib>
#include "tiradainicial.h"
#include "tirar.h"
#include "dados.h"
#include "Limpiar.h"

using namespace std;

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
