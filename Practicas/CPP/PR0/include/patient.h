#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <ctime>

struct Patient {
    int id;
    std::string name;
    int priority;  // 1 (más urgente) - 10 (menos urgente)
    time_t arrivalTime;
    
    Patient(int _id, std::string _name, int _priority) 
        : id(_id), name(_name), priority(_priority) {
        arrivalTime = time(nullptr);
    }
};

#endif
