// utilidades.cpp
// Proposito: Funciones de utilidad general del sistema (menu, pantalla, pausa, reporte)
// Parametros: ninguno / vector<Cliente> por referencia constante para el reporte
// Retorno: void

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "utilidades.h"
using namespace std;

void mostrarMenu() {
    cout << "\n========================================" << endl;
    cout << "     SISTEMA DE GESTION DE CLIENTES     " << endl;
    cout << "========================================" << endl;
    cout << "  [CRUD - Archivos Binarios]" << endl;
    cout << "  1. Crear cliente" << endl;
    cout << "  2. Listar clientes" << endl;
    cout << "  3. Modificar cliente" << endl;
    cout << "  4. Eliminar cliente" << endl;
    cout << "  [ORDENACION]" << endl;
    cout << "  5. Ordenar / Comparar algoritmos" << endl;
    cout << "  [BUSQUEDA]" << endl;
    cout << "  6. Buscar cliente" << endl;
    cout << "  [INTERCALACION]" << endl;
    cout << "  7. Intercalar archivos" << endl;
    cout << "  [SISTEMA]" << endl;
    cout << "  8. Reinicializar datos de prueba" << endl;
    cout << "  9. Generar reporte PDF" << endl;
    cout << "  0. Salir" << endl;
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

void generarReporteHTML(const vector<Cliente> &clientes) {
    ofstream archivo("reporte.html");
    if (!archivo) {
        cout << "Error: no se pudo crear el reporte." << endl;
        return;
    }

    archivo << "<!DOCTYPE html>" << endl;
    archivo << "<html lang='es'>" << endl;
    archivo << "<head>" << endl;
    archivo << "<meta charset='UTF-8'>" << endl;
    archivo << "<title>Reporte Sky Gym</title>" << endl;
    archivo << "<style>" << endl;
    archivo << "body { font-family: Arial, sans-serif; margin: 40px; }" << endl;
    archivo << "h1 { color: #2c3e50; text-align: center; }" << endl;
    archivo << "h3 { color: #555; text-align: center; }" << endl;
    archivo << "table { width: 100%; border-collapse: collapse; margin-top: 20px; }" << endl;
    archivo << "th { background-color: #2c3e50; color: white; padding: 10px; text-align: left; }" << endl;
    archivo << "td { padding: 8px; border-bottom: 1px solid #ddd; }" << endl;
    archivo << "tr:nth-child(even) { background-color: #f2f2f2; }" << endl;
    archivo << ".footer { text-align: center; margin-top: 30px; color: #888; font-size: 12px; }" << endl;
    archivo << "</style>" << endl;
    archivo << "</head>" << endl;
    archivo << "<body>" << endl;
    archivo << "<h1>Sky Gym</h1>" << endl;
    archivo << "<h3>Sistema de Control de Membresias Deportivas</h3>" << endl;
    archivo << "<h3>Reporte de Clientes Registrados</h3>" << endl;
    archivo << "<p>Total de clientes: <strong>" << clientes.size() << "</strong></p>" << endl;
    archivo << "<table>" << endl;
    archivo << "<tr><th>ID</th><th>Apellido</th><th>Nombre</th><th>Ciudad</th><th>Email</th><th>Tipo</th></tr>" << endl;

    for (const auto &c : clientes) {
        archivo << "<tr>";
        archivo << "<td>" << c.id       << "</td>";
        archivo << "<td>" << c.apellido << "</td>";
        archivo << "<td>" << c.nombre   << "</td>";
        archivo << "<td>" << c.ciudad   << "</td>";
        archivo << "<td>" << c.email    << "</td>";
        archivo << "<td>" << c.tipo     << "</td>";
        archivo << "</tr>" << endl;
    }

    archivo << "</table>" << endl;
    archivo << "<div class='footer'>" << endl;
    archivo << "<p>SIS-112 Programacion I — UCB San Pablo La Paz — Gestion 1/2026</p>" << endl;
    archivo << "</div>" << endl;
    archivo << "</body></html>" << endl;

    archivo.close();
    cout << "Reporte generado: reporte.html" << endl;
    cout << "Abra el archivo en su navegador y use Ctrl+P para guardar como PDF." << endl;
}
