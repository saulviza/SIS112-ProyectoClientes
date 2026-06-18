#include <iostream>
#include <fstream>
#include "intercalacion.h"
#include "archivos.h"
#include "cliente.h"
using namespace std;

void intercalarArchivos(const string &arch1, const string &arch2, const string &resultado) {
    ifstream f1(arch1.c_str());
    ifstream f2(arch2.c_str());
    ofstream fOut(resultado.c_str());

    if (!f1) { cout << "No se puede abrir: " << arch1 << endl; return; }
    if (!f2) { cout << "No se puede abrir: " << arch2 << endl; return; }
    if (!fOut){ cout << "No se puede crear: " << resultado << endl; return; }

    Cliente c1, c2;
    bool tiene1 = leerClienteCSV(f1, c1);
    bool tiene2 = leerClienteCSV(f2, c2);

    while (tiene1 && tiene2) {
        if (stoi(c1.id) <= stoi(c2.id)) {
            escribirClienteCSV(fOut, c1);
            tiene1 = leerClienteCSV(f1, c1);
        } else {
            escribirClienteCSV(fOut, c2);
            tiene2 = leerClienteCSV(f2, c2);
        }
    }
    while (tiene1) {
        escribirClienteCSV(fOut, c1);
        tiene1 = leerClienteCSV(f1, c1);
    }
    while (tiene2) {
        escribirClienteCSV(fOut, c2);
        tiene2 = leerClienteCSV(f2, c2);
    }

    f1.close(); f2.close(); fOut.close();
    cout << "Intercalacion completada en: " << resultado << endl;
}

void menuIntercalar() {
    cout << "\n=== INTERCALAR ARCHIVOS ===" << endl;
    cout << "Archivo 1 (ej: clientes1.csv): ";
    string a1; getline(cin, a1);
    cout << "Archivo 2 (ej: clientes2.csv): ";
    string a2; getline(cin, a2);
    cout << "Archivo resultado (ej: resultado.csv): ";
    string res; getline(cin, res);
    intercalarArchivos(a1, a2, res);
}
