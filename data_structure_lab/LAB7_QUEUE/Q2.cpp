#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
private:
    int arr[SIZE];
    int front, rear, count;

public:
    CircularQueue() {
   front = 0;
   rear = -1;
    count = 0;
    }

    void enqueue(int packet) {
   if (count == SIZE) {
  cout << "Queue Overflow! Buffer is full.\n";
  return;
      }

 rear = (rear + 1) % SIZE;
  arr[rear] = packet;
   count++;
        
    cout << "Packet " << packet << " added to the queue.\n";
    }

    void dequeue() {
    if (count == 0) {
   cout << "Queue Underflow! No packets to transmit.\n";
    return;
  }

   cout << "Packet " << arr[front] << " transmitted.\n";

  front = (front + 1) % SIZE;
   count--;

  if (count == 0) {
    front = 0;
    rear = -1;
     }
    }

    void display() {
    if (count == 0) {
    cout << "No packets waiting for transmission.\n";
    return;
    }

 cout << "Packets waiting for transmission: ";
 
  for (int i = 0; i < count; i++) {
   cout << arr[(front + i) % SIZE] << " ";
 }
        
   cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, packet;

    do {
    cout << "\n--- Network Packet Management ---\n";
   cout << "1. Insert Packet\n";
   cout << "2. Transmit Packet\n";
    cout << "3. Display Packets\n";
   cout << "4. Exit\n";
   cout << "Enter your choice: ";
 cin >> choice;
 
  switch (choice) {
  case 1:
    cout << "Enter packet ID: ";
    cin >> packet;
    q.enqueue(packet);
   break;

  case 2:
    q.dequeue();
   break;
   
  case 3:
    q.display();
    break;

  case 4:
    cout << "Exiting program.\n";
   break;

   default:
    cout << "Invalid choice!\n";
    }

    } while (choice != 4);

    return 0;
}
