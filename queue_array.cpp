#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = -1;
Node* rear = -1;

void enqueue(int value) {
    Node* newNode = new Node{value, -1};

    if (rear == -1) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Inserted: " << value << "\n";
}

void dequeue() {
    if (front == -1) {
        cout << "Queue Underflow\n";
        return;
    }

    Node* temp = front;
    cout << "Deleted: " << temp->data << "\n";

    front = front->next;

    if (front == -1)
        rear = -1;

    delete temp;
}

void display() {
    if (front == -1) {
        cout << "Queue is Empty\n";
        return;
    }

    Node* temp = front;

    cout << "Queue: ";
    while (temp != -1) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "\n";
}

int main() {
    int choice, value;

    do {
        cout << "\n--- QUEUE MENU ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}