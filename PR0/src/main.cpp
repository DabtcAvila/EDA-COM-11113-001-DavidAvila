#include <iostream>
#include <vector>
#include "patient.h"

using namespace std;

int main() {
    cout << "Sistema de Triage Hospitalario" << endl;
    cout << "==============================" << endl;
    
    // Prueba básica
    Patient p1(1, "Juan Pérez", 3);
    cout << "Paciente: " << p1.name << " - Prioridad: " << p1.priority << endl;
    
    return 0;
}
