# 🔵 Prácticas en C++

Esta carpeta contiene todas las prácticas implementadas en C++.

## 🛠️ Configuración del Entorno

### Requisitos
- **Compilador**: g++ 7.0+ o clang++ 
- **Estándar**: C++11 o superior
- **Build System**: GNU Make

### Compilación General
```bash
cd PR[X]
make clean
make
```

## 📁 Prácticas Completadas

### ✅ PR0 - Sistema de Triage Hospitalario
- **Estructuras**: Min Heap, Lista Ligada Ordenada
- **Complejidad**: O(log n) vs O(n) para inserción
- **Estado**: Completado ✅

### 🔄 Próximas Prácticas
- PR1: Por definir
- PR2: Por definir

## 📚 Convenciones de Código

- **Estilo**: Google C++ Style Guide
- **Naming**: 
  - Classes: `PascalCase`
  - Functions/Methods: `camelCase`
  - Variables: `snake_case`
  - Constants: `UPPER_SNAKE_CASE`
- **Headers**: Usar header guards
- **Memory**: Preferir smart pointers sobre raw pointers

## 🔧 Estructura Típica de Proyecto
```
PR[X]/
├── src/         # Archivos fuente (.cpp)
├── include/     # Headers (.h)
├── data/        # Datos de entrada
├── graphs/      # Gráficas de rendimiento
├── docs/        # Documentación
├── Makefile     # Script de compilación
└── README.md    # Descripción del proyecto
```