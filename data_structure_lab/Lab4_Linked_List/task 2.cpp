#include <iostream>
#include <string>
using namespace std;

struct Student
{
    int rollNumber;
    string studentName;
    string attendanceStatus;
    Student* next;
};

void addStudent(Student*& head, int roll, string name, string status)
{
    Student* newStudent = new Student;

    newStudent->rollNumber = roll;
    newStudent->studentName = name;
    newStudent->attendanceStatus = status;
    newStudent->next = NULL;

    if (head == NULL)
    {
        head = newStudent;
    }
    else
    {
        Student* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newStudent;
    }

    cout << "Student added successfully." << endl;
}

void searchStudent(Student* head, int roll)
{
    Student* temp = head;

    while (temp != NULL)
    {
        if (temp->rollNumber == roll)
        {
            cout << "\nStudent Found!" << endl;
            cout << "Roll Number: " << temp->rollNumber << endl;
            cout << "Student Name: " << temp->studentName << endl;
            cout << "Attendance Status: " << temp->attendanceStatus << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Student not found." << endl;
}


void deleteStudent(Student*& head, int roll)
{
    if (head == NULL)
    {
        cout << "Student not found." << endl;
        return;
    }

    if (head->rollNumber == roll)
    {
        Student* temp = head;
        head = head->next;

        delete temp;

        cout << "Student deleted successfully." << endl;
        return;
    }

    Student* temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->rollNumber == roll)
        {
            Student* deleteNode = temp->next;
            temp->next = temp->next->next;

            delete deleteNode;

            cout << "Student deleted successfully." << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Student not found." << endl;
}

void displayStudents(Student* head)
{
    if (head == NULL)
    {
        cout << "Attendance list is empty." << endl;
        return;
    }

    Student* temp = head;

    cout << "\n===== Attendance List =====" << endl;

    while (temp != NULL)
    {
        cout << "Roll Number: " << temp->rollNumber << endl;
        cout << "Student Name: " << temp->studentName << endl;
        cout << "Attendance Status: " << temp->attendanceStatus << endl;
        cout << "--------------------------" << endl;

        temp = temp->next;
    }
}

void countPresentStudents(Student* head)
{
    int count = 0;
    Student* temp = head;

    while (temp != NULL)
    {
        if (temp->attendanceStatus == "Present")
        {
            count++;
        }

        temp = temp->next;
    }

    cout << "Total students present: " << count << endl;
}

int main()
{
    Student* head = NULL;

    addStudent(head, 101, "Ali", "Present");
    addStudent(head, 102, "Ahmed", "Absent");
    addStudent(head, 103, "Sara", "Present");
    addStudent(head, 104, "Ayesha", "Present");

    displayStudents(head);

    cout << "\nSearching for Roll Number 103:" << endl;
    searchStudent(head, 103);

    cout << "\nSearching for Roll Number 110:" << endl;
    searchStudent(head, 110);

    cout << "\n";
    countPresentStudents(head);

    cout << "\nDeleting Roll Number 102:" << endl;
    deleteStudent(head, 102);

    cout << "\nFinal Attendance List:" << endl;
    displayStudents(head);

    return 0;
}
