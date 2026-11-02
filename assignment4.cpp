#include <iostream>
#include <string>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    int seatNo;
    string name;
    Node* next;
    Node* prev;
};

// Head pointer
Node* head = NULL;


// Function to reserve a seat
void reserveSeat(int seatNo, string name) {

    Node* newNode = new Node;
    newNode->seatNo = seatNo;
    newNode->name = name;
    newNode->next = NULL;
    newNode->prev = NULL;

    // If list is empty
    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* temp = head;

        // Check if seat is already reserved
        while (temp->next != NULL) {

            if (temp->seatNo == seatNo) {
                cout << "Seat already reserved.\n";
                delete newNode;
                return;
            }

            temp = temp->next;
        }

        // Check last node also
        if (temp->seatNo == seatNo) {
            cout << "Seat already reserved.\n";
            delete newNode;
            return;
        }

        // Add new node at the end
        temp->next = newNode;
        newNode->prev = temp;
    }

    cout << "Seat reserved successfully.\n";
}


// Function to display all reservations
void displayReservations() {

    if (head == NULL) {
        cout << "No reservations available.\n";
        return;
    }

    Node* temp = head;

    cout << "\n--- TRAIN RESERVATIONS ---\n";

    while (temp != NULL) {

        cout << "Seat No: " << temp->seatNo << endl;
        cout << "Passenger: " << temp->name << endl;
        cout << "------------------\n";

        temp = temp->next;
    }
}


// Function to search passenger
void searchPassenger(string name) {

    Node* temp = head;

    while (temp != NULL) {

        if (temp->name == name) {
            cout << "Passenger found!\n";
            cout << "Seat No: " << temp->seatNo << endl;
            cout << "Name: " << temp->name << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Passenger not found.\n";
}


// Function to cancel reservation
void cancelReservation(int seatNo) {

    Node* temp = head;

    // Search for the seat
    while (temp != NULL && temp->seatNo != seatNo) {
        temp = temp->next;
    }

    // If seat is not found
    if (temp == NULL) {
        cout << "Reservation not found.\n";
        return;
    }

    // If node is not the first node
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    // If node is not the last node
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    // Delete the node
    delete temp;

    cout << "Reservation cancelled successfully.\n";
}


// Main function
int main() {

    int choice, seatNo;
    string name;

    do {

        cout << "\n--- TRAIN RESERVATION SYSTEM ---\n";
        cout << "1. Reserve Seat\n";
        cout << "2. Display Reservations\n";
        cout << "3. Search Passenger\n";
        cout << "4. Cancel Reservation\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter seat number: ";
                cin >> seatNo;

                cout << "Enter passenger name: ";
                cin >> name;

                reserveSeat(seatNo, name);
                break;


            case 2:
                displayReservations();
                break;


            case 3:
                cout << "Enter passenger name to search: ";
                cin >> name;

                searchPassenger(name);
                break;


            case 4:
                cout << "Enter seat number to cancel: ";
                cin >> seatNo;

                cancelReservation(seatNo);
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