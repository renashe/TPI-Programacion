#include <iostream>
#include <ctime>
#include "menu.h"
#include "juego.h"
#include "dados.h"

using namespace std;

int main() {
    srand(time(0));
    int menu;

    while (true) {
        menu = menuJuego();
        switch(menu) {
            case 1:
                comenzarJuego();
                break;
            case 2:
                cout << "Cargando estadisticas..." << endl;
                system("pause");
                break;
            case 0:
                cout << "Cerrando juego..." << endl;
                system("pause");
                return 0;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    }

    return 0;
}
