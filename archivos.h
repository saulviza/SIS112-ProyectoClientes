#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <fstream>
#include <sstream>
#include "cliente.h"
using namespace std;

string quitarComillas(string texto);
string conComillas(string texto);
bool leerClienteCSV(ifstream &archivo, Cliente &c);
void escribirClienteCSV(ofstream &archivo, const Cliente &c);

#endif
