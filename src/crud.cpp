// crud.cpp
// Proposito: Operaciones CRUD sobre el vector de clientes con persistencia binaria
// Parametros: vector<Cliente> por referencia en todas las funciones
// Retorno: void

#include <iostream>
#include <cstring>
#include "crud.h"
#include "archivos.h"
using namespace std;

void crearCliente(vector<Cliente> &clientes) {
    Cliente c;
    string id = generarID(clientes);
    strncpy(c.id, id.c_str(), sizeof(c.id) - 1);
    c.id[sizeof(c.id) - 1] = '\0';

    cout << "\n=== CREAR NUEVO CLIENTE ===" << endl;
    cout << "ID asignado: " << c.id << endl;

    string temp;
    cout << "Apellido: ";   getline(cin, temp);
    strncpy(c.apellido, temp.c_str(), sizeof(c.apellido)-1); c.apellido[sizeof(c.apellido)-1] = '\0';

    cout << "Nombre: ";     getline(cin, temp);
    strncpy(c.nombre, temp.c_str(), sizeof(c.nombre)-1); c.nombre[sizeof(c.nombre)-1] = '\0';

    cout << "Ciudad: ";     getline(cin, temp);
    strncpy(c.ciudad, temp.c_str(), sizeof(c.ciudad)-1); c.ciudad[sizeof(c.ciudad)-1] = '\0';

    cout << "Email: ";      getline(cin, temp);
    strncpy(c.email, temp.c_str(), sizeof(c.email)-1); c.email[sizeof(c.email)-1] = '\0';

    cout << "Tipo (Afiliado/NoAfiliado): "; getline(cin, temp);
    strncpy(c.tipo, temp.c_str(), sizeof(c.tipo)-1); c.tipo[sizeof(c.tipo)-1] = '\0';

    clientes.push_back(c);
    guardarClientes(clientes);
    cout << "Cliente creado correctamente." << endl;
}

void listarClientes(const vector<Cliente> &clientes) {
    mostrarClientes(clientes);
}

void modificarCliente(vector<Cliente> &clientes) {
    cout << "\n=== MODIFICAR CLIENTE ===" << endl;
    cout << "Ingrese ID del cliente a modificar: ";
    string idBuscado; getline(cin, idBuscado);

    int pos = -1;
    for (int i = 0; i < (int)clientes.size(); i++) {
        if (string(clientes[i].id) == idBuscado) { pos = i; break; }
    }

    if (pos == -1) {
        cout << "Cliente con ID " << idBuscado << " no encontrado." << endl;
        return;
    }

    cout << "Cliente encontrado: " << clientes[pos].nombre << " " << clientes[pos].apellido << endl;
    cout << "Ingrese nuevos datos (Enter para mantener el actual):" << endl;

    string temp;
    cout << "Apellido [" << clientes[pos].apellido << "]: "; getline(cin, temp);
    if (!temp.empty()) { strncpy(clientes[pos].apellido, temp.c_str(), sizeof(clientes[pos].apellido)-1); clientes[pos].apellido[sizeof(clientes[pos].apellido)-1]='\0'; }

    cout << "Nombre [" << clientes[pos].nombre << "]: "; getline(cin, temp);
    if (!temp.empty()) { strncpy(clientes[pos].nombre, temp.c_str(), sizeof(clientes[pos].nombre)-1); clientes[pos].nombre[sizeof(clientes[pos].nombre)-1]='\0'; }

    cout << "Ciudad [" << clientes[pos].ciudad << "]: "; getline(cin, temp);
    if (!temp.empty()) { strncpy(clientes[pos].ciudad, temp.c_str(), sizeof(clientes[pos].ciudad)-1); clientes[pos].ciudad[sizeof(clientes[pos].ciudad)-1]='\0'; }

    cout << "Email [" << clientes[pos].email << "]: "; getline(cin, temp);
    if (!temp.empty()) { strncpy(clientes[pos].email, temp.c_str(), sizeof(clientes[pos].email)-1); clientes[pos].email[sizeof(clientes[pos].email)-1]='\0'; }

    cout << "Tipo [" << clientes[pos].tipo << "]: "; getline(cin, temp);
    if (!temp.empty()) { strncpy(clientes[pos].tipo, temp.c_str(), sizeof(clientes[pos].tipo)-1); clientes[pos].tipo[sizeof(clientes[pos].tipo)-1]='\0'; }

    guardarClientes(clientes);
    cout << "Cliente modificado correctamente." << endl;
}

void eliminarCliente(vector<Cliente> &clientes) {
    cout << "\n=== ELIMINAR CLIENTE ===" << endl;
    cout << "Ingrese ID del cliente a eliminar: ";
    string idBuscado; getline(cin, idBuscado);

    int pos = -1;
    for (int i = 0; i < (int)clientes.size(); i++) {
        if (string(clientes[i].id) == idBuscado) { pos = i; break; }
    }

    if (pos == -1) {
        cout << "Cliente con ID " << idBuscado << " no encontrado." << endl;
        return;
    }

    cout << "Eliminar a: " << clientes[pos].nombre << " " << clientes[pos].apellido << "? (s/n): ";
    string conf; getline(cin, conf);
    if (conf != "s" && conf != "S") {
        cout << "Operacion cancelada." << endl;
        return;
    }

    clientes.erase(clientes.begin() + pos);
    guardarClientes(clientes);
    cout << "Cliente eliminado correctamente." << endl;
}
