#include <iostream>

using namespace std;

class Task {
public:
    string task;
    bool completed;

    Task() : task(""), completed(false) {}
};

class TodoListManager {
private:
    static const int MAX_TASKS = 100;
    Task tasks[MAX_TASKS];
    int taskCount;

public:
    TodoListManager() : taskCount(0) {}

    void addTask(const string& task) {
        if (taskCount < MAX_TASKS) {
            tasks[taskCount].task = task;
            tasks[taskCount].completed = false;
            ++taskCount;
            cout << "Task added successfully!\n";
        } else {
            cout << "Task limit reached. Cannot add more tasks.\n";
        }
    }

    void viewTasks() {
        if (taskCount == 0) {
            cout << "No tasks available.\n";
        } else {
            cout << "Tasks:\n";
            for (int i = 0; i < taskCount; ++i) {
                string status = tasks[i].completed ? "Completed" : "Pending";
                cout << i + 1 << ". " << tasks[i].task << " - " << status << "\n";
            }
        }
    }

    void markCompleted(int taskIndex) {
        if (taskIndex >= 1 && taskIndex <= taskCount) {
            tasks[taskIndex - 1].completed = true;
            cout << "Task marked as completed!\n";
        } else {
            cout << "Invalid task index.\n";
        }
    }

    void removeTask(int taskIndex) {
        if (taskIndex >= 1 && taskIndex <= taskCount) {
            for (int i = taskIndex - 1; i < taskCount - 1; ++i) {
                tasks[i] = tasks[i + 1];
            }
            --taskCount;
            cout << "Task removed successfully!\n";
        } else {
            cout << "Invalid task index.\n";
        }
    }
};

int main() {
    TodoListManager manager;

    while (true) {
        cout << "\nOptions:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";

        int choice;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string task;
                cout << "Enter the task: ";
                cin.ignore(); // Clear the newline character from the buffer
                getline(cin, task);
                manager.addTask(task);
                break;
            }
            case 2:
                manager.viewTasks();
                break;
            case 3: {
                int taskIndex;
                cout << "Enter the task index to mark as completed: ";
                cin >> taskIndex;
                manager.markCompleted(taskIndex);
                break;
            }
            case 4: {
                int taskIndex;
                cout << "Enter the task index to remove: ";
                cin >> taskIndex;
                manager.removeTask(taskIndex);
                break;
            }
            case 5:
                cout << "Exiting the to-do list manager. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    }
}