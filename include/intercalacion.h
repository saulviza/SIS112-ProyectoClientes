#ifndef INTERCALACION_H
#define INTERCALACION_H

#include <string>
using namespace std;

// Intercala dos archivos binarios .dat ordenados por ID en un archivo resultado
// Retorna el total de registros escritos
int intercalarArchivos(const string &arch1, const string &arch2, const string &resultado);

// Menu de intercalacion de archivos
void menuIntercalar();

#endif
