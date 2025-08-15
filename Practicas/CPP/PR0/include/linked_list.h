#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "patient.h"

class Node {
public:
    Patient data;
    Node* next;
    
    Node(const Patient& p) : data(p), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    int listSize;
    
public:
    LinkedList() : head(nullptr), listSize(0) {}
    ~LinkedList();
    
    // Operaciones principales
    void insert(const Patient& patient);  // Inserción ordenada
    Patient extractMin();
    bool search(int patientId);
    bool isEmpty() { return head == nullptr; }
    int size() { return listSize; }
    
    // Para debugging
    void printList();
};

#endif