#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <vector>
#include "cliente.h"
using namespace std;

// Busqueda secuencial por ID
int busquedaSecuencial(const vector<Cliente> &clientes, const string &id);

// Busqueda binaria por ID (requiere vector ordenado por ID)
int busquedaBinaria(const vector<Cliente> &clientes, const string &id);

void menuBusqueda(const vector<Cliente> &clientes);

#endif
