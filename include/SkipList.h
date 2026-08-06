#ifndef SKIPLIST_H
#define SKIPLIST_H

#include "Patient.h"
#include <iostream>

using namespace std;

/* Skip Node represents a single Node in skip list
    Each Node stores:
    - A pointer to a Patient Object
    - Multiple Forward Pointers for different levels
*/
class SkipNode
{
public:
    // Pointer to Patient Data
    Patient* data;
    // Forward Pointers for 3 levels of skip List
    SkipNode* forward[3];

    // Constructor to initialize node with patient data
    SkipNode(Patient* p);
};

/* Skip List implements the Skip List Data Structure
    It allows:
    - Fast Insertion
    - Fast Deletion
    - Fast Searching
*/
class SkipList
{
    public:
        // Constructor to initialize Skip List
        SkipList();

        // Function to insert new patient into the skip List
        void insert(Patient* p);

        // Function to search Patient by ID
        Patient* search(int id);

        // Function to remove patient from the data after he or she is dischraged
        void remove(int id);

        // Display all patient's stored in skip List
        void display();

        // Destructor
        virtual ~SkipList();

    protected:

    private:
        // Head node of skip List
        SkipNode* head;
        // Maximum Levels Allowed in Skip List
        int maxLevel;
};

#endif // SKIPLIST_H
