#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string orderID;
    Node* next;

    Node(string id) {
        orderID = id;
        next = NULL;
    }
};

class OrderStack {
private:
    Node* top;

public:
  
    OrderStack() {
        top = NULL;
    }

    void push(string id) {
        Node* newNode = new Node(id);
        newNode->next = top;
        top = newNode;
    }

   
    void pop() {
        if (top == NULL) {
            cout << "Stack is empty. No order to process!" << endl;
            return;
        }

        Node* temp = top;

        cout << "Processed order: "
             << temp->orderID << endl;

        top = top->next;
        delete temp;
    }

  
    void displayOrders() {
        if (top == NULL) {
            cout << "No orders available." << endl;
            return;
        }

        Node* current = top;

        cout << "Orders (TOP to Bottom):" << endl;

        while (current != NULL) {
            cout << current->orderID << endl;
            current = current->next;
        }
    }

 
    void displayTop() {
        if (top == NULL) {
            cout << "No current TOP order." << endl;
        } else {
            cout << "Current TOP order: "
                 << top->orderID << endl;
        }
    }


    bool isEmpty() {
        return top == NULL;
    }


    ~OrderStack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    OrderStack restaurant;

    restaurant.push("ORD-101");
    restaurant.push("ORD-102");
    restaurant.push("ORD-103");
    restaurant.push("ORD-104");

    restaurant.displayOrders();

    cout << endl;


    restaurant.pop();
    restaurant.pop();

    cout << endl;

    restaurant.displayTop();

    cout << endl;

    cout << "Remaining Orders:" << endl;
    restaurant.displayOrders();

    cout << endl;

    if (restaurant.isEmpty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack is not empty." << endl;
    }

    return 0;
}
