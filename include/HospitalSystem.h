#ifndef HOSPITALSYSTEM_H
#define HOSPITALSYSTEM_H

#include <iostream>
#include <vector>
#include <string>

#include "Patient.h"
#include "Doctor.h"
#include "SkipList.h"
#include "Queue.h"

using namespace std;

/*
 HospitalSystem Class
 Handles the overall hospital work flow
*/
class HospitalSystem
{
public:
    // Constructor
    HospitalSystem();

    // Function to register new patient
    void registerPatient();
    // Doctor sees patient
    void doctorVisit();
    // Patient gets medicine
    void pharmacyVisit();

    // Admin Features

   // Search patient details by ID in SkipList
    void searchPatientRecord();
    // Display all doctor queues and waiting patients
    void showDoctorQueues();
    // Show all patients stored in the SkipList
    void showAllPatients();

private:
    // Stores all patient records
    SkipList records;

     // FIFO queue for patients waiting at pharmacy
    Queue pharmacyLine;

    // List of doctors with their own priority queues
    vector<Doctor> doctors;

};

#endif
