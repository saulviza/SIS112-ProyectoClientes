================================================================
  SISTEMA DE GESTION DE CLIENTES EN C++
  Universidad Católica Boliviana "San Pablo"
  Facultad de Ingeniería — Programación I (SIS-112)
  Gestión 1/2026
================================================================

CARRERA:
  Ingeniería de Sistemas

INTEGRANTES:
  - [Nombre Integrante 1]
  - [Nombre Integrante 2]

DOMINIO ELEGIDO:
  Gestión de Clientes — Sistema que permite administrar un
  registro de clientes (afiliados y no afiliados) mediante
  un archivo CSV como almacenamiento persistente.

ESTRUCTURA DEL PROYECTO:
  main.cpp          → Punto de entrada, menú principal
  cliente.h         → Definición de la estructura Cliente
  archivos.h/.cpp   → Lectura y escritura del archivo CSV
  crud.h/.cpp       → Crear, listar, modificar, eliminar
  vectores.h/.cpp   → Carga del CSV a vector en memoria
  ordenacion.h/.cpp → Bubble Sort optimizado (por ID, apellido, nombre)
  busqueda.h/.cpp   → Búsqueda secuencial y binaria
  intercalacion.h/.cpp → Intercalación de dos archivos CSV
  utilidades.h/.cpp → Menú, limpiar pantalla, pausar
  clientes.csv      → Archivo de datos principal (12 registros)
  clientes1.csv     → Archivo de prueba para intercalación
  clientes2.csv     → Archivo de prueba para intercalación

FUNCIONALIDADES:
  1. Crear cliente         (CRUD - CREATE)
  2. Listar clientes       (CRUD - READ)
  3. Modificar cliente     (CRUD - UPDATE)
  4. Eliminar cliente      (CRUD - DELETE)
  5. Ordenar clientes      (Bubble Sort optimizado)
  6. Búsqueda secuencial   (por ID)
  7. Búsqueda binaria      (por ID, requiere ordenar primero)
  8. Intercalar archivos   (merge de dos CSV ordenados)
  9. Salir

INSTRUCCIONES DE COMPILACIÓN:
  Opción A — Dev-C++ (Embarcadero 6.3):
    1. Abrir ProyectoClientes.dev
    2. Asegurarse de que todos los .cpp estén en el proyecto
    3. Presionar F11 para compilar todo
    4. Presionar F10 para ejecutar

  Opción B — Línea de comandos (g++):
    g++ -std=c++11 main.cpp archivos.cpp crud.cpp vectores.cpp
        ordenacion.cpp busqueda.cpp intercalacion.cpp utilidades.cpp
        -o SistemaClientes

INSTRUCCIONES DE EJECUCIÓN:
  1. El archivo clientes.csv debe estar en la misma carpeta
     que el ejecutable (.exe en Windows).
  2. Ejecutar SistemaClientes.exe (Windows) o ./SistemaClientes (Linux)
  3. Navegar el menú con las opciones numeradas del 1 al 9.

NOTA SOBRE BÚSQUEDA BINARIA:
  La búsqueda binaria requiere que los datos estén previamente
  ordenados por ID (opción 5 → ordenar por ID).

================================================================
