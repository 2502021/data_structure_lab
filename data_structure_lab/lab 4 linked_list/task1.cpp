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

void displayStudents(Node* head)
{
    Node* temp = head;

    cout << "Registered Students: ";

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

int main()
{
    Node* head = NULL;

    int n, rollNumber;
    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
   cout << "Enter Roll Number: ";
    cin >> rollNumber;
 addStudent(head, rollNumber);
    }

    displayStudents(head);

    cout << "Enter Roll Number to Search: ";
    cin >> rollNumber;

    searchStudent(head, rollNumber);

    return 0;
}
