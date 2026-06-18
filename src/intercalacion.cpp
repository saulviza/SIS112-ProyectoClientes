// intercalacion.cpp
// Proposito: Intercalacion de dos archivos binarios .dat ordenados por ID
// Parametros: rutas de archivos por referencia constante
// Retorno: int con total de registros escritos

#include <iostream>
#include <fstream>
#include "intercalacion.h"
#include "cliente.h"
using namespace std;

static bool leerClienteBin(ifstream &archivo, Cliente &c) {
    return (bool)archivo.read(reinterpret_cast<char*>(&c), sizeof(Cliente));
}

static void escribirClienteBin(ofstream &archivo, const Cliente &c) {
    archivo.write(reinterpret_cast<const char*>(&c), sizeof(Cliente));
}

int intercalarArchivos(const string &arch1, const string &arch2, const string &resultado) {
    ifstream f1(arch1.c_str(), ios::binary);
    ifstream f2(arch2.c_str(), ios::binary);
    ofstream fOut(resultado.c_str(), ios::binary | ios::trunc);

    if (!f1)   { cout << "No se puede abrir: " << arch1    << endl; return 0; }
    if (!f2)   { cout << "No se puede abrir: " << arch2    << endl; return 0; }
    if (!fOut) { cout << "No se puede crear: " << resultado << endl; return 0; }

    Cliente c1, c2;
    bool tiene1 = leerClienteBin(f1, c1);
    bool tiene2 = leerClienteBin(f2, c2);
    int total = 0;

    while (tiene1 && tiene2) {
        if (atoi(c1.id) <= atoi(c2.id)) {
            escribirClienteBin(fOut, c1);
            tiene1 = leerClienteBin(f1, c1);
        } else {
            escribirClienteBin(fOut, c2);
            tiene2 = leerClienteBin(f2, c2);
        }
        total++;
    }
    while (tiene1) {
        escribirClienteBin(fOut, c1);
        tiene1 = leerClienteBin(f1, c1);
        total++;
    }
    while (tiene2) {
        escribirClienteBin(fOut, c2);
        tiene2 = leerClienteBin(f2, c2);
        total++;
    }

    f1.close(); f2.close(); fOut.close();
    return total;
}

void menuIntercalar() {
    cout << "\n=== INTERCALAR ARCHIVOS ===" << endl;
    cout << "Ambos archivos deben estar ordenados por ID." << endl;
    cout << "Archivo 1 (ej: data/clientes1.dat): ";
    string a1; getline(cin, a1);
    cout << "Archivo 2 (ej: data/clientes2.dat): ";
    string a2; getline(cin, a2);
    cout << "Archivo resultado (ej: data/resultado.dat): ";
    string res; getline(cin, res);

    int total = intercalarArchivos(a1, a2, res);
    if (total > 0)
        cout << "Intercalacion completada. Registros escritos: " << total << " en " << res << endl;
}
