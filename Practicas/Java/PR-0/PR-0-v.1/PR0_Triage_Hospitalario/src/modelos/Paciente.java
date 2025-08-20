// Archivo: practicas/PR0-triage-hospitalario/src/modelos/Paciente.java
package modelos;

/**
 * Clase que representa un paciente en el sistema de triage hospitalario.
 * 
 * IMPORTANTE: La prioridad funciona así:
 * - 1 = MÁS urgente (atender inmediatamente)
 * - 10 = MENOS urgente (puede esperar)
 * 
 * Esta clase implementa Comparable para poder ordenar pacientes
 * automáticamente por prioridad.
 */
public class Paciente implements Comparable<Paciente> {
    
    // ============== ATRIBUTOS ==============
    // Todos son private para encapsulación (nadie los modifica directamente)
    
    private int id;                // Identificador único del paciente
    private String nombre;         // Nombre completo del paciente
    private int prioridad;         // Nivel de urgencia (1-10)
    private long tiempoLlegada;    // Cuándo llegó (en milisegundos desde 1970)
    
    
    // ============== CONSTRUCTOR ==============
    /**
     * Crea un nuevo paciente con todos sus datos.
     * 
     * @param id Identificador único (no se puede repetir)
     * @param nombre Nombre del paciente
     * @param prioridad Urgencia del 1 (más urgente) al 10 (menos urgente)
     * @param tiempoLlegada Timestamp de cuando llegó al hospital
     * @throws IllegalArgumentException si la prioridad no está entre 1 y 10
     */
    public Paciente(int id, String nombre, int prioridad, long tiempoLlegada) {
        // VALIDACIÓN: La prioridad DEBE estar entre 1 y 10
        if (prioridad < 1 || prioridad > 10) {
            throw new IllegalArgumentException(
                "Error: La prioridad debe estar entre 1 y 10. Se recibió: " + prioridad
            );
        }
        
        this.id = id;
        this.nombre = nombre;
        this.prioridad = prioridad;
        this.tiempoLlegada = tiempoLlegada;
    }
    
    
    // ============== GETTERS ==============
    // Métodos para obtener información (lectura solamente)
    
    public int getId() { 
        return id; 
    }
    
    public String getNombre() { 
        return nombre; 
    }
    
    public int getPrioridad() { 
        return prioridad; 
    }
    
    public long getTiempoLlegada() { 
        return tiempoLlegada; 
    }
    
    
    // ============== SETTERS ==============
    // Solo permitimos cambiar la prioridad (por si el doctor la re-evalúa)
    
    /**
     * Actualiza la prioridad del paciente.
     * Útil si el médico re-evalúa al paciente.
     * 
     * @param prioridad Nueva prioridad (1-10)
     * @throws IllegalArgumentException si la prioridad no es válida
     */
    public void setPrioridad(int prioridad) {
        if (prioridad < 1 || prioridad > 10) {
            throw new IllegalArgumentException(
                "Error: La prioridad debe estar entre 1 y 10. Se recibió: " + prioridad
            );
        }
        this.prioridad = prioridad;
    }
    
    
    // ============== MÉTODO CLAVE: compareTo ==============
    /**
     * Compara este paciente con otro para determinar quién debe ser atendido primero.
     * 
     * REGLAS DE COMPARACIÓN:
     * 1. Primero compara por prioridad (menor número = más urgente)
     * 2. Si tienen la misma prioridad, el que llegó primero va primero (FIFO)
     * 
     * @param otro El otro paciente a comparar
     * @return negativo si este paciente es más urgente,
     *         0 si son igual de urgentes,
     *         positivo si el otro es más urgente
     */
    @Override
    public int compareTo(Paciente otro) {
        // PASO 1: Comparar prioridades
        if (this.prioridad != otro.prioridad) {
            // Si yo tengo prioridad 1 y el otro 3:
            // Integer.compare(1, 3) = -1 (negativo)
            // Esto significa que YO voy primero
            return Integer.compare(this.prioridad, otro.prioridad);
        }
        
        // PASO 2: Si las prioridades son iguales, usar tiempo de llegada
        // El que llegó primero (tiempo menor) va primero
        return Long.compare(this.tiempoLlegada, otro.tiempoLlegada);
    }
    
    
    // ============== MÉTODOS DE IGUALDAD ==============
    /**
     * Determina si dos pacientes son el mismo.
     * Dos pacientes son iguales si tienen el mismo ID.
     * 
     * @param obj El objeto a comparar
     * @return true si son el mismo paciente
     */
    @Override
    public boolean equals(Object obj) {
        // Si es exactamente el mismo objeto en memoria
        if (this == obj) return true;
        
        // Si es null o de otra clase
        if (obj == null || getClass() != obj.getClass()) return false;
        
        // Comparar por ID
        Paciente paciente = (Paciente) obj;
        return id == paciente.id;
    }
    
    /**
     * Genera un código hash basado en el ID.
     * Necesario cuando usamos equals().
     * 
     * @return código hash del paciente
     */
    @Override
    public int hashCode() {
        return Integer.hashCode(id);
    }
    
    
    // ============== MÉTODO PARA IMPRIMIR ==============
    /**
     * Convierte el paciente a texto para poder imprimirlo.
     * Útil para debugging.
     * 
     * @return Representación en texto del paciente
     */
    @Override
    public String toString() {
        return String.format(
            "Paciente{id=%d, nombre='%s', prioridad=%d, llegada=%d}",
            id, nombre, prioridad, tiempoLlegada
        );
    }
    
    
    // ============== MÉTODOS ADICIONALES DE UTILIDAD ==============
    /**
     * Calcula cuánto tiempo lleva esperando el paciente.
     * 
     * @param tiempoActual El tiempo actual en milisegundos
     * @return Minutos que lleva esperando
     */
    public long getMinutosEsperando(long tiempoActual) {
        long milisegundosEsperando = tiempoActual - tiempoLlegada;
        return milisegundosEsperando / (60 * 1000); // Convertir a minutos
    }
    
    /**
     * Obtiene una descripción de la urgencia en palabras.
     * 
     * @return Descripción textual de la prioridad
     */
    public String getDescripcionUrgencia() {
        if (prioridad <= 2) return "CRÍTICO";
        if (prioridad <= 4) return "URGENTE";
        if (prioridad <= 6) return "MODERADO";
        if (prioridad <= 8) return "LEVE";
        return "NO URGENTE";
    }
}