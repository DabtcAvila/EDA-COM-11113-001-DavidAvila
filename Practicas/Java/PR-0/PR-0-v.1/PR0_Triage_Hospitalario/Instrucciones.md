# Práctica 0: Sistema de Triage Hospitalario
## Revisión de Algoritmos y Estructuras de Datos

**Profesor:** Marco Morales Aguirre  
**Departamento Académico de Computación, ITAM**  
**Materia:** COM-11113 Análisis de Algoritmos y Complejidad Computacional  
**Semestre:** Otoño 2025

---

## 1. Objetivos

Que las y los estudiantes:
- Utilicen estructuras de datos para la solución de un problema práctico
- Comparen el desempeño de estructuras de datos alternativas para el mismo problema  
- Practiquen los procesos de entrega de las prácticas de laboratorio

## 2. Problema

En el servicio de urgencias de un hospital público llegan, con alta frecuencia, pacientes con distintos tipos de padecimientos. El administrador del hospital te pide desarrollar un sistema de **Triage** que decida quién es el siguiente paciente a atender basado en la prioridad asignada después de una revisión inicial.

### Requisitos del Sistema

Implementa el sistema de Triage de manera que:

1. **La prioridad se establezca de manera numérica:**
   - `1` = Más urgente (prioridad máxima)
   - `10` = Menos urgente (prioridad mínima)

2. **Implementa el sistema con AL MENOS DOS de las siguientes estructuras de datos:**
   - **Heap Binario** (Priority Queue)
   - **Lista Ligada Ordenada**
   - **Árbol Binario de Búsqueda (BST)**

3. **Compara el desempeño de tus implementaciones en las siguientes operaciones:**
   - **Insert** (insertar nuevo paciente)
   - **Search** (buscar paciente específico)
   - **Delete** (atender/eliminar paciente con mayor prioridad)

### Simulación

- Simular llegadas en tiempo real de **1000 pacientes**
- Tiempo entre arribos: **1 minuto** (aleatorio con distribución uniforme)
- Generar tiempos de arribo y prioridades aleatorias para cada paciente
- Medir el tiempo de ejecución de cada operación en **nanosegundos**

## 3. Especificaciones Técnicas

### Lenguaje y Entorno
- **Lenguaje:** Java (sin Maven/Gradle)
- **Versión:** Java 11 o superior
- **Compilación:** Directa con `javac`
- **NO usar:** `ArrayList`, `LinkedList`, `PriorityQueue`, `TreeSet`, `TreeMap` o cualquier estructura de datos de `java.util`

### Estructura del Proyecto

```
PR0-triage-hospitalario/
├── src/
│   ├── Main.java
│   ├── modelos/
│   │   └── Paciente.java
│   ├── estructuras/
│   │   ├── HeapBinario.java           # Si eliges esta
│   │   ├── ListaLigadaOrdenada.java   # Si eliges esta
│   │   └── ArbolBinarioBusqueda.java  # Si eliges esta
│   └── simulacion/
│       └── SimuladorTriage.java
├── data/
│   └── resultados_tiempos.csv
├── graphs/
│   ├── comparacion_insercion.png
│   ├── comparacion_busqueda.png
│   └── comparacion_eliminacion.png
├── compile.sh
├── run.sh
└── README.md
```

### Clase Paciente (Modelo de Datos)

```java
public class Paciente {
    private int id;
    private String nombre;
    private int prioridad;      // 1 (más urgente) a 10 (menos urgente)
    private long tiempoArribo;  // timestamp en milisegundos
    
    // Constructor, getters, setters, toString()
}
```

### Medición de Tiempos

```java
// Ejemplo de medición
long inicio = System.nanoTime();
estructura.insertar(paciente);
long fin = System.nanoTime();
long tiempoInsercion = fin - inicio;
```

## 4. Implementación de Estructuras

### Opción 1: Heap Binario (Priority Queue)
- Implementar como **Min Heap** (prioridad 1 sale primero)
- Usar arreglo para representación
- Operaciones requeridas:
  - `insertar(Paciente p)` - O(log n)
  - `extraerMinimo()` - O(log n)
  - `buscar(int id)` - O(n)
  - `estaVacio()` - O(1)

### Opción 2: Lista Ligada Ordenada
- Mantener ordenada por prioridad (ascendente)
- Implementar con nodos enlazados
- Operaciones requeridas:
  - `insertar(Paciente p)` - O(n)
  - `extraerPrimero()` - O(1)
  - `buscar(int id)` - O(n)
  - `estaVacia()` - O(1)

### Opción 3: Árbol Binario de Búsqueda (BST)
- Ordenar por prioridad (no balanceado)
- Implementar con nodos enlazados
- Operaciones requeridas:
  - `insertar(Paciente p)` - O(log n) promedio, O(n) peor caso
  - `extraerMinimo()` - O(log n) promedio
  - `buscar(int id)` - O(n) si buscas por ID
  - `estaVacio()` - O(1)

## 5. Análisis Comparativo

