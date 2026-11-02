#include<iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    int choice;

    for(int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    for(int ele : arr)
    {
        cout << ele << " ";
    }

    do
    {
        cout << "\n ========= MENU =========";
        cout << "\n Update an element";
        cout << "\n Delete an element";
        cout << "\n Display the array";
        cout << "\n Exit";
        cout << "\n Enter your choice: ";

        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                int pos, val;
                cout << "\nEnter the position and value to update: ";
                cin >> pos;
                cin >> val;
                cout << endl;

                if(0 > pos || pos >= size)
                {
                    cout << " Invalid position";
                }
                else
                {
                    arr[pos] = val;

                    for(int ele : arr)
                    {
                        cout << ele << " ";
                    }
                }
                break;
            }

            case 2:
            {
                int del;
                cout << "\nEnter the position to delete: ";
                cin >> del;
                cout << endl;

                if(0 > del || del >= size)
                {
                    cout << " Invalid position";
                }
                else
                {
                    for(int i = del - 1; i < size - 1; i++)
                    {
                        arr[i] = arr[i + 1];
                    }

                    size--;

                    for(int ele : arr)
                    {
                        cout << ele << " ";
                    }
                }
                break;
            }

            case 3:
                for(int ele : arr)
                {
                    cout << ele << " ";
                }
                break;

            case 4:
                exit(0);

            default:
                cout << "\nInvalid choice";
            }

    } while(choice != 4);
}