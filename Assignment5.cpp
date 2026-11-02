#include <iostream>
using namespace std;

struct Node {
    string name;
    string number;
    Node* next;
};

Node* head = NULL;

void addCall(string name, string number) {
    Node* newNode = new Node;
    newNode->name = name;
    newNode->number = number;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Call added successfully.\n";
}

void displayCalls() {
    if (head == NULL) {
        cout << "No call logs available.\n";
        return;
    }

    Node* temp = head;

    cout << "\nCall Logs:\n";

    while (temp != NULL) {
        cout << "Name: " << temp->name << endl;
        cout << "Number: " << temp->number << endl;
        cout << "-------------------\n";

        temp = temp->next;
    }
}

void searchCall(string number) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->number == number) {
            cout << "Call found!\n";
            cout << "Name: " << temp->name << endl;
            cout << "Number: " << temp->number << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Call not found.\n";
}

void deleteCall(string number) {
    if (head == NULL) {
        cout << "No call logs available.\n";
        return;
    }

    if (head->number == number) {
        Node* temp = head;
        head = head->next;

        delete temp;

        cout << "Call deleted successfully.\n";
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        if (temp->next->number == number) {
            Node* deleteNode = temp->next;
            temp->next = temp->next->next;

            delete deleteNode;

            cout << "Call deleted successfully.\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Call not found.\n";
}

int main() {
    int choice;
    string name, number;

    do {
        cout << "\n--- CALL LOG MANAGEMENT ---\n";
        cout << "1. Add Call\n";
        cout << "2. Display Calls\n";
        cout << "3. Search Call\n";
        cout << "4. Delete Call\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter name: ";
                cin >> name;

                cout << "Enter phone number: ";
                cin >> number;

                addCall(name, number);
                break;

            case 2:
                displayCalls();
                break;

            case 3:
                cout << "Enter phone number to search: ";
                cin >> number;

                searchCall(number);
                break;

            case 4:
                cout << "Enter phone number to delete: ";
                cin >> number;

                deleteCall(number);
                break;

            case 5:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}