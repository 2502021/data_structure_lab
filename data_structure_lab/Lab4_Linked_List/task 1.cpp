#include <iostream>
#include <string>
using namespace std;

struct Patient
{
    int patientID;
    string patientName;
    int patientAge;
    Patient* next;
};

void addPatient(Patient*& head, int id, string name, int age)
{
    Patient* newPatient = new Patient;

    newPatient->patientID = id;
    newPatient->patientName = name;
    newPatient->patientAge = age;
    newPatient->next = NULL;

    if (head == NULL)
    {
        head = newPatient;
    }
    else
    {
        Patient* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newPatient;
    }

    cout << "Patient added successfully.\n";
}

void addEmergencyPatient(Patient*& head, int id, string name, int age)
{
    Patient* newPatient = new Patient;

    newPatient->patientID = id;
    newPatient->patientName = name;
    newPatient->patientAge = age;

    newPatient->next = head;
    head = newPatient;

    cout << "Emergency patient added at the beginning.\n";
}


void searchPatient(Patient* head, int id)
{
    Patient* temp = head;

    while (temp != NULL)
    {
        if (temp->patientID == id)
        {
            cout << "\nPatient Found!\n";
            cout << "Patient ID: " << temp->patientID << endl;
            cout << "Patient Name: " << temp->patientName << endl;
            cout << "Patient Age: " << temp->patientAge << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Patient not found.\n";
}


void removePatient(Patient*& head, int id)
{
    if (head == NULL)
    {
        cout << "No patients in the waiting list.\n";
        return;
    }

    
    if (head->patientID == id)
    {
        Patient* temp = head;
        head = head->next;
        delete temp;

        cout << "Patient removed successfully.\n";
        return;
    }

    Patient* temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->patientID == id)
        {
            Patient* deleteNode = temp->next;
            temp->next = temp->next->next;

            delete deleteNode;

            cout << "Patient removed successfully.\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Patient not found.\n";
}


void displayPatients(Patient* head)
{
    if (head == NULL)
    {
        cout << "No patients in the waiting list.\n";
        return;
    }

    Patient* temp = head;

    cout << "\n===== Waiting Patients =====\n";

    while (temp != NULL)
    {
        cout << "Patient ID: " << temp->patientID << endl;
        cout << "Patient Name: " << temp->patientName << endl;
        cout << "Patient Age: " << temp->patientAge << endl;
        cout << "---------------------------\n";

        temp = temp->next;
    }
}

int main()
{
    Patient* head = NULL;

    addPatient(head, 101, "Ali", 25);
    addPatient(head, 102, "Ahmed", 40);
    addPatient(head, 103, "Sara", 30);

    addEmergencyPatient(head, 100, "Hassan", 55);

    displayPatients(head);

    cout << "\nSearching for Patient ID 102:\n";
    searchPatient(head, 102);

    cout << "\nRemoving Patient ID 102:\n";
    removePatient(head, 102);

    displayPatients(head);

    return 0;
}
