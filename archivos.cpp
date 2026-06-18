#include "archivos.h"

string quitarComillas(string texto) {
    if (texto.size() >= 2 && texto.front() == '"' && texto.back() == '"') {
        return texto.substr(1, texto.size() - 2);
    }
    return texto;
}

string conComillas(string texto) {
    return "\"" + texto + "\"";
}

bool leerClienteCSV(ifstream &archivo, Cliente &c) {
    string linea;
    if (!getline(archivo, linea)) return false;
    if (linea.empty()) return false;

    stringstream ss(linea);
    string campo;

    getline(ss, campo, ','); c.id       = quitarComillas(campo);
    getline(ss, campo, ','); c.apellido = quitarComillas(campo);
    getline(ss, campo, ','); c.nombre   = quitarComillas(campo);
    getline(ss, campo, ','); c.ciudad   = quitarComillas(campo);
    getline(ss, campo, ','); c.email    = quitarComillas(campo);
    getline(ss, campo, ','); c.tipo     = quitarComillas(campo);

    return true;
}

void escribirClienteCSV(ofstream &archivo, const Cliente &c) {
    archivo << conComillas(c.id)       << ","
            << conComillas(c.apellido) << ","
            << conComillas(c.nombre)   << ","
            << conComillas(c.ciudad)   << ","
            << conComillas(c.email)    << ","
            << conComillas(c.tipo)     << endl;
}
