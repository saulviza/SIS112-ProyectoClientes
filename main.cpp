// main.cpp
// Proposito: Punto de entrada del sistema - SOLO contiene llamadas a funciones
//            Toda la logica de negocio reside en las librerias de usuario
// SIS-112 Programacion I - Examen Final Integrador

#include <iostream>
#include <vector>
#include "include/cliente.h"
#include "include/archivos.h"
#include "include/crud.h"
#include "include/ordenacion.h"
#include "include/busqueda.h"
#include "include/intercalacion.h"
#include "include/utilidades.h"
using namespace std;

int main() {
    vector<Cliente> clientes;

    // Cargar datos del archivo binario
    cargarClientes(clientes);

    // Seeding automatico: si no hay datos, cargar registros de prueba
    inicializarDatos(clientes);

    string opcion;
    do {
        mostrarMenu();
        getline(cin, opcion);

        if (opcion == "1") {
            crearCliente(clientes);

        } else if (opcion == "2") {
            listarClientes(clientes);

        } else if (opcion == "3") {
            modificarCliente(clientes);

        } else if (opcion == "4") {
            eliminarCliente(clientes);

        } else if (opcion == "5") {
            menuOrdenar(clientes);
            guardarClientes(clientes);

        } else if (opcion == "6") {
            menuBusqueda(clientes);

        } else if (opcion == "7") {
            menuIntercalar();

        } else if (opcion == "8") {
            clientes.clear();
            inicializarDatos(clientes);

        } else if (opcion == "9") {
            cout << "\nSaliendo del sistema. Hasta luego!" << endl;

        } else {
            cout << "Opcion invalida. Intente nuevamente." << endl;
        }

        if (opcion != "9") pausar();

    } while (opcion != "9");

    return 0;
}
