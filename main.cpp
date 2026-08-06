#include <iostream>

// for _getch() to get single key input without Enter
#include <conio.h>
#include "HospitalSystem.h"

// SkipList for fast searching (O(Log N))
#include "SkipList.h"
using namespace std;

int main()
{
    // Hospital System Object to manage patients, doctors, queue and records
    HospitalSystem hospital;

    // SkipList Object for efficient searching
    SkipList sk;

    // Infinite loop to keep showing the menu until user exits
    while (true)
        {
        // Display the Main Menu
        cout << "\n======================================\n";
        cout << "   HOSPITAL MANAGEMENT SYSTEM    \n";
        cout << "======================================\n";
        cout << "1. Register New Patient \n";
        cout << "2. Doctor: Treat Next Patient\n";
        cout << "3. Pharmacy: Dispense Medicine\n";
        cout << "4. Search Patient Record\n";
        cout << "5. View Doctor Waiting Lists\n";
        cout << "6. View Database\n";
        cout << "7. Exit\n";
        cout << "Enter Choice: ";

        // Takes users choice using _getch() (Reads a single character without pressing Enter)
        char choice = _getch();

            // Option 1: Register a new patient
            if(choice == '1')
            {
                hospital.registerPatient();
            }
            // Option 2: Doctor treats Patient
            else if(choice == '2')
            {
                hospital.doctorVisit();
            }
            // Option 3: Pharmacy gives medicine and discharges the patient
            else if(choice == '3')
            {
                hospital.pharmacyVisit();
            }
            // Option 4: Search for Patient Record by ID
            else if(choice == '4')
            {
                hospital.searchPatientRecord();
            }
            // Option 5: Show waiting Queue for all Doctors
            else if(choice == '5')
            {
                hospital.showDoctorQueues();
            }
            // Option 6: Show complete patient database
            else if(choice == '6')
            {
                hospital.showAllPatients();
            }
            // Option 7: Exit the program
            else if(choice == '7')
            {
                cout << "Exiting System...\n";
                return 0;
            }
            // If user enters any other key
            else
            {
                cout << "Invalid choice!\n";
            }
    }
    return 0;
}
