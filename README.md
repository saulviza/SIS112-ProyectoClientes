# Sky Gym — Sistema de Control de Membresías Deportivas

**Universidad Católica Boliviana "San Pablo"**  
Unidad Académica Regional La Paz — Facultad de Ingeniería  
Departamento de Ingeniería de Sistemas  

**Asignatura:** Programación I — SIS-112  
**Gestión:** 1/2026  

---

## Integrantes

| Nombre completo         |
|-------------------------|
| Saul Josue Viza Choque  |

---

## Descripción del Dominio

Sky Gym es un sistema de consola para gestionar las membresías de clientes de un gimnasio deportivo. Permite registrar, consultar, modificar y eliminar clientes, así como ordenarlos y buscarlos de forma eficiente.

### Struct principal: `Cliente`

```cpp
struct Cliente {
    char id[10];        // Identificador único numérico
    char apellido[50];  // Apellido del cliente
    char nombre[50];    // Nombre del cliente
    char ciudad[50];    // Ciudad de residencia
    char email[80];     // Correo electrónico
    char tipo[20];      // "Afiliado" o "NoAfiliado"
};
```

Los campos usan arreglos de caracteres de tamaño fijo (`char[]`) para permitir la persistencia en archivos binarios mediante escritura directa de structs.

---

## Estructura del Proyecto

```
SIS112-ProyectoClientes/
├── include/              → Archivos de cabecera (.h)
│   ├── cliente.h         → Definición del struct Cliente
│   ├── archivos.h        → Persistencia binaria y seeding
│   ├── crud.h            → Operaciones CRUD
│   ├── ordenacion.h      → Bubble Sort y Merge Sort
│   ├── busqueda.h        → Búsqueda secuencial y binaria
│   ├── intercalacion.h   → Intercalación de archivos
│   └── utilidades.h      → Menú y utilidades generales
├── src/                  → Implementaciones (.cpp)
│   ├── archivos.cpp
│   ├── crud.cpp
│   ├── ordenacion.cpp
│   ├── busqueda.cpp
│   ├── intercalacion.cpp
│   └── utilidades.cpp
├── data/                 → Archivos binarios de datos (.dat)
│   └── clientes.dat
└── main.cpp              → Punto de entrada (solo llamadas a funciones)
```

---

## Compilación y Ejecución

### Requisitos
- Compilador g++ (MinGW o TDM-GCC en Windows)
- Sistema operativo: Windows / Linux

### Compilar desde la terminal

```bash
g++ -std=c++17 -Wall -o sistema main.cpp src/archivos.cpp src/crud.cpp src/ordenacion.cpp src/busqueda.cpp src/intercalacion.cpp src/utilidades.cpp -I include
```

### Ejecutar

**Windows:**
```bash
.\sistema.exe
```

**Linux:**
```bash
./sistema
```

---

## Guía de Uso Rápido

Al iniciar por primera vez, el sistema carga automáticamente **10 registros de prueba** con datos bolivianos reales.

### Menú principal

```
1. Crear cliente        → Alta de nuevo cliente (ID asignado automáticamente)
2. Listar clientes      → Muestra todos los registros almacenados
3. Modificar cliente    → Edita datos de un cliente por ID
4. Eliminar cliente     → Elimina un cliente por ID
5. Ordenar / Comparar  → Bubble Sort vs Merge Sort con reporte de eficiencia
6. Buscar cliente       → Secuencial, binaria iterativa o binaria recursiva
7. Intercalar archivos  → Merge de dos archivos .dat ordenados
8. Reinicializar datos  → Recarga los 10 registros de prueba
9. Salir
```

### Módulo de Ordenación (opción 5)
- **Opción 3** ejecuta ambos algoritmos y muestra un reporte comparativo indicando cuál fue más eficiente en comparaciones e intercambios.

### Módulo de Búsqueda (opción 6)
- **Opción 1:** Búsqueda secuencial — recorre el vector linealmente
- **Opción 2:** Búsqueda binaria iterativa — requiere datos ordenados por ID
- **Opción 3:** Búsqueda binaria recursiva — requiere datos ordenados por ID  
Todas muestran el número de iteraciones o llamadas recursivas realizadas.

---

## Persistencia de Datos

Los datos se almacenan en formato **binario** (`data/clientes.dat`) mediante escritura directa del struct `Cliente`. Esto garantiza lectura y escritura eficiente con `fstream` en modo `ios::binary`.

---

*SIS-112 Programación I — UCB San Pablo La Paz — Gestión 1/2026*
