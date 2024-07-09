#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;
const double FINE_PER_DAY = 0.5; // Fine per day in dollars

struct Book {
    string title;
    string author;
    string ISBN;
    bool isAvailable;
    time_t dueDate; // Stores the due date for checked out books
};

vector<Book> books;

void printLine() {
    cout << "========================================" << endl;
}

void printHeader() {
    printLine();
    cout << "|           BOOK MANAGEMENT SYSTEM     |" << endl;
    printLine();
}

void printMenu() {
    cout << "| 1. Add Book                          |" << endl;
    cout << "| 2. Search Book                       |" << endl;
    cout << "| 3. Checkout Book                     |" << endl;
    cout << "| 4. Return Book                       |" << endl;
    cout << "| 5. Calculate Fine                    |" << endl;
    cout << "| 6. Exit                              |" << endl;
    printLine();
}

void addBook() {
    Book newBook;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, newBook.title);
    cout << "Enter book author: ";
    getline(cin, newBook.author);
    cout << "Enter book ISBN: ";
    getline(cin, newBook.ISBN);
    newBook.isAvailable = true;
    books.push_back(newBook);
    cout << "Book added successfully!" << endl;
    printLine();
}

void searchBook() {
    string keyword;
    cout << "Enter title, author, or ISBN to search: ";
    cin.ignore();
    getline(cin, keyword);

    bool found = false;
    for (const auto& book : books) {
        if (book.title == keyword || book.author == keyword || book.ISBN == keyword) {
            cout << "Book found: " << endl;
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "ISBN: " << book.ISBN << endl;
            cout << "Status: " << (book.isAvailable ? "Available" : "Checked Out") << endl;
            printLine();
            found = true;
        }
    }
    if (!found) {
        cout << "No book found with the given information." << endl;
        printLine();
    }
}

void checkoutBook() {
    string isbn;
    cout << "Enter ISBN of the book to checkout: ";
    cin.ignore();
    getline(cin, isbn);

    bool found = false;
    for (auto& book : books) {
        if (book.ISBN == isbn) {
            if (book.isAvailable) {
                book.isAvailable = false;
                cout << "Enter due date (yyyy-mm-dd): ";
                tm tm = {};
                string dueDate;
                getline(cin, dueDate);
                istringstream ss(dueDate);
                ss >> get_time(&tm, "%Y-%m-%d");
                book.dueDate = mktime(&tm);
                cout << "Book checked out successfully!" << endl;
            } else {
                cout << "Book is already checked out." << endl;
            }
            printLine();
            found = true;
        }
    }
    if (!found) {
        cout << "No book found with the given ISBN." << endl;
        printLine();
    }
}

void returnBook() {
    string isbn;
    cout << "Enter ISBN of the book to return: ";
    cin.ignore();
    getline(cin, isbn);

    bool found = false;
    for (auto& book : books) {
        if (book.ISBN == isbn) {
            if (!book.isAvailable) {
                book.isAvailable = true;
                cout << "Book returned successfully!" << endl;
            } else {
                cout << "Book is already available." << endl;
            }
            printLine();
            found = true;
        }
    }
    if (!found) {
        cout << "No book found with the given ISBN." << endl;
        printLine();
    }
}

void calculateFine() {
    string isbn;
    cout << "Enter ISBN of the book to calculate fine: ";
    cin.ignore();
    getline(cin, isbn);

    bool found = false;
    for (auto& book : books) {
        if (book.ISBN == isbn) {
            if (!book.isAvailable) {
                time_t now = time(0);
                double diff = difftime(now, book.dueDate) / (60 * 60 * 24);
                if (diff > 0) {
                    double fine = diff * FINE_PER_DAY;
                    cout << "The fine for the overdue book is: $" << fine << endl;
                } else {
                    cout << "No fine. Book is not overdue." << endl;
                }
            } else {
                cout << "Book is already returned." << endl;
            }
            printLine();
            found = true;
        }
    }
    if (!found) {
        cout << "No book found with the given ISBN." << endl;
        printLine();
    }
}

int main() {
    int choice;
    do {
        printHeader();
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                checkoutBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                calculateFine();
                break;
            case 6:
                cout << "Thank you for using the Book Management System. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                printLine();
                break;
        }
    } while (choice != 6);

    return 0;
}
