#ifndef CRUD_H
#define CRUD_H

#include <vector>
#include "cliente.h"
using namespace std;

// Alta: solicita datos al usuario y agrega un nuevo cliente
void crearCliente(vector<Cliente> &clientes);

// Consulta: muestra todos los clientes registrados
void listarClientes(const vector<Cliente> &clientes);

// Modificacion: busca por ID y permite editar los datos
void modificarCliente(vector<Cliente> &clientes);

// Baja: elimina un cliente por ID
void eliminarCliente(vector<Cliente> &clientes);

#endif
