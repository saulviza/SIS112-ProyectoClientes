#ifndef ORDENACION_H
#define ORDENACION_H

#include <vector>
#include "cliente.h"
using namespace std;

// Resultado de una ordenacion con metricas de eficiencia
struct ResultadoOrden {
    long long comparaciones;
    long long intercambios;
    string metodo;
};

// Bubble Sort optimizado - retorna metricas por referencia
void bubbleSortPorID(vector<Cliente> &clientes, long long &comparaciones, long long &intercambios);

// Intercalacion/Merge Sort - retorna metricas por referencia
void mergeSortPorID(vector<Cliente> &clientes, long long &comparaciones, long long &intercambios);

// Ordena por ID (usa bubble sort, para uso interno)
void ordenarPorID(vector<Cliente> &clientes);

// Menu comparativo: ejecuta ambos algoritmos y muestra reporte de eficiencia
void menuOrdenar(vector<Cliente> &clientes);

#endif
