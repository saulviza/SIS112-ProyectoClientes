#include <iostream>
#include <vector>
#include "cliente.h"
#include "utilidades.h"
#include "crud.h"
#include "vectores.h"
#include "ordenacion.h"
#include "busqueda.h"
#include "intercalacion.h"
using namespace std;

int main() {
    vector<Cliente> clientes;
    string opcion;

    // Cargar clientes al inicio
    cargarClientes(clientes);

    do {
        mostrarMenu();
        getline(cin, opcion);

        if (opcion == "1") {
            // Crear cliente
            crearCliente();
            cargarClientes(clientes); // Recargar vector

        } else if (opcion == "2") {
            // Listar clientes (desde vector)
            cargarClientes(clientes);
            mostrarClientes(clientes);

        } else if (opcion == "3") {
            // Modificar cliente
            modificarCliente();
            cargarClientes(clientes);

        } else if (opcion == "4") {
            // Eliminar cliente
            eliminarCliente();
            cargarClientes(clientes);

        } else if (opcion == "5") {
            // Ordenar
            cargarClientes(clientes);
            menuOrdenar(clientes);
            guardarClientes(clientes);
            cout << "Vector guardado en archivo." << endl;

        } else if (opcion == "6") {
            // Busqueda secuencial
            cargarClientes(clientes);
            cout << "\n=== BUSQUEDA SECUENCIAL ===" << endl;
            cout << "Ingrese ID a buscar: ";
            string id; getline(cin, id);
            int pos = busquedaSecuencial(clientes, id);
            if (pos == -1) cout << "Cliente no encontrado." << endl;
            else {
                cout << "Encontrado en posicion [" << pos << "]:" << endl;
                cout << "ID: "       << clientes[pos].id       << endl;
                cout << "Apellido: " << clientes[pos].apellido << endl;
                cout << "Nombre: "   << clientes[pos].nombre   << endl;
                cout << "Ciudad: "   << clientes[pos].ciudad   << endl;
                cout << "Email: "    << clientes[pos].email    << endl;
                cout << "Tipo: "     << clientes[pos].tipo     << endl;
            }

        } else if (opcion == "7") {
            // Busqueda binaria (requiere orden por ID)
            cargarClientes(clientes);
            ordenarPorID(clientes);
            cout << "\n=== BUSQUEDA BINARIA (ordenado por ID) ===" << endl;
            cout << "Ingrese ID a buscar: ";
            string id; getline(cin, id);
            int pos = busquedaBinaria(clientes, id);
            if (pos == -1) cout << "Cliente no encontrado." << endl;
            else {
                cout << "Encontrado:" << endl;
                cout << "ID: "       << clientes[pos].id       << endl;
                cout << "Apellido: " << clientes[pos].apellido << endl;
                cout << "Nombre: "   << clientes[pos].nombre   << endl;
                cout << "Ciudad: "   << clientes[pos].ciudad   << endl;
                cout << "Email: "    << clientes[pos].email    << endl;
                cout << "Tipo: "     << clientes[pos].tipo     << endl;
            }

        } else if (opcion == "8") {
            // Intercalar archivos
            menuIntercalar();

        } else if (opcion == "9") {
            cout << "\nSaliendo del sistema. Hasta luego!" << endl;

        } else {
            cout << "Opcion invalida. Intente nuevamente." << endl;
        }

        if (opcion != "9") pausar();

    } while (opcion != "9");

    return 0;
}
