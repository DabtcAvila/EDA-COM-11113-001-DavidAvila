#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <chrono>
#include "patient.h"

class MinHeap {
private:
    std::vector<Patient> heap;
    
    // Funciones auxiliares para navegar el árbol
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }
    
    // Mantener la propiedad del heap
    void heapifyUp(int index);
    void heapifyDown(int index);
    
public:
    MinHeap() {}
    
    // Operaciones principales
    void insert(const Patient& patient);
    Patient extractMin();
    bool search(int patientId);
    bool isEmpty() { return heap.empty(); }
    int size() { return heap.size(); }
    
    // Para debugging
    void printHeap();
};

#endif