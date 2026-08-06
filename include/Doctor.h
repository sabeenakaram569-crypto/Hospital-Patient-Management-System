#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>
#include <iostream>
#include "PriorityQueue.h"

using namespace std;

// Doctor Class
class Doctor
{
public:
    // Doctor Identity

    // Doctor ID
    int doctorID;
    // Doctor Name
    string name;
    // Doctor Specialization
    string specialization;

    // The Waiting Room
    // Every doctor has their own Priority Queue.
    // Patients with Severity will automatically jump to the front.
    PriorityQueue waitingRoom;

    // Constructor
    Doctor(int id, string n, string spec);

    // Function to add Patient
    void addPatient(Patient* p);
    // Function to treat Patient
    void treatPatient();
    // Function to display queue for all doctors
    void displayQueue();
};

#endif
