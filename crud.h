#ifndef CRUD_H
#define CRUD_H

#include "cliente.h"
#include "archivos.h"

void crearCliente();
void listarClientesArchivo();
void modificarCliente();
void eliminarCliente();
bool buscarClientePorID(const string &idBuscado, Cliente &encontrado);

#endif
