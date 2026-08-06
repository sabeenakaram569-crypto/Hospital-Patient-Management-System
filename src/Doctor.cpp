#include "Doctor.h"
#include <iostream>

using namespace std;
// Constructor
Doctor::Doctor(int id, string n, string spec)
{
    doctorID = id;
    name = n;
    specialization = spec;
}

// Add Patient to Line
void Doctor::addPatient(Patient* p)
{
    // We pass the patient pointer + their priority to the queue
    waitingRoom.enqueue(p);

    cout << "Assigned to " << name << " (" << specialization << ")\n";
}

// Treat the Next Patient
void Doctor::treatPatient()
{
    if (waitingRoom.isEmpty())
    {
        cout << name << " is free. No patients waiting.\n";
        return;
    }

    // Get the patient at the front
    Patient* p = waitingRoom.getPatient();

    // Update their status (This updates the Skip List record too!)
    p->status = "Treated";

    cout << name << " is now treating: " << p->name << endl;

    // Remove them from the Waiting Room
    waitingRoom.dequeue();
}

// View Waiting List
void Doctor::displayQueue()
{
    cout << "Waiting List for " << name << ":\n";
    waitingRoom.display();
}
