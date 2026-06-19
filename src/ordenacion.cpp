// ordenacion.cpp
// Proposito: Algoritmos de ordenacion con metricas de eficiencia
//            Bubble Sort optimizado e Intercalacion (Merge Sort)
// Parametros: vector<Cliente> por referencia, contadores por referencia
// Retorno: void

#include <iostream>
#include <vector>
#include <algorithm>
#include "ordenacion.h"
using namespace std;

void bubbleSortPorID(vector<Cliente> &clientes, long long &comparaciones, long long &intercambios) {
    comparaciones = 0;
    intercambios  = 0;
    int n = clientes.size();
    bool intercambiado;

    for (int i = 0; i < n - 1; i++) {
        intercambiado = false;
        for (int j = 0; j < n - i - 1; j++) {
            comparaciones++;
            if (atoi(clientes[j].id) > atoi(clientes[j+1].id)) {
                swap(clientes[j], clientes[j+1]);
                intercambios++;
                intercambiado = true;
            }
        }
        if (!intercambiado) break;
    }
}

static void merge(vector<Cliente> &clientes, int izq, int mid, int der,
                  long long &comparaciones, long long &intercambios) {
    vector<Cliente> izqV(clientes.begin() + izq, clientes.begin() + mid + 1);
    vector<Cliente> derV(clientes.begin() + mid + 1, clientes.begin() + der + 1);

    int i = 0, j = 0, k = izq;
    while (i < (int)izqV.size() && j < (int)derV.size()) {
        comparaciones++;
        if (atoi(izqV[i].id) <= atoi(derV[j].id)) {
            clientes[k++] = izqV[i++];
        } else {
            clientes[k++] = derV[j++];
            intercambios++;
        }
    }
    while (i < (int)izqV.size()) clientes[k++] = izqV[i++];
    while (j < (int)derV.size()) clientes[k++] = derV[j++];
}

static void mergeSortRecursivo(vector<Cliente> &clientes, int izq, int der,
                                long long &comparaciones, long long &intercambios) {
    if (izq >= der) return;
    int mid = (izq + der) / 2;
    mergeSortRecursivo(clientes, izq, mid, comparaciones, intercambios);
    mergeSortRecursivo(clientes, mid + 1, der, comparaciones, intercambios);
    merge(clientes, izq, mid, der, comparaciones, intercambios);
}

void mergeSortPorID(vector<Cliente> &clientes, long long &comparaciones, long long &intercambios) {
    comparaciones = 0;
    intercambios  = 0;
    if (clientes.empty()) return;
    mergeSortRecursivo(clientes, 0, (int)clientes.size() - 1, comparaciones, intercambios);
}

void ordenarPorID(vector<Cliente> &clientes) {
    long long comp, inter;
    bubbleSortPorID(clientes, comp, inter);
}

void menuOrdenar(vector<Cliente> &clientes) {
    cout << "\n=== MODULO COMPARATIVO DE ORDENACION ===" << endl;
    cout << "1. Bubble Sort (ordenar datos actuales)" << endl;
    cout << "2. Merge Sort / Intercalacion (ordenar datos actuales)" << endl;
    cout << "3. Comparar ambos algoritmos (reporte de eficiencia)" << endl;
    cout << "Opcion: ";
    string op; getline(cin, op);

    if (op == "1") {
        long long comp = 0, inter = 0;
        bubbleSortPorID(clientes, comp, inter);
        cout << "\n--- Bubble Sort completado ---" << endl;
        cout << "Comparaciones: " << comp << endl;
        cout << "Intercambios:  " << inter << endl;

    } else if (op == "2") {
        long long comp = 0, inter = 0;
        mergeSortPorID(clientes, comp, inter);
        cout << "\n--- Merge Sort completado ---" << endl;
        cout << "Comparaciones: " << comp << endl;
        cout << "Movimientos:   " << inter << endl;

    } else if (op == "3") {
        vector<Cliente> copia1 = clientes;
        vector<Cliente> copia2 = clientes;

        long long compBubble = 0, interBubble = 0;
        long long compMerge  = 0, interMerge  = 0;

        bubbleSortPorID(copia1, compBubble, interBubble);
        mergeSortPorID (copia2, compMerge,  interMerge);

        clientes = copia2;

        cout << "\n=======================================" << endl;
        cout << "   REPORTE COMPARATIVO DE ORDENACION   " << endl;
        cout << "=======================================" << endl;
        cout << "Registros ordenados: " << clientes.size() << endl;
        cout << "---------------------------------------" << endl;
        cout << "Metodo          | Comparaciones | Movimientos" << endl;
        cout << "---------------------------------------" << endl;
        cout << "Bubble Sort     | " << compBubble  << "           | " << interBubble << endl;
        cout << "Merge Sort      | " << compMerge   << "           | " << interMerge  << endl;
        cout << "---------------------------------------" << endl;
        if (compBubble <= compMerge)
            cout << "Resultado: Bubble Sort fue mas eficiente en comparaciones." << endl;
        else
            cout << "Resultado: Merge Sort fue mas eficiente en comparaciones." << endl;
        cout << "=======================================" << endl;

    } else {
        cout << "Opcion invalida." << endl;
    }
}