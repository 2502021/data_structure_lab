#include <iostream>
#include <string>
using namespace std;

struct Order
{
    int orderID;
    string customerName;
    string foodItem;
    Order* next;
};

void addOrder(Order*& head, int id, string name, string food)
{
    Order* newOrder = new Order;

    newOrder->orderID = id;
    newOrder->customerName = name;
    newOrder->foodItem = food;
    newOrder->next = NULL;

    if (head == NULL)
    {
        head = newOrder;
    }
    else
    {
        Order* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newOrder;
    }

    cout << "Order added successfully." << endl;
}

void addUrgentOrder(Order*& head, int id, string name, string food)
{
    Order* newOrder = new Order;

    newOrder->orderID = id;
    newOrder->customerName = name;
    newOrder->foodItem = food;

    newOrder->next = head;
    head = newOrder;

    cout << "Urgent order added at the beginning." << endl;
}

void displayOrders(Order* head)
{
    if (head == NULL)
    {
        cout << "No pending orders." << endl;
        return;
    }

    Order* temp = head;

    cout << "\n===== Pending Orders =====" << endl;

    while (temp != NULL)
    {
        cout << "Order ID: " << temp->orderID << endl;
        cout << "Customer Name: " << temp->customerName << endl;
        cout << "Food Item: " << temp->foodItem << endl;
        cout << "-------------------------" << endl;

        temp = temp->next;
    }
}

void searchOrder(Order* head, int id)
{
    Order* temp = head;

    while (temp != NULL)
    {
        if (temp->orderID == id)
        {
            cout << "\nOrder Found!" << endl;
            cout << "Order ID: " << temp->orderID << endl;
            cout << "Customer Name: " << temp->customerName << endl;
            cout << "Food Item: " << temp->foodItem << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Order not found." << endl;
}

void removeOrder(Order*& head, int id)
{
    if (head == NULL)
    {
        cout << "Order not found." << endl;
        return;
    }

    if (head->orderID == id)
    {
        Order* temp = head;
        head = head->next;

        delete temp;

        cout << "Order delivered and removed successfully." << endl;
        return;
    }

    Order* temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->orderID == id)
        {
            Order* deleteOrder = temp->next;
            temp->next = temp->next->next;

            delete deleteOrder;

            cout << "Order delivered and removed successfully." << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Order not found." << endl;
}

int main()
{
    Order* head = NULL;


    addOrder(head, 101, "Ali", "Burger");
    addOrder(head, 102, "Ahmed", "Pizza");
    addOrder(head, 103, "Sara", "Biryani");

    displayOrders(head);

    cout << "\nSearching for Order ID 102:" << endl;
    searchOrder(head, 102);

    cout << "\nAdding urgent order:" << endl;
    addUrgentOrder(head, 100, "Hassan", "Shawarma");

    cout << "\nRemoving Order ID 102:" << endl;
    removeOrder(head, 102);

    cout << "\nUpdated Pending-Order List:" << endl;
    displayOrders(head);

    return 0;
}
