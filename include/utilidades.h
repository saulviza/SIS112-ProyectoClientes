#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <vector>
#include "cliente.h"
using namespace std;

// Muestra el menu principal del sistema
void mostrarMenu();

// Limpia la pantalla (compatible Windows/Linux)
void limpiarPantalla();

// Pausa la ejecucion hasta que el usuario presione Enter
void pausar();

// Genera reporte HTML exportable a PDF
void generarReporteHTML(const vector<Cliente> &clientes);

#endif
