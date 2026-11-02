#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

void enqueue(int value) {
    Node* newNode = new Node{value, nullptr};

    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Inserted: " << value << "\n";
}

void dequeue() {
    if (front == nullptr) {
        cout << "Queue Underflow\n";
        return;
    }

    Node* temp = front;
    cout << "Deleted: " << temp->data << "\n";

    front = front->next;

    if (front == nullptr)
        rear = nullptr;

    delete temp;
}

void display() {
    if (front == nullptr){
        cout << "Queue is Empty\n";
        return;
    }

    Node* temp = front;

    cout << "Queue: ";
    while (temp != nullptr) {
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
