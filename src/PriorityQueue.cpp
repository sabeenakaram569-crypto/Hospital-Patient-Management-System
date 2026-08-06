#include "PriorityQueue.h"
#include <iostream>
using namespace std;

/*
 Constructor
 Initializes the priority queue as empty
*/
PriorityQueue::PriorityQueue()
{
    // no patient at start
    front = nullptr;
}

/*
 Destructor
 Removes all nodes from the queue to free memory
*/
PriorityQueue::~PriorityQueue()
{
    while (!isEmpty())
    {
        // remove each node one by one
        dequeue();
    }
}

/*
 Enqueue function
 Inserts a patient in the queue according to severity
 Higher severity = higher priority
*/
void PriorityQueue::enqueue(Patient* p)
{
    // if patient pointer is null, do nothing
    if (!p)
        return;

    // create a new node
    PQNode* newNode = new PQNode;
    newNode->patientPtr = p;
    newNode->next = nullptr;

    // if queue is empty, insert at front
    if (isEmpty())
    {
        front = newNode;
        return;
    }

    // if new patient has higher severity than front
    if (p->getSeverity() > front->patientPtr->getSeverity())
    {
        newNode->next = front;
        front = newNode;
        return;
    }

    // find correct position in the middle or end
    PQNode* cur = front;
    while (cur->next != nullptr)
    {
        // stop when correct priority position is found
        if (p->getSeverity() > cur->next->patientPtr->getSeverity())
        {
            break;
        }
        cur = cur->next;
    }
    // insert a new node at found position
    newNode->next = cur->next;
    cur->next = newNode;
}

/*
 Dequeue function
 Removes and returns the highest priority patient
*/
Patient* PriorityQueue::dequeue()
{
    // if queue is empty return Null
    if (isEmpty())
        return nullptr;

        // store front node
    PQNode* temp = front;
    Patient* p   = temp->patientPtr;

    // move front to next node
    front = front->next;
    // delete old node
    delete temp;
    // return patient
    return p;
}

// Checks whether Queue is empty or not
bool PriorityQueue::isEmpty()
{
    return front == nullptr;
}

// Display all patients in priority order
void PriorityQueue::display()
{
    if (isEmpty())
    {
        cout << "Priority Queue is empty.\n";
        return;
    }

    PQNode* cur = front;
    int position = 1;
    while (cur) {
        Patient* p = cur->patientPtr;
        // post-increment: prints number first, then increases
        cout << position++ << ". "
             << "ID: " << p->getId()
             << "   Name: " << p->getName()
             << "   Severity: " << p->getSeverity()<<endl;

        cur = cur->next;
    }
}

// Returns patient at front without removing
Patient* PriorityQueue::getPatient()
{
    return front->patientPtr;
}
