#include <iostream>
#include <string>
using namespace std;

int main() {
    string name[100], mobile[100];
    int n;

    cout << "Enter number of friends: ";
    cin >> n;

    // Input friends
    for (int i = 0; i < n; i++) {
        cout << "Enter name: ";
        cin >> name[i];

        cout << "Enter mobile number: ";
        cin >> mobile[i];
    }

    // Sort friends by name
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (name[i] > name[j]) {
                swap(name[i], name[j]);
                swap(mobile[i], mobile[j]);
            }
        }
    }

    // Display phone book
    cout << "\nPhone Book:\n";

    for (int i = 0; i < n; i++) {
        cout << name[i] << " -- " << mobile[i] << endl;
    }

    // Search friend
    string key;
    cout << "\nEnter name to search: ";
    cin >> key;

    // Sentinel
    string lastName = name[n - 1];
    string lastMobile = mobile[n - 1];

    name[n - 1] = key;

    int i = 0;

    while (name[i] != key) {
        i++;
    }

    // Check whether friend exists
    if (i < n - 1 || lastName == key) {
        if (i == n - 1) {
            cout << "Friend found!\n";
            cout << "Mobile: " << lastMobile << endl;
        } else {
            cout << "Friend found!\n";
            cout << "Mobile: " << mobile[i] << endl;
        }

        // Restore last name
        name[n - 1] = lastName;
        mobile[n - 1] = lastMobile;
    }
    else {
        // Restore last friend
        name[n - 1] = lastName;
        mobile[n - 1] = lastMobile;

        cout << "Friend not found.\n";

        // Insert new friend
        cout << "Enter mobile number: ";
        string newMobile;
        cin >> newMobile;

        i = n - 1;

        while (i >= 0 && name[i] > key) {
            name[i + 1] = name[i];
            mobile[i + 1] = mobile[i];
            i--;
        }

        name[i + 1] = key;
        mobile[i + 1] = newMobile;

        n++;

        cout << "Friend inserted successfully.\n";
    }

    // Display updated phone book
    cout << "\nUpdated Phone Book:\n";

    for (int i = 0; i < n; i++) {
        cout << name[i] << " -- " << mobile[i] << endl;
    }

    return 0;
}
