#include <iostream>
using namespace std;

struct Node
{
    string patientID;
    Node* next;
};

void addPatient(Node*& head, string id)
{
    Node* newNode = new Node;

    newNode->patientID = id;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void displayPatients(Node* head)
{
    Node* temp = head;

    if (temp == NULL)
    {
        cout << "No patients are waiting." << endl;
        return;
    }

    cout << "Waiting Patients: ";

    while (temp != NULL)
    {
        cout << temp->patientID;

        if (temp->next != NULL)
        {
            cout << " -> ";
        }

        temp = temp->next;
    }

    cout << endl;
}

void servePatient(Node*& head)
{
    if (head == NULL)
    {
        cout << "No patients to serve." << endl;
        return;
    }

    Node* temp = head;

    cout << "Patient " << temp->patientID
         << " is being served." << endl;

    head = head->next;

    delete temp;
}

int main()
{
    Node* head = NULL;

    int n;
    string id;

    cout << "Enter number of patients: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Patient ID: ";
        cin >> id;

        addPatient(head, id);
    }

    cout << endl;
    displayPatients(head);

    servePatient(head);

    cout << "Updated Queue: ";

    if (head == NULL)
    {
        cout << "No patients waiting." << endl;
    }
    else
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->patientID;

            if (temp->next != NULL)
            {
                cout << " -> ";
            }

            temp = temp->next;
        }

        cout << endl;
    }

    return 0;
}
