#ifndef QUEUE_H
#define QUEUE_H

#include "Patient.h"
#include <iostream>
using namespace std;

/*
 Node structure
 Each node stores a patient pointer and link to next node
*/
struct Node
{
    // pointer to patient object
    Patient* patientPtr;
    // pointer to next node
    Node* next;
};

// Queue Class: Implements FIFO
class Queue
{
public:
    // Constructor
    Queue();

    // Destructor
    ~Queue();

    // Function to insert patient at rear
    void enqueue(Patient* p);

    // Function to remove patient from front
    Patient* dequeue();

    // Function to check if queue is empty
    bool isEmpty();

    // Function to display patients in the queue
    void display();
    // Function that returns total number of patients
    int getCounter();

private:
    // points to first patient in the queue
    Node* front;
    // points to last patient in the queue
    Node* rear;
    // keeps count of patients in the queue
    int counter;
};

#endif
