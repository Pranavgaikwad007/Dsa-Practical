#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name, number;
    Node *next;
};

Node *head = NULL;

void add()
{
    Node *n = new Node;

    cout << "Name: ";
    cin >> n->name;

    cout << "Number: ";
    cin >> n->number;

    n->next = NULL;

    if (head == NULL)
    {
        head = n;
    }
    else
    {
        Node *t = head;

        while (t->next != NULL)
        {
            t = t->next;
        }

        t->next = n;
    }
}

void display()
{
    Node *t = head;

    if (t == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    while (t != NULL)
    {
        cout << t->name << " " << t->number << endl;
        t = t->next;
    }
}

void deleteCall()
{
    string num;

    cout << "Enter number: ";
    cin >> num;

    Node *t = head;
    Node *p = NULL;

    while (t != NULL && t->number != num)
    {
        p = t;
        t = t->next;
    }

    if (t == NULL)
    {
        cout << "Not found\n";
        return;
    }

    if (p == NULL)
    {
        head = head->next;
    }
    else
    {
        p->next = t->next;
    }

    delete t;
    cout << "Record deleted successfully\n";
}

int main()
{
    int ch;

    do
    {
        cout << "\n1. Add  2. Display  3. Delete  4. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1:
                add();
                break;

            case 2:
                display();
                break;

            case 3:
                deleteCall();
                break;

            case 4:
                cout << "Exiting program\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (ch != 4);

    return 0;
}