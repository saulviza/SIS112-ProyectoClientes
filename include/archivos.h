#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <vector>
#include <string>
#include "cliente.h"
using namespace std;

// Ruta del archivo binario de datos
#define ARCHIVO_DATOS "data/clientes.dat"

// Carga todos los clientes del archivo binario al vector
void cargarClientes(vector<Cliente> &clientes);

// Guarda todos los clientes del vector al archivo binario
void guardarClientes(const vector<Cliente> &clientes);

// Genera el siguiente ID disponible
string generarID(const vector<Cliente> &clientes);

// Inicializa el archivo con datos de prueba si esta vacio (seeding)
void inicializarDatos(vector<Cliente> &clientes);

// Muestra la lista de clientes en consola
void mostrarClientes(const vector<Cliente> &clientes);

#endif