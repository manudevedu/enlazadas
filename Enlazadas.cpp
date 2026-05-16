#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

int main() {
    Nodo* inicio = nullptr;
    Nodo* actual = nullptr;
    char respuesta;

    do {
        cout << "¿Desea ingresar un nuevo valor? (S/N): ";
        cin >> respuesta;

        if (respuesta == 'S' || respuesta == 's') {
            Nodo* nuevoNodo = new Nodo();
            cout << "Ingrese el valor entero: ";
            cin >> nuevoNodo->dato;
            nuevoNodo->siguiente = nullptr;

            if (inicio == nullptr) {
                inicio = nuevoNodo;
                actual = inicio;
            }
            else {
                actual->siguiente = nuevoNodo;
                actual = nuevoNodo;
            }
        }
    } while (respuesta == 'S' || respuesta == 's');

    cout << "\nContenido de la lista:" << endl;
    actual = inicio;
    while (actual != nullptr) {
        cout << "[" << actual->dato << " | * ] -> ";
        actual = actual->siguiente;
    }
    cout << "NULL" << endl;

    while (inicio != nullptr) {
        actual = inicio;
        inicio = inicio->siguiente;
        delete actual;
    }

    return 0;
}