### Análisis Teórico (a incluir en README.md)

| Estructura | Inserción | Extracción Mín | Búsqueda |
|------------|-----------|----------------|----------|
| Heap Binario | O(log n) | O(log n) | O(n) |
| Lista Ligada Ordenada | O(n) | O(1) | O(n) |
| BST (promedio) | O(log n) | O(log n) | O(n)* |
| BST (peor caso) | O(n) | O(n) | O(n) |

*La búsqueda por ID en BST es O(n) porque el árbol está ordenado por prioridad, no por ID.

### Métricas a Recolectar
1. Tiempo promedio de inserción (1000 operaciones)
2. Tiempo promedio de extracción del mínimo
3. Tiempo promedio de búsqueda
4. Tiempo total de simulación
5. Uso de memoria (opcional)

## 6. Formato de Trabajo

### Modalidad
- **Esta práctica es EN EQUIPO** (2-3 personas máximo)
- **Todas las demás prácticas serán INDIVIDUALES**
- Duración estimada: 2 semanas

### Scripts de Compilación y Ejecución

**compile.sh:**
```bash
#!/bin/bash
echo "Compilando PR0 - Sistema de Triage..."
javac -d bin src/**/*.java
echo "Compilación completada."
```

**run.sh:**
```bash
#!/bin/bash
echo "Ejecutando simulación de Triage Hospitalario..."
java -cp bin Main
```

## 7. Entregables

Depositar en la carpeta `PR0` de tu repositorio de GitHub del curso:

1. **Código fuente completo** 
   - Implementación de AL MENOS 2 estructuras de datos
   - Simulador con 1000 pacientes
   - Medición de tiempos

2. **Gráficas del tiempo de ejecución**
   - Gráfica comparativa de inserción
   - Gráfica comparativa de extracción
   - Gráfica comparativa de búsqueda
   - Formato: PNG o PDF

3. **Archivo README.md** que contenga:
   - Descripción de cada archivo
   - Instrucciones para compilar y ejecutar
   - **Discusión que compare:**
     - Análisis teórico del desempeño de las estructuras
     - Resultados obtenidos en las gráficas
     - Conclusiones sobre cuál estructura es mejor para este problema
     - Situaciones donde cada estructura sería preferible

## 8. Proceso de Entrega

1. Completar la implementación en tu repositorio privado de GitHub
2. Hacer commit con mensaje descriptivo:
   ```bash
   git commit -m "FEAT: PR0 completada - Sistema de Triage con [estructuras elegidas]"
   ```
3. Hacer Pull Request para revisión
4. El profesor evaluará:
   - Correcta implementación de las estructuras
   - Funcionamiento de la simulación
   - Calidad del análisis comparativo
   - Dominio del código (preguntas durante la revisión)

## 9. Rúbrica de Evaluación

| Criterio | Puntos |
|----------|--------|
| Implementación correcta de estructuras | 40% |
| Simulación funcional con 1000 pacientes | 20% |
| Medición y gráficas de tiempos | 20% |
| Análisis comparativo en README | 15% |
| Documentación y calidad del código | 5% |

## 10. Consejos y Recordatorios

### ⚠️ Importante
- **NO copiar código** - Implementar desde cero para aprender
- **Probar casos extremos**: lista vacía, un solo elemento, muchos elementos
- **Documentar decisiones**: ¿Por qué elegiste esas dos estructuras?
- **Semilla aleatoria**: Usar seed fijo para reproducibilidad
  ```java
  Random random = new Random(42); // Seed fijo
  ```

### 💡 Tips de Implementación
1. Empezar con la estructura más simple (Lista Ligada)
2. Probar cada método individualmente antes de la simulación
3. Crear método `toString()` para debugging
4. Validar que las prioridades se respeten correctamente
5. Considerar pacientes con la misma prioridad (desempate por orden de llegada)

### 📊 Para las Gráficas
- Pueden usar Python (matplotlib), Excel, o cualquier herramienta
- Eje X: Número de operaciones o tiempo
- Eje Y: Tiempo en nanosegundos o milisegundos
- Incluir leyenda clara con las estructuras comparadas

## 11. Preguntas Frecuentes

**P: ¿Qué pasa si dos pacientes tienen la misma prioridad?**  
R: Atender por orden de llegada (FIFO dentro de la misma prioridad)

**P: ¿Necesito implementar las tres estructuras?**  
R: No, solo DOS de las tres opciones

**P: ¿Puedo usar Collections.sort()?**  
R: No para las estructuras principales, pero sí para procesar los datos de salida/gráficas

**P: ¿Cómo genero las gráficas?**  
R: Exporta los tiempos a CSV y usa Python, Excel, o cualquier herramienta de graficación

---

**Fecha de inicio:** Viernes de la primera semana  
**Fecha de entrega:** Dos semanas después  
**Valor:** Esta práctica tiene menor peso que las siguientes (es de revisión)

*"La idea es comparar estas estructuras de datos y ver cuál es la que más nos conviene para este problema particular."* - Prof. Marco Morales