#include <iostream>
#include <fstream>
#include "vectores.h"
using namespace std;

void cargarClientes(vector<Cliente> &clientes) {
    clientes.clear();
    ifstream archivo("clientes.csv");
    if (!archivo) {
        cout << "Error al abrir clientes.csv" << endl;
        return;
    }
    Cliente temp;
    while (leerClienteCSV(archivo, temp)) {
        clientes.push_back(temp);
    }
    archivo.close();
}

void guardarClientes(const vector<Cliente> &clientes) {
    ofstream archivo("clientes.csv");
    if (!archivo) {
        cout << "Error al guardar clientes.csv" << endl;
        return;
    }
    for (const auto &c : clientes) {
        escribirClienteCSV(archivo, c);
    }
    archivo.close();
}

void mostrarClientes(const vector<Cliente> &clientes) {
    if (clientes.empty()) {
        cout << "No hay clientes en memoria." << endl;
        return;
    }
    cout << "\n====== LISTA DE CLIENTES ======" << endl;
    for (int i = 0; i < (int)clientes.size(); i++) {
        cout << "ID: "       << clientes[i].id       << endl;
        cout << "Apellido: " << clientes[i].apellido << endl;
        cout << "Nombre: "   << clientes[i].nombre   << endl;
        cout << "Ciudad: "   << clientes[i].ciudad   << endl;
        cout << "Email: "    << clientes[i].email    << endl;
        cout << "Tipo: "     << clientes[i].tipo     << endl;
        cout << "--------------------" << endl;
    }
    cout << "Total: " << clientes.size() << " cliente(s)." << endl;
}
