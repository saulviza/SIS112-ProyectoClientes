#ifndef CLIENTE_H
#define CLIENTE_H

// Estructura principal del dominio de datos
// Representa un cliente del sistema
struct Cliente {
    char id[10];
    char apellido[50];
    char nombre[50];
    char ciudad[50];
    char email[80];
    char tipo[20];   // "Afiliado" o "NoAfiliado"
};

#endif