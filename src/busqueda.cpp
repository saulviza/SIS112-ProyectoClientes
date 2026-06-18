// busqueda.cpp
// Proposito: Algoritmos de busqueda con conteo de iteraciones
//            Secuencial, Binaria iterativa y Binaria recursiva
// Parametros: vector<Cliente> por referencia constante, contadores por referencia
// Retorno: int (indice encontrado o -1)

#include <iostream>
#include "busqueda.h"
#include "ordenacion.h"
using namespace std;

int busquedaSecuencial(const vector<Cliente> &clientes, const string &id, int &iteraciones) {
    iteraciones = 0;
    for (int i = 0; i < (int)clientes.size(); i++) {
        iteraciones++;
        if (string(clientes[i].id) == id) return i;
    }
    return -1;
}

int busquedaBinariaIterativa(const vector<Cliente> &clientes, const string &id, int &iteraciones) {
    iteraciones = 0;
    int izq = 0, der = (int)clientes.size() - 1;
    int idNum = atoi(id.c_str());

    while (izq <= der) {
        iteraciones++;
        int mid = (izq + der) / 2;
        int midID = atoi(clientes[mid].id);
        if (midID == idNum) return mid;
        else if (midID < idNum) izq = mid + 1;
        else der = mid - 1;
    }
    return -1;
}

int busquedaBinariaRecursiva(const vector<Cliente> &clientes, const string &id,
                              int izq, int der, int &llamadas) {
    llamadas++;
    if (izq > der) return -1;

    int mid = (izq + der) / 2;
    int midID = atoi(clientes[mid].id);
    int idNum = atoi(id.c_str());

    if (midID == idNum) return mid;
    if (idNum < midID)
        return busquedaBinariaRecursiva(clientes, id, izq, mid - 1, llamadas);
    else
        return busquedaBinariaRecursiva(clientes, id, mid + 1, der, llamadas);
}

void mostrarResultadoBusqueda(const vector<Cliente> &clientes, int pos) {
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

void menuBusqueda(vector<Cliente> &clientes) {
    cout << "\n=== BUSCAR CLIENTE ===" << endl;
    cout << "1. Busqueda secuencial (por ID)" << endl;
    cout << "2. Busqueda binaria iterativa (requiere orden por ID)" << endl;
    cout << "3. Busqueda binaria recursiva (requiere orden por ID)" << endl;
    cout << "Opcion: ";
    string op; getline(cin, op);

    cout << "Ingrese ID a buscar: ";
    string id; getline(cin, id);

    if (op == "1") {
        int iteraciones = 0;
        int pos = busquedaSecuencial(clientes, id, iteraciones);
        mostrarResultadoBusqueda(clientes, pos);
        cout << "Iteraciones realizadas: " << iteraciones << endl;

    } else if (op == "2") {
        ordenarPorID(clientes);
        int iteraciones = 0;
        int pos = busquedaBinariaIterativa(clientes, id, iteraciones);
        mostrarResultadoBusqueda(clientes, pos);
        cout << "Iteraciones realizadas: " << iteraciones << endl;

    } else if (op == "3") {
        ordenarPorID(clientes);
        int llamadas = 0;
        int pos = busquedaBinariaRecursiva(clientes, id, 0, (int)clientes.size() - 1, llamadas);
        mostrarResultadoBusqueda(clientes, pos);
        cout << "Llamadas recursivas realizadas: " << llamadas << endl;

    } else {
        cout << "Opcion invalida." << endl;
    }
}
