# Instrucciones para Claude Code - COM-11113

## 🎓 Información del Proyecto
- **Estudiante:** David Fernando Avila Díaz
- **Clave Única:** 197851
- **Materia:** COM-11113 Análisis de Algoritmos y Complejidad Computacional
- **Profesor:** Marco Morales Aguirre
- **Semestre:** Otoño 2025
- **Repositorio GitHub:** `EDA-COM-11113-001-DavidAvila` (privado)

## 📋 REGLAS FUNDAMENTALES

### REGLA 0: Desarrollo Paso a Paso
**SIEMPRE** que programemos algo, vamos paso por paso:
1. Explicar el concepto teóricamente primero
2. Derivar la complejidad antes de implementar
3. Implementar incrementalmente
4. Probar cada componente antes de continuar
5. Documentar el razonamiento en cada paso

### REGLA 1: No Usar Bibliotecas para Estructuras Estudiadas
- **PROHIBIDO** usar bibliotecas externas para estructuras de datos del curso
- Implementar desde cero: listas ligadas, pilas, colas, árboles, heaps, grafos
- **PERMITIDO** usar bibliotecas para funciones complementarias (I/O, random, time)
- **PERMITIDO** comparar tu implementación con bibliotecas existentes después

### REGLA 2: Filosofía de Aprendizaje
> "No usar nada que no pueda explicar completamente"
- Priorizar comprensión profunda sobre velocidad
- Cada línea de código debe poder ser explicada
- Si no entiendes algo, no lo implementes hasta comprenderlo

## 🛠️ Configuración Técnica

### Lenguaje y Entorno
- **Lenguaje:** Java (sin Maven/Gradle)
- **Versión:** Java 11 o superior
- **Compilación:** javac directo
- **Ejecución:** java desde línea de comandos
- **IDE:** VSCode (sin extensiones de build automático)

### Estructura del Proyecto
```
EDA-COM-11113-001-DavidAvila/
├── practicas/
│   ├── PR0-triage-hospitalario/
│   │   ├── src/
│   │   │   ├── Main.java
│   │   │   ├── estructuras/
│   │   │   │   ├── HeapBinario.java
│   │   │   │   ├── ListaLigadaOrdenada.java
│   │   │   │   └── BinarySearchTree.java
│   │   │   ├── modelos/
│   │   │   │   └── Paciente.java
│   │   │   └── simulacion/
│   │   │       └── SimuladorTriage.java
│   │   ├── data/
│   │   │   └── resultados.csv
│   │   ├── graphs/
│   │   │   └── comparacion_tiempos.png
│   │   ├── docs/
│   │   │   └── analisis_teorico.md
│   │   ├── compile.sh
│   │   ├── run.sh
│   │   └── README.md
│   └── PR[N]-[nombre]/
├── tareas/
│   └── T[N]-[tema]/
├── examenes/
├── notas/
│   └── [fecha]-[tema].md
└── INSTRUCCIONES_CLAUDE_CODE.md
```

## 💻 Protocolos de Desarrollo

### 1. Protocolo de Inicio de Práctica
```
1. Leer completamente el enunciado
2. Identificar estructuras de datos requeridas
3. Hacer análisis teórico de complejidad esperada
4. Diseñar arquitectura de clases
5. Implementar estructura por estructura
6. Integrar y probar
```

### 2. Protocolo de Implementación de Estructuras
```java
// SIEMPRE seguir este patrón:

/**
 * [Nombre de la Estructura]
 * 
 * Complejidad:
 * - Inserción: O(?)
 * - Eliminación: O(?)
 * - Búsqueda: O(?)
 * 
 * Justificación: [Por qué estas complejidades]
 */
public class EstructuraDeDatos {
    // Implementación desde cero
}
```

### 3. Protocolo de Análisis y Medición
```
1. Implementar cronómetros para cada operación
2. Generar datos de prueba (mínimo 1000 elementos)
3. Medir tiempos en nanosegundos
4. Exportar resultados a CSV
5. Graficar con herramienta externa (Python/Excel)
6. Comparar con análisis teórico
```

### 4. Protocolo de Documentación
Cada práctica DEBE incluir un README.md con:
```markdown
# Práctica [N]: [Nombre]

## Descripción
[Qué hace el programa]

## Estructuras Implementadas
- Estructura 1: [descripción y complejidad]
- Estructura 2: [descripción y complejidad]

## Compilación
```bash
javac -d bin src/**/*.java
```

## Ejecución
```bash
java -cp bin Main [argumentos]
```

## Análisis de Resultados
[Comparación teoría vs práctica]
[Gráficas y conclusiones]
```

