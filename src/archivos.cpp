// archivos.cpp
// Proposito: Manejo de persistencia con archivos binarios (.dat)
//            e inicializacion automatica de datos de prueba (seeding)
// Parametros: vector<Cliente> por referencia para carga y guardado
// Retorno: void / string para generarID

#include <iostream>
#include <fstream>
#include <cstring>
#include "archivos.h"
using namespace std;

void cargarClientes(vector<Cliente> &clientes) {
    clientes.clear();
    ifstream archivo(ARCHIVO_DATOS, ios::binary);
    if (!archivo) return;
    Cliente temp;
    while (archivo.read(reinterpret_cast<char*>(&temp), sizeof(Cliente))) {
        clientes.push_back(temp);
    }
    archivo.close();
}

void guardarClientes(const vector<Cliente> &clientes) {
    ofstream archivo(ARCHIVO_DATOS, ios::binary | ios::trunc);
    if (!archivo) {
        cout << "Error: no se pudo guardar el archivo de datos." << endl;
        return;
    }
    for (const auto &c : clientes) {
        archivo.write(reinterpret_cast<const char*>(&c), sizeof(Cliente));
    }
    archivo.close();
}

string generarID(const vector<Cliente> &clientes) {
    int maxID = 0;
    for (const auto &c : clientes) {
        int id = atoi(c.id);
        if (id > maxID) maxID = id;
    }
    return to_string(maxID + 1);
}

void inicializarDatos(vector<Cliente> &clientes) {
    if (!clientes.empty()) return;

    cout << "\nPrimera ejecucion detectada. Cargando datos de prueba..." << endl;

    const char* datos[][6] = {
        {"1",  "Mamani",   "Juan Carlos",  "La Paz",     "jmamani@gmail.com",   "Afiliado"},
        {"2",  "Quispe",   "Maria Elena",  "Cochabamba", "mquispe@hotmail.com", "Afiliado"},
        {"3",  "Flores",   "Pedro Luis",   "Santa Cruz", "pflores@outlook.com", "NoAfiliado"},
        {"4",  "Condori",  "Ana Patricia", "Oruro",      "acondori@gmail.com",  "Afiliado"},
        {"5",  "Huanca",   "Carlos Raul",  "Potosi",     "chuanca@yahoo.com",   "NoAfiliado"},
        {"6",  "Choque",   "Rosa Isabel",  "Sucre",      "rchoque@gmail.com",   "Afiliado"},
        {"7",  "Vargas",   "Luis Alberto", "Tarija",     "lvargas@hotmail.com", "NoAfiliado"},
        {"8",  "Apaza",    "Carmen Sofia", "Beni",       "capaza@outlook.com",  "Afiliado"},
        {"9",  "Mendoza",  "Jorge Ivan",   "Pando",      "jmendoza@gmail.com",  "NoAfiliado"},
        {"10", "Ticona",   "Silvia Ruth",  "La Paz",     "sticona@gmail.com",   "Afiliado"}
    };

    for (int i = 0; i < 10; i++) {
        Cliente c;
        strncpy(c.id,       datos[i][0], sizeof(c.id)-1);       c.id[sizeof(c.id)-1]             = '\0';
        strncpy(c.apellido, datos[i][1], sizeof(c.apellido)-1); c.apellido[sizeof(c.apellido)-1] = '\0';
        strncpy(c.nombre,   datos[i][2], sizeof(c.nombre)-1);   c.nombre[sizeof(c.nombre)-1]     = '\0';
        strncpy(c.ciudad,   datos[i][3], sizeof(c.ciudad)-1);   c.ciudad[sizeof(c.ciudad)-1]     = '\0';
        strncpy(c.email,    datos[i][4], sizeof(c.email)-1);    c.email[sizeof(c.email)-1]       = '\0';
        strncpy(c.tipo,     datos[i][5], sizeof(c.tipo)-1);     c.tipo[sizeof(c.tipo)-1]         = '\0';
        clientes.push_back(c);
    }

    guardarClientes(clientes);
    cout << "10 registros de prueba cargados correctamente." << endl;
}

void mostrarClientes(const vector<Cliente> &clientes) {
    if (clientes.empty()) {
        cout << "No hay clientes registrados." << endl;
        return;
    }
    cout << "\n====== LISTA DE CLIENTES ======" << endl;
    for (int i = 0; i < (int)clientes.size(); i++) {
        cout << "ID: "       << clientes[i].id       << endl;
        cout << "Apellido: " << clientes[i].apellido << endl;
        cout << "Nombre: "   << clientes[i].nombre   << endl;
        cout << "Ciudad: "   << clientes[i].ciudad   << endl;
        cout << "Email: "    << clientes[i].email    << endl;
        cout << "Tipo: "     << clientes[i].tipo     << endl;
        cout << "--------------------" << endl;
    }
    cout << "Total: " << clientes.size() << " cliente(s)." << endl;
}
