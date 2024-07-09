#include <iostream>
#include <iomanip>

void printLine() {
    std::cout << "========================================" << std::endl;
}

void printHeader() {
    printLine();
    std::cout << "|       SIMPLE CALCULATOR              |" << std::endl;
    printLine();
}

void printMenu() {
    std::cout << "| Options:                             |" << std::endl;
    std::cout << "| 1. Addition                          |" << std::endl;
    std::cout << "| 2. Subtraction                       |" << std::endl;
    std::cout << "| 3. Multiplication                    |" << std::endl;
    std::cout << "| 4. Division                          |" << std::endl;
    printLine();
}

int main() {
    double num1, num2;
    int choice;
    char cont = 'y';

    while (cont == 'y' || cont == 'Y') {
        printHeader();
        printMenu();

        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;

        std::cout << "Enter first number: ";
        std::cin >> num1;

        std::cout << "Enter second number: ";
        std::cin >> num2;

        printLine();
        std::cout << "| Result: ";

        switch (choice) {
            case 1:
                std::cout << num1 << " + " << num2 << " = " << num1 + num2 << std::endl;
                break;
            case 2:
                std::cout << num1 << " - " << num2 << " = " << num1 - num2 << std::endl;
                break;
            case 3:
                std::cout << num1 << " * " << num2 << " = " << num1 * num2 << std::endl;
                break;
            case 4:
                if (num2 != 0) {
                    std::cout << num1 << " / " << num2 << " = " << num1 / num2 << std::endl;
                } else {
                    std::cout << "Error: Division by zero!" << std::endl;
                }
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
        }

        printLine();
        std::cout << "Do you want to perform another calculation? (y/n): ";
        std::cin >> cont;
    }

    std::cout << "Thank you for using the calculator. Goodbye!" << std::endl;
    return 0;
}
