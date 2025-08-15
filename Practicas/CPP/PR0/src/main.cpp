#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <iomanip>
#include "patient.h"
#include "heap.h"
#include "linked_list.h"

using namespace std;
using namespace chrono;

// Generar paciente aleatorio
Patient generateRandomPatient(int id) {
    string name = "Paciente_" + to_string(id);
    int priority = rand() % 10 + 1;  // Prioridad 1-10
    return Patient(id, name, priority);
}

// Medir tiempo de operaciones
void measurePerformance(int numPatients) {
    cout << "\n=== MIDIENDO DESEMPEÑO CON " << numPatients << " PACIENTES ===" << endl;
    
    // Generar pacientes de prueba
    vector<Patient> patients;
    for (int i = 0; i < numPatients; i++) {
        patients.push_back(generateRandomPatient(i));
    }
    
    // === HEAP ===
    cout << "\n--- HEAP (Min Heap) ---" << endl;
    MinHeap heap;
    
    // Medir INSERT
    auto start = high_resolution_clock::now();
    for (const auto& p : patients) {
        heap.insert(p);
    }
    auto end = high_resolution_clock::now();
    auto heapInsertTime = duration_cast<microseconds>(end - start).count();
    cout << "INSERT total: " << heapInsertTime << " μs" << endl;
    
    // Medir SEARCH (buscar 100 pacientes aleatorios)
    start = high_resolution_clock::now();
    for (int i = 0; i < 100; i++) {
        heap.search(rand() % numPatients);
    }
    end = high_resolution_clock::now();
    auto heapSearchTime = duration_cast<microseconds>(end - start).count();
    cout << "SEARCH (100 búsquedas): " << heapSearchTime << " μs" << endl;
    
    // Medir EXTRACT MIN (sacar 100 pacientes)
    start = high_resolution_clock::now();
    for (int i = 0; i < min(100, numPatients); i++) {
        if (!heap.isEmpty()) {
            heap.extractMin();
        }
    }
    end = high_resolution_clock::now();
    auto heapExtractTime = duration_cast<microseconds>(end - start).count();
    cout << "EXTRACT MIN (100 ops): " << heapExtractTime << " μs" << endl;
    
    // === LISTA LIGADA ===
    cout << "\n--- LISTA LIGADA ORDENADA ---" << endl;
    LinkedList list;
    
    // Medir INSERT
    start = high_resolution_clock::now();
    for (const auto& p : patients) {
        list.insert(p);
    }
    end = high_resolution_clock::now();
    auto listInsertTime = duration_cast<microseconds>(end - start).count();
    cout << "INSERT total: " << listInsertTime << " μs" << endl;
    
    // Medir SEARCH
    start = high_resolution_clock::now();
    for (int i = 0; i < 100; i++) {
        list.search(rand() % numPatients);
    }
    end = high_resolution_clock::now();
    auto listSearchTime = duration_cast<microseconds>(end - start).count();
    cout << "SEARCH (100 búsquedas): " << listSearchTime << " μs" << endl;
    
    // Medir EXTRACT MIN
    start = high_resolution_clock::now();
    for (int i = 0; i < min(100, numPatients); i++) {
        if (!list.isEmpty()) {
            list.extractMin();
        }
    }
    end = high_resolution_clock::now();
    auto listExtractTime = duration_cast<microseconds>(end - start).count();
    cout << "EXTRACT MIN (100 ops): " << listExtractTime << " μs" << endl;
    
    // === COMPARACIÓN ===
    cout << "\n=== COMPARACIÓN ===" << endl;
    cout << fixed << setprecision(2);
    cout << "INSERT - Heap vs Lista: " << (double)heapInsertTime/listInsertTime << "x" << endl;
    cout << "SEARCH - Heap vs Lista: " << (double)heapSearchTime/listSearchTime << "x" << endl;
    cout << "EXTRACT - Heap vs Lista: " << (double)heapExtractTime/listExtractTime << "x" << endl;
}

int main() {
    srand(time(nullptr));
    
    cout << "========================================" << endl;
    cout << "   SISTEMA DE TRIAGE HOSPITALARIO" << endl;
    cout << "========================================" << endl;
    
    // Prueba pequeña
    cout << "\n=== PRUEBA BÁSICA ===" << endl;
    MinHeap testHeap;
    testHeap.insert(Patient(1, "Juan", 5));
    testHeap.insert(Patient(2, "María", 2));
    testHeap.insert(Patient(3, "Pedro", 8));
    testHeap.insert(Patient(4, "Ana", 1));
    testHeap.insert(Patient(5, "Luis", 3));
    
    cout << "Orden de atención (Heap):" << endl;
    while (!testHeap.isEmpty()) {
        Patient p = testHeap.extractMin();
        cout << "  " << p.name << " (Prioridad " << p.priority << ")" << endl;
    }
    
    // Mediciones con diferentes tamaños
    measurePerformance(100);
    measurePerformance(500);
    measurePerformance(1000);
    
    return 0;
}