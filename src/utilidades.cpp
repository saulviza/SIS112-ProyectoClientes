#include <iostream>
#include <cstdlib>
#include "utilidades.h"
using namespace std;

void mostrarMenu() {
    cout << "\n========================================" << endl;
    cout << "     SISTEMA DE CLIENTES EN C++         " << endl;
    cout << "========================================" << endl;
    cout << "  [CRUD]" << endl;
    cout << "  1. Crear cliente" << endl;
    cout << "  2. Listar clientes" << endl;
    cout << "  3. Modificar cliente" << endl;
    cout << "  4. Eliminar cliente" << endl;
    cout << "  [VECTORES + ORDENACION]" << endl;
    cout << "  5. Ordenar clientes" << endl;
    cout << "  [BUSQUEDA]" << endl;
    cout << "  6. Busqueda secuencial" << endl;
    cout << "  7. Busqueda binaria" << endl;
    cout << "  [INTERCALACION]" << endl;
    cout << "  8. Intercalar archivos" << endl;
    cout << "  [SISTEMA]" << endl;
    cout << "  9. Salir" << endl;
    cout << "========================================" << endl;
    cout << "Opcion: ";
}

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore(1000, '\n');
}
