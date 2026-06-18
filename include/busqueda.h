#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <vector>
#include "cliente.h"
using namespace std;

// Busqueda secuencial por ID
// Retorna: indice encontrado (-1 si no existe) e iteraciones realizadas
int busquedaSecuencial(const vector<Cliente> &clientes, const string &id, int &iteraciones);

// Busqueda binaria iterativa por ID (requiere vector ordenado)
// Retorna: indice encontrado (-1 si no existe) e iteraciones realizadas
int busquedaBinariaIterativa(const vector<Cliente> &clientes, const string &id, int &iteraciones);

// Busqueda binaria RECURSIVA por ID (requiere vector ordenado)
// Retorna: indice encontrado (-1 si no existe) y acumula llamadas en el parametro
int busquedaBinariaRecursiva(const vector<Cliente> &clientes, const string &id,
                              int izq, int der, int &llamadas);

// Muestra los datos de un cliente encontrado
void mostrarResultadoBusqueda(const vector<Cliente> &clientes, int pos);

// Menu de busqueda con opciones secuencial, binaria iterativa y recursiva
void menuBusqueda(vector<Cliente> &clientes);

#endif

