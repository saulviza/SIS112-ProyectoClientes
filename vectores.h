#ifndef VECTORES_H
#define VECTORES_H

#include <vector>
#include "cliente.h"
#include "archivos.h"
using namespace std;

void cargarClientes(vector<Cliente> &clientes);
void guardarClientes(const vector<Cliente> &clientes);
void mostrarClientes(const vector<Cliente> &clientes);

#endif
