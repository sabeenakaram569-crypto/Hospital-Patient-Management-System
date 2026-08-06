#ifndef PATIENT_H
#define PATIENT_H
#include <string>

using namespace std;

// Patient Class with attributes and methods
class Patient
{
    public:
        // Name of Patient
        string name;
        // ID of patient
        int id;
        // Age of Patient
        int age;
        // Disease that Patient is suffering from
        string disease;
        // How severe the Condition is
        int severity;
        // Status of Patient(Waiting, Being Treated or discharged)
        string status;
        // ID of Doctor (Which Doctor is being assigned to the patient)
        int doctorId;

        // Patient Constructor
        Patient(int patient_Id, string patient_name, int patient_age, string patient_disease, int sev, int doctor_Id);

        // Function to display patient's details
        void Display_Details();

        // Destructor
        virtual ~Patient();

        // Getters to get Patient's ID, Severity and Name
        int getId();
        int getSeverity();
        string getName();


    protected:

    private:
};

#endif // PATIENT_H
