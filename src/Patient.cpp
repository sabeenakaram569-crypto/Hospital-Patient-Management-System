#include "Patient.h"
#include <iostream>
using namespace std;

// Constructor for Patient
Patient::Patient(int patient_Id, string patient_name, int patient_age, string patient_disease, int sev, int doc_Id)
{
    id = patient_Id;
    name = patient_name;
    age = patient_age;
    disease = patient_disease;
    severity = sev;
    doctorId = doc_Id;
    status = "waiting";
}

// Display Patients Information
void Patient::Display_Details()
{
    cout << "---------------------------------------------" << endl;
    cout << " ID       : " << id << endl;
    cout << " Name     : " << name << endl;
    cout << " Age      : " << age << endl;
    cout << " Disease  : " << disease << endl;
    cout << " Severity : " << severity;

    // If Severity is greater than 7 then its an emergency case
    if (severity >= 7)
    {
        // Print Emergency
        cout << "(EMERGENCY)";
    }
    else
    {
        // Else print Normal
        cout << "(Normal)";
    }
    cout << endl;
    cout << " Status: " << status << endl;
    cout << "---------------------------------------------" << endl;
}

// Get Patient's ID
int Patient::getId()
{
    return id;
}

// Get Patients's Severity
int Patient::getSeverity()
{
    return severity;
}

// Get Patient's Name
string Patient::getName()
{
    return name;
}
// Destructor
Patient::~Patient()
{
}
