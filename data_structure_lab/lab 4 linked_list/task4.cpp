#include <iostream>
using namespace std;

struct Node
{
    int rollNumber;
    Node* next;
};

void addStudent(Node*& head, int rollNumber)
{
    Node* newNode = new Node;

    newNode->rollNumber = rollNumber;
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

void insertBeginning(Node*& head, int rollNumber)
{
    Node* newNode = new Node;

    newNode->rollNumber = rollNumber;
    newNode->next = head;

    head = newNode;
}

void searchStudent(Node* head, int rollNumber)
{
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->rollNumber == rollNumber)
        {
            cout << "Student Found" << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Student Not Found" << endl;
}

void displayStudents(Node* head)
{
    if (head == NULL)
    {
        cout << "No students enrolled." << endl;
        return;
    }

    Node* temp = head;

    cout << "Enrolled Students: ";

    while (temp != NULL)
    {
        cout << temp->rollNumber;

        if (temp->next != NULL)
        {
            cout << " -> ";
        }

        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    Node* head = NULL;

    int n;
    int rollNumber;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Roll Number: ";
        cin >> rollNumber;

        addStudent(head, rollNumber);
    }

    cout << endl;
    displayStudents(head);

    cout << "Enter new student Roll Number to insert at beginning: ";
    cin >> rollNumber;

    insertBeginning(head, rollNumber);

    cout << "After insertion: ";
    displayStudents(head);

    cout << "Enter Roll Number to search: ";
    cin >> rollNumber;

    searchStudent(head, rollNumber);

    return 0;
}
