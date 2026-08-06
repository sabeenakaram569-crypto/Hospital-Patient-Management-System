#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include "Patient.h"
using namespace std;

/*
    PQNode represents a single node in the priority Queue
    Each Node stores:
    - Pointer to patient data
    - Pointer to next node in the queue
*/
struct PQNode
{
    // Pointer to patient object
    Patient* patientPtr;
    // Pointer to next node
    PQNode* next;
};

/*
    PriorityQueue Class
    Implements a priority queue using a linked list
    Patients with higher priority (severity) are served first.
*/

class PriorityQueue
{
public:

    // Constructor
    PriorityQueue();
    // Destructor
    ~PriorityQueue();
    // Returns the patient at the front without removing it
    Patient* getPatient();

    // Insert a patient into the queue based on priority
    void enqueue(Patient* p);

    // Remove and return the highest priority patient
    Patient* dequeue();

    // Check if the queue is empty
    bool isEmpty();

    // Display all patients in the queue
    void display();

private:
    // Pointer to the first (highest priority) node
    PQNode* front;

};

#endif
