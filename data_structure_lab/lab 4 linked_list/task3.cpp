#include <iostream>
using namespace std;

struct Node
{
    string productID;
    Node* next;
};

void addProduct(Node*& head, string id)
{
    Node* newNode = new Node;

    newNode->productID = id;
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

void displayCart(Node* head)
{
    if (head == NULL)
    {
   cout << "Shopping Cart is empty." << endl;
    return;
    }

    Node* temp = head;

    cout << "Shopping Cart: ";

    while (temp != NULL)
    {
   cout << temp->productID;
    if (temp->next != NULL)
    {
   cout << " -> ";
    }
 temp = temp->next;
    }

    cout << endl;
}

void removeProduct(Node*& head, string id)
{
    if (head == NULL)
    {
    cout << "Shopping Cart is empty." << endl;
   return;
    }

    if (head->productID == id)
    {
   Node* temp = head;
    head = head->next;
  delete temp;
   return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
    if (temp->next->productID == id)
   {
   Node* deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
    return;
    }
  temp = temp->next;
    }

    cout << "Product " << id << " not found." << endl;
}

int main()
{
    Node* head = NULL;

    int n;
    string id;

    cout << "Enter number of products: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
  cout << "Enter Product ID: ";
   cin >> id;
 addProduct(head, id);
    }

    cout << endl;
    displayCart(head);

   cout << "Remove Product: ";
    cin >> id;

    removeProduct(head, id);

    cout << "Updated Cart: ";
    displayCart(head);
    return 0;
}
