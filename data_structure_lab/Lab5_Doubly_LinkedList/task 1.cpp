#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string website;
    Node* prev;
    Node* next;

    Node(string name) {
        website = name;
        prev = NULL;
        next = NULL;
    }
};

class BrowserHistory {
private:
    Node* head;
    Node* tail;

public:
    BrowserHistory() {
        head = NULL;
        tail = NULL;
    }

    void addWebsite(string name) {
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

        cout << "Browser History (First -> Last):" << endl;

        while (temp != NULL) {
            cout << temp->website << endl;
            temp = temp->next;
        }
    }

    void displayReverse() {
        Node* temp = tail;

        cout << "\nBrowser History (Last -> First):" << endl;

        while (temp != NULL) {
            cout << temp->website << endl;
            temp = temp->prev;
        }
    }
};

int main() {
    BrowserHistory history;

    history.addWebsite("www.google.com");
    history.addWebsite("www.youtube.com");
    history.addWebsite("www.github.com");
    history.addWebsite("www.stackoverflow.com");
    history.addWebsite("www.wikipedia.org");

    history.displayForward();
    history.displayReverse();

    return 0;
}
