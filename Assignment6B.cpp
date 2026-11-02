#include <iostream>
#include <stack>
using namespace std;

class Queue {
private:
    stack<int> s1, s2;

public:
    void enqueue(int value) {
        s1.push(value);
        cout << value << " inserted into queue.\n";
    }

    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty.\n";
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << "Deleted element: " << s2.top() << endl;
        s2.pop();
    }

    void display() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue: ";

        stack<int> temp = s2;
        stack<int> temp2 = s1;
        stack<int> reversed;

        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }

        while (!temp2.empty()) {
            reversed.push(temp2.top());
            temp2.pop();
        }

        while (!reversed.empty()) {
            cout << reversed.top() << " ";
            reversed.pop();
        }

        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n--- Queue Using Two Stacks ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
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
                cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}