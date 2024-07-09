#include <iostream>
#include <iomanip>
using namespace std;
void printLine() {
    cout << "========================================" << endl;
}

void printHeader() {
    printLine();
    cout << "|       SIMPLE CALCULATOR              |" << endl;
    printLine();
}

void printMenu() {
    cout << "| Options:                             |" << endl;
    cout << "| 1. Addition                          |" << endl;
    cout << "| 2. Subtraction                       |" << endl;
    cout << "| 3. Multiplication                    |" << endl;
    cout << "| 4. Division                          |" << endl;
    printLine();
}

int main() {
    double num1, num2;
    int choice;
    char cont = 'y';

    while (cont == 'y' || cont == 'Y') {
        printHeader();
        printMenu();

        cout << "Enter your choice (1-4): ";
        cin >> choice;

        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter second number: ";
        cin >> num2;

        printLine();
        cout << "| Result: ";

        switch (choice) {
            case 1:
                cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
                break;
            case 2:
                cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
                break;
            case 3:
                cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
                break;
            case 4:
                if (num2 != 0) {
                    cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
                } else {
                    cout << "Error: Division by zero!" << endl;
                }
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }

        printLine();
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> cont;
    }

    cout << "Thank you for using the calculator. Goodbye!" << endl;
    return 0;
}
