#include "linked_list.h"
#include <iostream>
#include <stdexcept>

LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::insert(const Patient& patient) {
    Node* newNode = new Node(patient);
    
    // Si está vacía o el nuevo tiene mayor prioridad (menor número)
    if (head == nullptr || head->data.priority > patient.priority) {
        newNode->next = head;
        head = newNode;
    } else {
        // Buscar posición correcta
        Node* current = head;
        while (current->next != nullptr && 
               current->next->data.priority <= patient.priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    listSize++;
}

Patient LinkedList::extractMin() {
    if (head == nullptr) {
        throw std::runtime_error("Lista vacía");
    }
    
    Node* temp = head;
    Patient min = head->data;
    head = head->next;
    delete temp;
    listSize--;
    
    return min;
}

bool LinkedList::search(int patientId) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data.id == patientId) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void LinkedList::printList() {
    std::cout << "Lista (Prioridades): ";
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data.priority << " ";
        current = current->next;
    }
    std::cout << std::endl;
}