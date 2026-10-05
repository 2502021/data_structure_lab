#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string image;
    Node* prev;
    Node* next;

    Node(string name) {
        image = name;
        prev = NULL;
        next = NULL;
    }
};

class ImageGallery {
private:
    Node* head;
    Node* tail;

public:
    ImageGallery() {
        head = NULL;
        tail = NULL;
    }

    void addImage(string name) {
        Node* newNode = new Node(name);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayForward() {
        Node* temp = head;

        cout << "Images (First -> Last):" << endl;

        while (temp != NULL) {
            cout << temp->image << endl;
            temp = temp->next;
        }
    }

    void displayBackward() {
        Node* temp = tail;

        cout << "\nImages (Last -> First):" << endl;

        while (temp != NULL) {
            cout << temp->image << endl;
            temp = temp->prev;
        }
    }
};

int main() {
    ImageGallery gallery;

    gallery.addImage("Beach.jpg");
    gallery.addImage("Mountains.jpg");
    gallery.addImage("Sunset.jpg");
    gallery.addImage("Nature.jpg");
    gallery.addImage("City.jpg");

    gallery.displayForward();
    gallery.displayBackward();

    return 0;
}
