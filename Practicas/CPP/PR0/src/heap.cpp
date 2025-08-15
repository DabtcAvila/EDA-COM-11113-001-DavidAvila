#include "heap.h"
#include <iostream>
#include <algorithm>

void MinHeap::heapifyUp(int index) {
    while (index > 0 && heap[parent(index)].priority > heap[index].priority) {
        std::swap(heap[parent(index)], heap[index]);
        index = parent(index);
    }
}

void MinHeap::heapifyDown(int index) {
    int minIndex = index;
    int left = leftChild(index);
    int right = rightChild(index);
    
    if (left < heap.size() && heap[left].priority < heap[minIndex].priority)
        minIndex = left;
    
    if (right < heap.size() && heap[right].priority < heap[minIndex].priority)
        minIndex = right;
    
    if (minIndex != index) {
        std::swap(heap[index], heap[minIndex]);
        heapifyDown(minIndex);
    }
}

void MinHeap::insert(const Patient& patient) {
    heap.push_back(patient);
    heapifyUp(heap.size() - 1);
}

Patient MinHeap::extractMin() {
    if (heap.empty()) {
        throw std::runtime_error("Heap vacío");
    }
    
    Patient min = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    
    if (!heap.empty()) {
        heapifyDown(0);
    }
    
    return min;
}

bool MinHeap::search(int patientId) {
    for (const auto& patient : heap) {
        if (patient.id == patientId) {
            return true;
        }
    }
    return false;
}

void MinHeap::printHeap() {
    std::cout << "Heap (Prioridades): ";
    for (const auto& p : heap) {
        std::cout << p.priority << " ";
    }
    std::cout << std::endl;
}