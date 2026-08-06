#include "SkipList.h"
#include <iostream>
// for random number generator
#include <cstdlib>


using namespace std;

// Skip Node constructor
// Initialize a node with patient data and set all forward pointers to nullptr
SkipNode::SkipNode(Patient* p)
{
    // Store Patient pointer
    data = p;
    // Initialize all forward pointers to null
    for(int i = 0; i < 3; i++)
    {
        forward[i] = nullptr;
    }
}

// Skip List Constructor
// Initialize the skip List with Maximum Level and head node with no patient data
SkipList::SkipList()
{

    maxLevel = 2;

    // Create Head Node
    head = new SkipNode(nullptr);
}

/* Generates a Random Level for a new node
    Probability-Bases
    - level increases while rand()%2 == 0
*/

int getRandomLevel()
{
    int level = 0;
    // Allow levels 0, 1, 2. Stop if we hit 2.
    while(rand() % 2 == 0 && level < 2)
    {
        level++;
    }
    return level;
}

// Inserts a new patient into the skip List
// Maintains sorted order by Patient ID
void SkipList::insert(Patient* p)
{

    // Array to store previous nodes at each level
    SkipNode* prevNode[3];
    SkipNode* current = head;

    // Traverse from Highest to Lowest Level
    for(int i = maxLevel; i >= 0; i--)
    {
        // Move forward while next node ID is smaller
        while(current->forward[i] != NULL && current->forward[i]->data->id < p->id)
        {
            current = current->forward[i];
        }
        prevNode[i] = current;
    }

    // Generate random level for new Node
    int level = getRandomLevel();
    // Create a new Skip Node
    SkipNode* newNode = new SkipNode(p);


    // Insert Node at all valid levels
    for(int i = 0; i <= level; i++)
    {
        newNode->forward[i] = prevNode[i]->forward[i];
        prevNode[i]->forward[i] = newNode;
    }
    cout << "Patient Inserted Successfully: " << p->name << endl;
}
// Searches for Patient by ID
// Returns Patient's pointer if found else returns null
Patient* SkipList::search(int id)
{
    SkipNode* current = head;

    // Traverse from top to bottom level
    for(int i = maxLevel; i >= 0; i--)
    {
        while(current->forward[i] != NULL && current->forward[i]->data->id < id)
        {
            current = current->forward[i];
        }
    }
    // Move to next Node at level 0
    current = current->forward[0];

    // Check if Patient ID matches
    if(current != NULL && current->data->id == id)
    {
        return current->data;
    }

    return NULL;
}

// Remove a patient from Skip List using ID
void SkipList::remove(int id) {
    SkipNode* prevNode[3];
    SkipNode* current = head;

    // Find previous Nodes at all levels
    for(int i = maxLevel; i >= 0; i--)
    {
        while(current->forward[i] != nullptr && current->forward[i]->data->id < id)
        {
            current = current->forward[i];
        }
        prevNode[i] = current;
    }

    // Move to target Node
    current = current->forward[0];

    // If node is found
    if(current != nullptr && current->data->id == id)
        {
            // Update pointer at all levels
        for(int i = 0; i <= maxLevel; i++)
        {
            if(prevNode[i]->forward[i] != current)
                continue;
            prevNode[i]->forward[i] = current->forward[i];
        }
        // Free Patient memory
        delete current->data;
        // Free Node memory
        delete current;
    }
}

// Display all Patient record
void SkipList::display()
{
    cout << "\n---- Patient Record ----" << endl;

    SkipNode* current = head->forward[0];

    // If Skip List is empty
    if (current == nullptr) {
        cout << "(Database is empty)" << endl;
        return;
    }

    // Traverse and display patient data
    while(current != NULL)
    {
        cout << "ID: " << current->data->id
             << " | Name: " << current->data->name
             << " | Status: " << current->data->status << endl;
        current = current->forward[0];
    }
    cout << "-------------------------------------------\n";
}

// Destructor
SkipList::~SkipList()
{
}
