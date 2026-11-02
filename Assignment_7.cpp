#include <iostream>
#include <deque>
#include <string>
using namespace std;

struct Task {
    int id;
    string name;
    int priority;
};

class TaskScheduler {
private:
    deque<Task> tasks;
    int nextId = 1;

public:
    void addFront(string name, int priority) {
        Task t = {nextId++, name, priority};
        tasks.push_front(t);
        cout << "Task added at front.\n";
    }

    void addRear(string name, int priority) {
        Task t = {nextId++, name, priority};
        tasks.push_back(t);
        cout << "Task added at rear.\n";
    }

    void processTask() {
        if (tasks.empty()) {
            cout << "No tasks available.\n";
            return;
        }

        int highest = 0;

        for (int i = 1; i < tasks.size(); i++) {
            if (tasks[i].priority < tasks[highest].priority) {
                highest = i;
            }
        }

        Task t = tasks[highest];
        tasks.erase(tasks.begin() + highest);

        cout << "Processing Task ID: " << t.id << endl;
        cout << "Task Name: " << t.name << endl;
        cout << "Priority: " << t.priority << endl;
    }

    void displayTasks() {
        if (tasks.empty()) {
            cout << "No tasks available.\n";
            return;
        }

        cout << "\nPending Tasks:\n";

        for (const Task &t : tasks) {
            cout << "ID: " << t.id
                 << " | Name: " << t.name
                 << " | Priority: " << t.priority << endl;
        }
    }
};

int main() {
    TaskScheduler scheduler;

    int choice, priority;
    string name;

    do {
        cout << "\n--- Task Scheduler ---\n";
        cout << "1. Add Task at Front\n";
        cout << "2. Add Task at Rear\n";
        cout << "3. Process Highest-Priority Task\n";
        cout << "4. Display Tasks\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task name: ";
                cin >> ws;
                getline(cin, name);

                cout << "Enter priority (1 = Highest): ";
                cin >> priority;

                scheduler.addFront(name, priority);
                break;

            case 2:
                cout << "Enter task name: ";
                cin >> ws;
                getline(cin, name);

                cout << "Enter priority (1 = Highest): ";
                cin >> priority;

                scheduler.addRear(name, priority);
                break;

            case 3:
                scheduler.processTask();
                break;

            case 4:
                scheduler.displayTasks();
                break;

            case 5:
                cout << "Exiting Task Scheduler.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}