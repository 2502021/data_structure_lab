
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Patient {
    string id;
    int priority;
};

struct ComparePriority {
    bool operator()(Patient a, Patient b) {
        return a.priority > b.priority;
    }
};

int main() {
    priority_queue<Patient, vector<Patient>, ComparePriority> pq;

    int choice;

    do {
    cout << "\n--- Hospital Emergency Department ---\n";
    cout << "1. Add Patient\n";
    cout << "2. Treat Highest Priority Patient\n";
    cout << "3. Display Waiting Patients\n";
    cout << "4. Exit\n";
   cout << "Enter your choice: ";
   cin >> choice;

    if (choice == 1) {
    Patient p;

   cout << "Enter Patient ID: ";
  cin >> p.id;

    cout << "Enter Priority (1 = Highest): ";
    cin >> p.priority;
    pq.push(p);

   cout << "Patient added successfully.\n";
  }
  else if (choice == 2) {
  if (pq.empty()) {
    cout << "No patients waiting.\n";
    } else {
    Patient p = pq.top();
  cout << "Treating Patient: " << p.id
  << " (Priority: " << p.priority << ")\n";

    pq.pop();
    }
    }
  else if (choice == 3) {
   if (pq.empty()) {
   cout << "No patients waiting.\n";
   } else {
    priority_queue<Patient, vector<Patient>,
    ComparePriority> temp = pq;

  cout << "\nWaiting Patients:\n";
  while (!temp.empty()) {
    Patient p = temp.top();
 cout << "Patient ID: " << p.id<< ", Priority: " << p.priority << '\n';
    temp.pop();
   }
    }
   }
    else if (choice == 4) {
    cout << "Exiting program.\n";
  }
      else {
    cout << "Invalid choice. Try again.\n";
  }

    } while (choice != 4);

    return 0;
}
