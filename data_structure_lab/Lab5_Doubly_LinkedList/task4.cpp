#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string song;
    Node* next;

    Node(string name) {
        song = name;
        next = this;
    }
};

class Playlist {
private:
    Node* head;

public:
    Playlist() {
        head = NULL;
    }

    void addSong(string name) {
        Node* newNode = new Node(name);

        if (head == NULL) {
            head = newNode;
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

    void displayOnce() {
        if (head == NULL) {
            return;
        }

        Node* temp = head;

        cout << "Playlist:" << endl;

        do {
            cout << temp->song << endl;
            temp = temp->next;
        } while (temp != head);
    }

    void playTwoRounds() {
        if (head == NULL) {
            return;
        }

        Node* temp = head;

        cout << "\nPlaying Playlist for 2 Complete Rounds:" << endl;

        for (int i = 1; i <= 10; i++) {
            cout << "Playing: " << temp->song << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Playlist playlist;

    playlist.addSong("Perfect");
    playlist.addSong("Shape of You");
    playlist.addSong("Believer");
    playlist.addSong("Faded");
    playlist.addSong("Let Me Down Slowly");

    playlist.displayOnce();
    playlist.playTwoRounds();

    return 0;
}
