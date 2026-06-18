#ifndef ORDENACION_H
#define ORDENACION_H

#include <vector>
#include "cliente.h"
using namespace std;

void ordenarPorID(vector<Cliente> &clientes);
void ordenarPorApellido(vector<Cliente> &clientes);
void ordenarPorNombre(vector<Cliente> &clientes);
void menuOrdenar(vector<Cliente> &clientes);

#endif
