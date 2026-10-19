#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> passengers;
    int choice, id;

    do {
    cout << "\n--- Train Station Passenger Management ---\n";
   cout << "1. Insert at Front\n";
  cout << "2. Insert at Rear\n";
    cout << "3. Remove from Front\n";
   cout << "4. Remove from Rear\n";
  cout << "5. Display All Requests\n";
   cout << "6. Exit\n";
   cout << "Enter your choice: ";
 cin >> choice;

  switch (choice) {
    case 1:
cout << "Enter passenger request ID: ";
    cin >> id;
  passengers.push_front(id);
    cout << "Request inserted at front.\n";
  break;

  case 2:
  cout << "Enter passenger request ID: ";
   cin >> id;
    passengers.push_back(id);
  cout << "Request inserted at rear.\n";
  break;

    case 3:
     if (passengers.empty()) {
    cout << "Deque is empty. Nothing to remove.\n";
     } else {
   cout << "Removed from front: " << passengers.front() << '\n';
passengers.pop_front();
      }
  break;
  case 4:
    if (passengers.empty()) {
    cout << "Deque is empty. Nothing to remove.\n";
    } else {
   cout << "Removed from rear: " << passengers.back() << '\n';
    passengers.pop_back();
    }
   break;

   case 5:
    if (passengers.empty()) {
    cout << "No passenger requests available.\n";
    } else {
  cout << "Front -> ";
for (int i = 0; i < passengers.size(); i++) {
    cout << passengers[i] << " ";
}
cout << "<- Rear\n";
    }
    break;

    case 6:
   cout << "Exiting program.\n";
    break;
 default:
   cout << "Invalid choice. Try again.\n";
    }

    } while (choice != 6);

    return 0;
}
