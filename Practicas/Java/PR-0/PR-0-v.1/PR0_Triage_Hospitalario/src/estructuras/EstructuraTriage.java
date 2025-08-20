/**
 * Interfaz para estructuras de datos del Sistema de Triage Hospitalario
 * 
 * Define las operaciones básicas que debe implementar cualquier
 * estructura de datos utilizada en el sistema de triage.
 * 
 * @author David Fernando Avila Díaz
 * @version 1.0
 * @since Otoño 2025
 */

package estructuras;

import modelos.Paciente;

public interface EstructuraTriage {
    
    /**
     * Inserta un nuevo paciente en la estructura manteniendo
     * el orden por prioridad (1 = más urgente, 10 = menos urgente)
     * 
     * @param paciente El paciente a insertar
     * @throws IllegalArgumentException si el paciente es null
     */
    void insertar(Paciente paciente);
    
    /**
     * Extrae y retorna el paciente con mayor prioridad (prioridad más baja)
     * En caso de empate, se atiende por orden de llegada (FIFO)
     * 
     * @return El paciente con mayor prioridad, null si la estructura está vacía
     */
    Paciente extraerSiguiente();
    
    /**
     * Busca un paciente por su ID único
     * 
     * @param id El ID del paciente a buscar
     * @return El paciente con el ID especificado, null si no se encuentra
     */
    Paciente buscar(int id);
    
    /**
     * Verifica si la estructura está vacía
     * 
     * @return true si no hay pacientes, false en caso contrario
     */
    boolean estaVacia();
    
    /**
     * Retorna el número de pacientes en la estructura
     * 
     * @return Cantidad actual de pacientes
     */
    int tamano();
    
    /**
     * Retorna el paciente con mayor prioridad sin extraerlo
     * 
     * @return El paciente con mayor prioridad, null si la estructura está vacía
     */
    Paciente verSiguiente();
    
    /**
     * Limpia todos los pacientes de la estructura
     */
    void limpiar();
    
    /**
     * Retorna una representación en cadena de la estructura
     * Útil para debugging y visualización
     * 
     * @return String con la representación de la estructura
     */
    String toString();
}