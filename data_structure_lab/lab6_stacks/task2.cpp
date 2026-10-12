#include <iostream>
#include <string>
using namespace std;

class ActionStack {
private:
    string actions[10];
    int top;

public:
   
    ActionStack() {
        top = -1;
    }

    
    void push(string action) {
        if (top == 9) {
            cout << "Stack Overflow!" << endl;
        } else {
            actions[++top] = action;
        }
    }

    
    void pop() {
        if (top == -1) {
            cout << "No actions to undo!" << endl;
        } else {
            cout << "Undo action: " << actions[top] << endl;
            top--;
        }
    }

   
    void displayActions() {
        if (top == -1) {
            cout << "No actions available." << endl;
            return;
        }

        cout << "Actions (TOP to Bottom):" << endl;

        for (int i = top; i >= 0; i--) {
            cout << actions[i] << endl;
        }
    }

    void displayTop() {
        if (top == -1) {
            cout << "No current action." << endl;
        } else {
            cout << "Current TOP action: "
                 << actions[top] << endl;
        }
    }
};

int main() {
    ActionStack editor;

    editor.push("Type \"Hello\"");
    editor.push("Type \"World\"");
    editor.push("Add \"!\"");
    editor.push("Delete \"!\"");

    editor.displayActions();

    cout << endl;
    editor.pop();
    editor.pop();

    cout << endl;
    editor.displayTop();

    cout << endl;
    cout << "Remaining Actions:" << endl;
    editor.displayActions();

    return 0;
}