## 📊 Way of Working

### Flujo de Trabajo por Sesión
1. **Inicio (5 min)**
   - Revisar dónde quedamos
   - Establecer objetivo de la sesión
   - Verificar que entendemos el problema

2. **Desarrollo (tiempo principal)**
   - Implementar paso a paso
   - Documentar mientras codificamos
   - Hacer pruebas incrementales

3. **Cierre (10 min)**
   - Commit con mensaje descriptivo
   - Documentar pendientes
   - Planear siguiente sesión

### Commits en Git
```bash
# Formato de mensajes de commit
[TIPO]: descripción corta

# Tipos:
FEAT: nueva funcionalidad
FIX: corrección de bug
DOC: documentación
TEST: pruebas
REFACTOR: mejora de código
MEASURE: mediciones de rendimiento

# Ejemplo:
git commit -m "FEAT: implementar inserción en Heap Binario"
```

### Entrega de Prácticas
1. Código fuente completo y funcional
2. README.md con instrucciones claras
3. Gráficas de tiempos de ejecución
4. Análisis comparativo teórico vs empírico
5. Hacer Pull Request cuando esté listo

## ⚠️ Consideraciones Importantes

### Para la Práctica 0 (Triage Hospitalario)
- Implementar 2 de las 3 estructuras propuestas
- Simular 1000 pacientes con arribos aleatorios
- Tiempo medio entre arribos: 1 minuto
- Prioridades: 1 (más urgente) a 10 (menos urgente)
- Medir tiempos de inserción y extracción
- Generar gráficas comparativas

### Estructuras de Datos para PR0
1. **Heap Binario** (Cola de Prioridades)
   - Árbol binario completo
   - Propiedad de heap (min o max)
   - Inserción: O(log n)
   - Extracción: O(log n)

2. **Lista Ligada Ordenada**
   - Nodos enlazados
   - Mantener orden por prioridad
   - Inserción: O(n)
   - Extracción: O(1)

3. **Binary Search Tree (BST)**
   - Árbol binario de búsqueda
   - Sin balanceo (por ahora)
   - Inserción: O(log n) promedio, O(n) peor caso
   - Extracción del mínimo: O(log n) promedio

## 🚫 Antipatrones a Evitar

### NUNCA hacer:
1. Copiar código sin entenderlo
2. Usar `ArrayList`, `LinkedList`, `PriorityQueue` de Java
3. Optimizar prematuramente
4. Ignorar casos extremos (lista vacía, un elemento, muchos elementos)
5. Entregar sin probar exhaustivamente
6. Usar recursión sin entender el caso base
7. Implementar sin análisis teórico previo

### SIEMPRE hacer:
1. Entender antes de codear
2. Probar con casos límite
3. Medir y comparar con teoría
4. Documentar decisiones de diseño
5. Mantener código limpio y legible
6. Versionar frecuentemente en Git

## 📝 Plantilla para Análisis de Algoritmos

```java
/**
 * Análisis del Algoritmo: [Nombre]
 * 
 * Descripción:
 * [Qué hace el algoritmo]
 * 
 * Pseudocódigo:
 * [Pasos del algoritmo]
 * 
 * Análisis de Complejidad:
 * - Mejor caso: O(?) - [cuando ocurre]
 * - Caso promedio: O(?) - [condiciones típicas]
 * - Peor caso: O(?) - [cuando ocurre]
 * 
 * Complejidad espacial: O(?)
 * 
 * Justificación matemática:
 * [Demostración o razonamiento]
 */
```

## 🎯 Recordatorios para Claude Code

Cuando trabajemos juntos:
1. **Siempre explicar** el "por qué" detrás del código
2. **Implementar incrementalmente** - no todo de golpe
3. **Probar cada método** antes de continuar
4. **Documentar inline** con comentarios significativos
5. **Seguir convenciones Java** (camelCase, nombres descriptivos)
6. **No usar imports** de java.util para estructuras de datos
7. **Medir tiempos** con System.nanoTime()
8. **Generar datos reproducibles** (usar semillas en Random)

## 📚 Referencias del Curso

- **Libro principal:** Erickson, Jeff. *Algorithms*. 1st edition, 2019
- **Referencia:** Cormen, Leiserson, Rivest, Stein. *Introduction to Algorithms*. MIT Press, 2022
- **Objetivo:** Comprender, no solo implementar

---

*"El verdadero aprendizaje ocurre cuando puedes explicar no solo el 'qué', sino el 'por qué' y el 'cuándo' de cada algoritmo."*

**Última actualización:** Agosto 2025
**Mantenido por:** David Fernando Avila Díaz