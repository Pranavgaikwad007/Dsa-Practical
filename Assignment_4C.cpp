#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string song;
    Node* next;
};

Node* head = NULL;       // First song
Node* current = NULL;    // Song currently playing

// Add a song to the end of the playlist
void addSong(string name)
{
    Node* newNode = new Node();
    newNode->song = name;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        current = head;
    }
    else
    {
        Node* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    cout << "Added: " << name << endl;
}

// Show all songs in the playlist
void showPlaylist()
{
    if (head == NULL)
    {
        cout << "Playlist is empty." << endl;
        return;
    }

    Node* temp = head;

    cout << "Playlist:" << endl;

    do
    {
        cout << " - " << temp->song;

        if (temp == current)
        {
            cout << " (playing)";
        }

        cout << endl;
        temp = temp->next;

    } while (temp != head);
}

// Play the next song
void playNext()
{
    if (current == NULL)
    {
        cout << "Playlist is empty." << endl;
        return;
    }

    current = current->next;
    cout << "Now playing: " << current->song << endl;
}

// Delete a song by name
void deleteSong(string name)
{
    if (head == NULL)
    {
        cout << "Playlist is empty." << endl;
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    do
    {
        if (temp->song == name)
        {
            break;
        }

        prev = temp;
        temp = temp->next;

    } while (temp != head);

    if (temp->song != name)
    {
        cout << "Song not found." << endl;
        return;
    }

    // If only one song exists
    if (temp == head && temp->next == head)
    {
        head = NULL;
        current = NULL;
    }
    else
    {
        // If deleting the first song
        if (temp == head)
        {
            Node* last = head;

            while (last->next != head)
            {
                last = last->next;
            }

            head = head->next;
            last->next = head;
        }
        else
        {
            prev->next = temp->next;
        }

        // Update current song if it is deleted
        if (current == temp)
        {
            current = temp->next;
        }
    }

    delete temp;
    cout << "Deleted: " << name << endl;
}

int main()
{
    int choice;
    string name;

    do
    {
        cout << "\n--- MUSIC PLAYLIST ---\n";
        cout << "1. Add  2. Show  3. Play Next  4. Delete  0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Song name: ";
            cin >> name;
            addSong(name);
        }
        else if (choice == 2)
        {
            showPlaylist();
        }
        else if (choice == 3)
        {
            playNext();
        }
        else if (choice == 4)
        {
            cout << "Song to delete: ";
            cin >> name;
            deleteSong(name);
        }
        else if (choice != 0)
        {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 0);

    cout << "Exiting Music Playlist." << endl;

    return 0;
}