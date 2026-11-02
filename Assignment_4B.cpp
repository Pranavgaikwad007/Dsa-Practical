#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string passenger;
    int seat;
    Node* next;
    Node* prev;
};

Node* head = NULL;  // First booking
Node* tail = NULL;  // Last booking

// Book a seat (add to the end)
void bookSeat(string passenger, int seat)
{
    Node* newNode = new Node();

    newNode->passenger = passenger;
    newNode->seat = seat;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    cout << "Booked seat " << seat << " for " << passenger << endl;
}

// Show bookings from first to last
void showForward()
{
    if (head == NULL)
    {
        cout << "No bookings yet." << endl;
        return;
    }

    Node* temp = head;

    cout << "Bookings (forward):" << endl;

    while (temp != NULL)
    {
        cout << "Seat " << temp->seat << " - "
             << temp->passenger << endl;
        temp = temp->next;
    }
}

// Show bookings from last to first
void showReverse()
{
    if (tail == NULL)
    {
        cout << "No bookings yet." << endl;
        return;
    }

    Node* temp = tail;

    cout << "Bookings (reverse):" << endl;

    while (temp != NULL)
    {
        cout << "Seat " << temp->seat << " - "
             << temp->passenger << endl;
        temp = temp->prev;
    }
}

// Cancel a booking by seat number
void cancelSeat(int seat)
{
    if (head == NULL)
    {
        cout << "No bookings yet." << endl;
        return;
    }

    Node* temp = head;

    while (temp != NULL && temp->seat != seat)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Seat not found." << endl;
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;

    cout << "Cancelled seat " << seat
         << " (" << temp->passenger << ")" << endl;

    delete temp;
}

int main()
{
    int choice, seat;
    string passenger;

    do
    {
        cout << "\n--- TRAIN RESERVATION ---\n";
        cout << "1. Book  2. Show Forward  3. Show Reverse"
             << "  4. Cancel  0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Passenger name: ";
            cin >> passenger;

            cout << "Seat number: ";
            cin >> seat;

            bookSeat(passenger, seat);
        }
        else if (choice == 2)
        {
            showForward();
        }
        else if (choice == 3)
        {
            showReverse();
        }
        else if (choice == 4)
        {
            cout << "Seat number to cancel: ";
            cin >> seat;

            cancelSeat(seat);
        }
        else if (choice != 0)
        {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    cout << "Exiting Train Reservation System." << endl;

    return 0;
}
