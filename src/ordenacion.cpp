#include <iostream>
#include <algorithm>
#include "ordenacion.h"
using namespace std;

void ordenarPorID(vector<Cliente> &clientes) {
    // Bubble sort optimizado por ID (numerico)
    int n = clientes.size();
    bool intercambiado;
    for (int i = 0; i < n - 1; i++) {
        intercambiado = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (stoi(clientes[j].id) > stoi(clientes[j+1].id)) {
                swap(clientes[j], clientes[j+1]);
                intercambiado = true;
            }
        }
        if (!intercambiado) break; // Ya esta ordenado, salir anticipadamente
    }
    cout << "Clientes ordenados por ID." << endl;
}

void ordenarPorApellido(vector<Cliente> &clientes) {
    // Bubble sort optimizado por apellido
    int n = clientes.size();
    bool intercambiado;
    for (int i = 0; i < n - 1; i++) {
        intercambiado = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (clientes[j].apellido > clientes[j+1].apellido) {
                swap(clientes[j], clientes[j+1]);
                intercambiado = true;
            }
        }
        if (!intercambiado) break; // Ya esta ordenado, salir anticipadamente
    }
    cout << "Clientes ordenados por apellido." << endl;
}

void ordenarPorNombre(vector<Cliente> &clientes) {
    // Bubble sort optimizado por nombre
    int n = clientes.size();
    bool intercambiado;
    for (int i = 0; i < n - 1; i++) {
        intercambiado = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (clientes[j].nombre > clientes[j+1].nombre) {
                swap(clientes[j], clientes[j+1]);
                intercambiado = true;
            }
        }
        if (!intercambiado) break; // Ya esta ordenado, salir anticipadamente
    }
    cout << "Clientes ordenados por nombre." << endl;
}

void menuOrdenar(vector<Cliente> &clientes) {
    cout << "\n=== ORDENAR CLIENTES ===" << endl;
    cout << "1. Por ID" << endl;
    cout << "2. Por Apellido" << endl;
    cout << "3. Por Nombre" << endl;
    cout << "Opcion: ";
    string op; getline(cin, op);
    if (op == "1") ordenarPorID(clientes);
    else if (op == "2") ordenarPorApellido(clientes);
    else if (op == "3") ordenarPorNombre(clientes);
    else cout << "Opcion invalida." << endl;
}
