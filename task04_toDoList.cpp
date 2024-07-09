#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void printLine(char ch, int length) {
    for (int i = 0; i < length; ++i) {
        cout << ch;
    }
    cout << endl;
}

void printHeader(const string& header) {
    int width = 40;
    printLine('=', width);
    cout << setw((width + header.length()) / 2) << header << endl;
    printLine('=', width);
}

void addTask(vector<string>& tasks) {
    string task;
    cout << "Enter the task: ";
    cin.ignore();
    getline(cin, task);
    tasks.push_back(task);
    cout << "\nTask added successfully!" << endl;
}

void viewTasks(const vector<string>& tasks) {
    printHeader("Your Tasks");
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
    } else {
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }
    printLine('=', 40);
}

void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to delete." << endl;
        return;
    }

    int taskNumber;
    cout << "Enter the task number to delete: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number." << endl;
    } else {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "\nTask deleted successfully!" << endl;
    }
}

void displayMenu() {
    printHeader("To-Do List Manager");
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Delete Task" << endl;
    cout << "4. Exit" << endl;
    printLine('=', 40);
    cout << "Enter your choice: ";
}

int main() {
    vector<string> tasks;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
