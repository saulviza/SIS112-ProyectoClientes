#include <iostream>
#include <fstream>
#include <vector>
#include "crud.h"
using namespace std;

// Genera el siguiente ID automaticamente
string generarID() {
    ifstream archivo("clientes.csv");
    if (!archivo) return "1";
    Cliente c;
    int maxID = 0;
    while (leerClienteCSV(archivo, c)) {
        int id = stoi(c.id);
        if (id > maxID) maxID = id;
    }
    archivo.close();
    return to_string(maxID + 1);
}

void crearCliente() {
    Cliente c;
    c.id = generarID();

    cout << "\n=== CREAR NUEVO CLIENTE ===" << endl;
    cout << "ID asignado: " << c.id << endl;
    cout << "Apellido: "; getline(cin, c.apellido);
    cout << "Nombre: ";   getline(cin, c.nombre);
    cout << "Ciudad: ";   getline(cin, c.ciudad);
    cout << "Email: ";    getline(cin, c.email);
    cout << "Tipo (Afiliado/NoAfiliado): "; getline(cin, c.tipo);

    ofstream archivo("clientes.csv", ios::app);
    if (!archivo) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }
    escribirClienteCSV(archivo, c);
    archivo.close();
    cout << "Cliente creado correctamente." << endl;
}

void listarClientesArchivo() {
    ifstream archivo("clientes.csv");
    if (!archivo) {
        cout << "No se encontro el archivo clientes.csv" << endl;
        return;
    }
    Cliente c;
    int count = 0;
    cout << "\n=== LISTA DE CLIENTES ===" << endl;
    while (leerClienteCSV(archivo, c)) {
        cout << "ID: "       << c.id       << endl;
        cout << "Apellido: " << c.apellido << endl;
        cout << "Nombre: "   << c.nombre   << endl;
        cout << "Ciudad: "   << c.ciudad   << endl;
        cout << "Email: "    << c.email    << endl;
        cout << "Tipo: "     << c.tipo     << endl;
        cout << "--------------------" << endl;
        count++;
    }
    archivo.close();
    if (count == 0) cout << "No hay clientes registrados." << endl;
    else cout << "Total: " << count << " cliente(s)." << endl;
}

bool buscarClientePorID(const string &idBuscado, Cliente &encontrado) {
    ifstream archivo("clientes.csv");
    if (!archivo) return false;
    Cliente c;
    while (leerClienteCSV(archivo, c)) {
        if (c.id == idBuscado) {
            encontrado = c;
            archivo.close();
            return true;
        }
    }
    archivo.close();
    return false;
}

void modificarCliente() {
    cout << "\n=== MODIFICAR CLIENTE ===" << endl;
    string idBuscado;
    cout << "Ingrese ID del cliente a modificar: ";
    getline(cin, idBuscado);

    Cliente encontrado;
    if (!buscarClientePorID(idBuscado, encontrado)) {
        cout << "Cliente con ID " << idBuscado << " no encontrado." << endl;
        return;
    }

    cout << "Cliente encontrado: " << encontrado.nombre << " " << encontrado.apellido << endl;
    cout << "Ingrese nuevos datos (Enter para mantener actual):" << endl;

    string temp;
    cout << "Apellido [" << encontrado.apellido << "]: "; getline(cin, temp);
    if (!temp.empty()) encontrado.apellido = temp;

    cout << "Nombre [" << encontrado.nombre << "]: "; getline(cin, temp);
    if (!temp.empty()) encontrado.nombre = temp;

    cout << "Ciudad [" << encontrado.ciudad << "]: "; getline(cin, temp);
    if (!temp.empty()) encontrado.ciudad = temp;

    cout << "Email [" << encontrado.email << "]: "; getline(cin, temp);
    if (!temp.empty()) encontrado.email = temp;

    cout << "Tipo [" << encontrado.tipo << "]: "; getline(cin, temp);
    if (!temp.empty()) encontrado.tipo = temp;

    // Leer todos, reemplazar el modificado, reescribir
    ifstream archivoIn("clientes.csv");
    vector<Cliente> todos;
    Cliente c;
    while (leerClienteCSV(archivoIn, c)) {
        if (c.id == idBuscado) todos.push_back(encontrado);
        else todos.push_back(c);
    }
    archivoIn.close();

    ofstream archivoOut("clientes.csv");
    for (auto &cl : todos) escribirClienteCSV(archivoOut, cl);
    archivoOut.close();

    cout << "Cliente modificado correctamente." << endl;
}

void eliminarCliente() {
    cout << "\n=== ELIMINAR CLIENTE ===" << endl;
    string idBuscado;
    cout << "Ingrese ID del cliente a eliminar: ";
    getline(cin, idBuscado);

    Cliente encontrado;
    if (!buscarClientePorID(idBuscado, encontrado)) {
        cout << "Cliente con ID " << idBuscado << " no encontrado." << endl;
        return;
    }

    cout << "Eliminar a: " << encontrado.nombre << " " << encontrado.apellido << "? (s/n): ";
    string conf; getline(cin, conf);
    if (conf != "s" && conf != "S") {
        cout << "Operacion cancelada." << endl;
        return;
    }

    ifstream archivoIn("clientes.csv");
    vector<Cliente> todos;
    Cliente c;
    while (leerClienteCSV(archivoIn, c)) {
        if (c.id != idBuscado) todos.push_back(c);
    }
    archivoIn.close();

    ofstream archivoOut("clientes.csv");
    for (auto &cl : todos) escribirClienteCSV(archivoOut, cl);
    archivoOut.close();

    cout << "Cliente eliminado correctamente." << endl;
}
