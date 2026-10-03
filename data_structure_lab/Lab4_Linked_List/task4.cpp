#include <iostream>
#include <string>
using namespace std;

struct Course
{
    string courseCode;
    string courseName;
    int creditHours;
    Course* next;
};

void addAtBeginning(Course*& head, string code, string name, int hours)
{
    Course* newCourse = new Course;

    newCourse->courseCode = code;
    newCourse->courseName = name;
    newCourse->creditHours = hours;
    newCourse->next = head;

    head = newCourse;
}

void addAtEnd(Course*& head, string code, string name, int hours)
{
    Course* newCourse = new Course;

    newCourse->courseCode = code;
    newCourse->courseName = name;
    newCourse->creditHours = hours;
    newCourse->next = NULL;

    if (head == NULL)
    {
        head = newCourse;
        return;
    }

    Course* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newCourse;
}

void searchCourse(Course* head, string code)
{
    Course* temp = head;

    while (temp != NULL)
    {
        if (temp->courseCode == code)
        {
            cout << "\nCourse Found!" << endl;
            cout << "Course Code: " << temp->courseCode << endl;
            cout << "Course Name: " << temp->courseName << endl;
            cout << "Credit Hours: " << temp->creditHours << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Course not found." << endl;
}

void deleteCourse(Course*& head, string code)
{
    if (head == NULL)
    {
        cout << "Course not found." << endl;
        return;
    }

    if (head->courseCode == code)
    {
        Course* temp = head;
        head = head->next;
        delete temp;

        cout << "Course deleted successfully." << endl;
        return;
    }

    Course* temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->courseCode == code)
        {
            Course* deleteCourse = temp->next;
            temp->next = temp->next->next;
            delete deleteCourse;

            cout << "Course deleted successfully." << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Course not found." << endl;
}

void displayCourses(Course* head)
{
    if (head == NULL)
    {
        cout << "No courses available." << endl;
        return;
    }

    Course* temp = head;

    while (temp != NULL)
    {
        cout << "Course Code: " << temp->courseCode << endl;
        cout << "Course Name: " << temp->courseName << endl;
        cout << "Credit Hours: " << temp->creditHours << endl;
        cout << "------------------------" << endl;

        temp = temp->next;
    }
}

int countCourses(Course* head)
{
    int count = 0;
    Course* temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void concatenate(Course*& head1, Course* head2)
{
    if (head1 == NULL)
    {
        head1 = head2;
        return;
    }

    Course* temp = head1;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = head2;
}

void menu(Course*& head)
{
    int choice;
    string code;
    string name;
    int hours;

    do
    {
        cout << "\n===== Course Management =====" << endl;
        cout << "1. Add Course at Beginning" << endl;
        cout << "2. Add Course at End" << endl;
        cout << "3. Search Course" << endl;
        cout << "4. Delete Course" << endl;
        cout << "5. Display All Courses" << endl;
        cout << "6. Count Total Courses" << endl;
        cout << "7. Concatenate Another Course List" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Course Code: ";
            cin >> code;

            cout << "Enter Course Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Credit Hours: ";
            cin >> hours;

            addAtBeginning(head, code, name, hours);
            cout << "Course added successfully." << endl;
            break;

        case 2:
            cout << "Enter Course Code: ";
            cin >> code;

            cout << "Enter Course Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Credit Hours: ";
            cin >> hours;

            addAtEnd(head, code, name, hours);
            cout << "Course added successfully." << endl;
            break;

        case 3:
            cout << "Enter Course Code to search: ";
            cin >> code;

            searchCourse(head, code);
            break;

        case 4:
            cout << "Enter Course Code to delete: ";
            cin >> code;

            deleteCourse(head, code);
            break;

        case 5:
            cout << "\n===== All Courses =====" << endl;
            displayCourses(head);
            break;

        case 6:
            cout << "Total Courses: " << countCourses(head) << endl;
            break;

        case 7:
        {
            Course* anotherList = NULL;

            addAtEnd(anotherList, "SE101", "Software Engineering", 3);
            addAtEnd(anotherList, "WEB201", "Web Development", 3);
            addAtEnd(anotherList, "DB301", "Database Systems", 3);

            concatenate(head, anotherList);

            cout << "Another course list concatenated successfully." << endl;
            break;
        }

        case 8:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 8);
}

int main()
{
    Course* morningCourses = NULL;

    addAtEnd(morningCourses, "CS101", "Programming Fundamentals", 3);
    addAtEnd(morningCourses, "AI201", "Artificial Intelligence", 3);
    addAtEnd(morningCourses, "DS301", "Data Structures", 3);

    menu(morningCourses);

    return 0;
}
