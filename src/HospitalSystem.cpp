#include "HospitalSystem.h"
#include <chrono>
#include <iostream>
using namespace std;

// Constructor: Initialize the Hospital
HospitalSystem::HospitalSystem()
{
    // List of Doctors
    doctors.push_back(Doctor(1, "Dr.Ali", "Cardiology"));
    doctors.push_back(Doctor(2, "Dr.Sara", "Neurology"));
    doctors.push_back(Doctor(3, "Dr.Haider", "General"));
    doctors.push_back(Doctor(4, "Dr.Ahmed", "Orthopedics"));
    doctors.push_back(Doctor(5, "Dr.Fatima", "Dermatologist"));
    doctors.push_back(Doctor(6, "Dr.Kamran", "ENT"));
    doctors.push_back(Doctor(7, "Dr.Ayesha", "Pediatrics"));
    doctors.push_back(Doctor(8, "Dr.Bilal", "Oncology"));
    doctors.push_back(Doctor(9, "Dr.Raza", "Urology"));
    doctors.push_back(Doctor(10, "Dr.Imran", "Psychiatry"));
    doctors.push_back(Doctor(11, "Dr.Maria", "Radiology"));
    doctors.push_back(Doctor(12, "Dr.Rabia", "Nutritionist"));
}

// --- REGISTER PATIENT ---
// Adds a patient to the system and assigns a doctor
void HospitalSystem::registerPatient()
{
    int id, age, severity, docChoice;
    string name, disease;

    cout << "\n--- NEW PATIENT REGISTRATION ---\n";

    // Check ID first
    cout << "Enter ID: ";
    cin >> id;
    if(cin.fail() || id < 0)
    {
        cout<<"Error you wrote string or negative number!";
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }
    // checks if patient already exists in skip list
    if (records.search(id) != NULL)
    {
        cout << "Error: Patient ID already exists!\n";
        return;
    }
    // Get other patient details
    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Age: ";
    cin >> age;
    if(cin.fail() || age < 0 )
    {
        cout<<"Error you wrote string or negative number!";
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    cout << "Enter Disease: ";
    cin >> disease;

    cout << "Enter Severity (1-10): ";
    cin >> severity;
    if(cin.fail() || severity>10)
    {
        cout<<"You wrote severity greater than 10 or a string";
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }


    // Show all available Doctors
    cout << "\nAvailable Doctors:\n";
    for (int i = 0; i < doctors.size(); i++)
    {
        cout << doctors[i].doctorID << ". " << doctors[i].name
             << " (" << doctors[i].specialization << ")\n";
    }

    cout << "Assign to Doctor ID: ";
    cin >> docChoice;

    // Create a Patient object
    Patient* newPatient = new Patient(id, name, age, disease, severity, docChoice);

    // Add to Skip List
    records.insert(newPatient);

    for (int i = 0; i < doctors.size(); i++)
    {
        if (doctors[i].doctorID == docChoice)
        {
            doctors[i].addPatient(newPatient);
            return;
        }
    }

    cout << "Error: Doctor ID not found.\n";
}

// --- DOCTOR TREATMENT ---
void HospitalSystem::doctorVisit()
{
    int docID;
    cout << "\n--- DOCTOR PORTAL ---\n";
    cout << "Enter Doctor ID: ";
    cin >> docID;

    // Search for the doctor
    for (int i = 0; i < doctors.size(); i++)
        {
        if (doctors[i].doctorID == docID)
        {

            // Check if queue is empty
            if (doctors[i].waitingRoom.isEmpty())
            {
                cout << "No patients waiting.\n";
                return;
            }

            // Get the patient pointer
            Patient* p = doctors[i].waitingRoom.getPatient();

            // Treat the patient
            doctors[i].treatPatient();

            // Send to Pharmacy
            p->status = "Pharmacy";
            pharmacyLine.enqueue(p);
            cout << "Patient sent to Pharmacy.\n";
             cout<<"No of patients in Queue : "<<pharmacyLine.getCounter()<<endl;
            return;
        }
    }
    cout << "Doctor not found.\n";
}

// --- PHARMACY ---
void HospitalSystem::pharmacyVisit() {
    cout << "\n--- PHARMACY ---\n";

    if (pharmacyLine.isEmpty()) {
        cout << "No one is waiting.\n";
        return;
    }

    // Serve the patient
    Patient* p = pharmacyLine.dequeue();

    // Update status to finished
    p->status = "Discharged";

    cout << "Medicine given to: " << p->name << endl;
    cout << "Patient Discharged.\n";
    // Removes the patient from Skip List
    records.remove(p->id);
}

// --- SEARCH FEATURE ---
void HospitalSystem::searchPatientRecord() {
    int id;
    cout << "Enter Patient ID: ";
    cin >> id;
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    // Measure search time
    auto t1 = high_resolution_clock::now();
    Patient* p = records.search(id);
    auto t2 = high_resolution_clock::now();
    auto ms_int = duration_cast<milliseconds>(t2 - t1);
    duration<double, std::milli> ms_double = t2 - t1;

    if (p != NULL)
    {
        p->Display_Details();
    } else
    {
        cout << "Patient with ID " << id << " not found.\n";
    }

    // --- PRINT ALGORITHM PERFORMANCE ---
    cout << "\n======================================\n";
    cout << "          ALGORITHM PERFORMANCE       \n";
    cout << "======================================\n";
    cout << " Operation: Skip List Search O(log n) \n";
    cout << " Time: " << ms_double.count() << "ms\n";
    cout << "======================================\n";
}

// --- SHOW ALL DOCTOR QUEUES ---
void HospitalSystem::showDoctorQueues()
{
    for (int i = 0; i < doctors.size(); i++)
    {
        doctors[i].displayQueue();
        cout << endl;
    }
}

// --- SHOW ALL PATIENTS (SKIP LIST) ---
void HospitalSystem::showAllPatients()
{
    records.display();
}
