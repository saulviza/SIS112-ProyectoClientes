#include <iostream>
#include "busqueda.h"
using namespace std;

int busquedaSecuencial(const vector<Cliente> &clientes, const string &id) {
    for (int i = 0; i < (int)clientes.size(); i++) {
        if (clientes[i].id == id) return i;
    }
    return -1;
}

int busquedaBinaria(const vector<Cliente> &clientes, const string &id) {
    int izq = 0, der = (int)clientes.size() - 1;
    int idNum = stoi(id);
    while (izq <= der) {
        int mid = (izq + der) / 2;
        int midID = stoi(clientes[mid].id);
        if (midID == idNum) return mid;
        else if (midID < idNum) izq = mid + 1;
        else der = mid - 1;
    }
    return -1;
}

void mostrarResultado(const vector<Cliente> &clientes, int pos) {
    if (pos == -1) {
        cout << "Cliente no encontrado." << endl;
        return;
    }
    const Cliente &c = clientes[pos];
    cout << "\nCliente encontrado en posicion [" << pos << "]:" << endl;
    cout << "ID: "       << c.id       << endl;
    cout << "Apellido: " << c.apellido << endl;
    cout << "Nombre: "   << c.nombre   << endl;
    cout << "Ciudad: "   << c.ciudad   << endl;
    cout << "Email: "    << c.email    << endl;
    cout << "Tipo: "     << c.tipo     << endl;
}

void menuBusqueda(const vector<Cliente> &clientes) {
    cout << "\n=== BUSCAR CLIENTE ===" << endl;
    cout << "1. Busqueda secuencial (por ID)" << endl;
    cout << "2. Busqueda binaria (requiere ordenar por ID primero)" << endl;
    cout << "Opcion: ";
    string op; getline(cin, op);

    cout << "Ingrese ID a buscar: ";
    string id; getline(cin, id);

    if (op == "1") {
        int pos = busquedaSecuencial(clientes, id);
        mostrarResultado(clientes, pos);
    } else if (op == "2") {
        int pos = busquedaBinaria(clientes, id);
        mostrarResultado(clientes, pos);
    } else {
        cout << "Opcion invalida." << endl;
    }
}
