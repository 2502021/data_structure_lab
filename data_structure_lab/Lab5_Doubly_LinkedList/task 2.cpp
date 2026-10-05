#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string player;
    Node* next;

    Node(string name) {
        player = name;
        next = NULL;
    }
};

class Game {
private:
    Node* head;

public:
    Game() {
        head = NULL;
    }

    void addPlayer(string name) {
        Node* newNode = new Node(name);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        }
        else {
            Node* temp = head;

            while (temp->next != head) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
        }
    }

    void displayTurns() {
        if (head == NULL) {
            return;
        }

        Node* temp = head;

        cout << "Player Turns:" << endl;

        do {
            cout << temp->player << "'s turn" << endl;
            temp = temp->next;
        } while (temp != head);

        cout << "\nAfter the last player, turn returns to: "
             << head->player << endl;
    }
};

int main() {
    Game game;

    game.addPlayer("Ali");
    game.addPlayer("Ahmed");
    game.addPlayer("Sara");
    game.addPlayer("Hassan");
    game.addPlayer("Ayesha");

    game.displayTurns();

    return 0;
}
