#include "queue.h"
#include <iostream>
using namespace std;

/*
 Constructor
 Initializes an empty queue
*/
Queue::Queue()
{
    // no first node
    front = nullptr;
    // no last node
    rear = nullptr;
    // Queue is empty
    counter = 0;
}

/*
 Destructor
 Removes all nodes to free memory
*/
Queue::~Queue()
{
    while (!isEmpty())
    {
        // remove nodes one by one
        dequeue();
    }
}

// Checks whether Queue is empty or not
bool Queue::isEmpty()
{
    return front == nullptr;
}

// Enqueue a patient at the rear (FIFO)
void Queue::enqueue(Patient* p)
{
    // Create a node
    Node* newNode = new Node;
    newNode->patientPtr = p;
    newNode->next = nullptr;

    // Check if empty
    if (isEmpty())
    {
        front = newNode;
    }
    else
    {
        // otherwise link last node a new node
        rear->next = newNode;
    }

    // Always update rear to the new node
    rear = newNode;

    // Increase patient count
    counter++;
    cout << "Patient " << p->name << " added to Pharmacy Queue.\n";

}

// Dequeue Function from the front
Patient* Queue::dequeue()
{

    // variable to store removed patient
    Patient* p;

    if (isEmpty())
    {
        cout << "Error: the queue is empty." << endl;
        return nullptr; // We return NULL instead of exit(1) so the app doesn't crash
    }
    else
    {
        // Store the data
        p = front->patientPtr;

        // Save the next node
        Node* nextNode = front->next;

        // Delete the old front
        delete front;

        // Move front pointer
        front = nextNode;

        counter--;

    // If queue became empty, fix rear
        if (front == nullptr) {
            rear = nullptr;
        }
    }
    return p;
}

// Displays all patients waiting in pharmacy queue
void Queue::display() {
    if (isEmpty()) {
        cout << "Pharmacy line is empty.\n";
        return;
    }

    Node* temp = front;
    cout << "Pharmacy Line:\n";

    while (temp != nullptr) {
        cout << "Waiting: " << temp->patientPtr->name << endl;
        temp = temp->next;
    }
}
// Returns total number of patients in queue
int Queue ::getCounter()
{
    return counter;
}
