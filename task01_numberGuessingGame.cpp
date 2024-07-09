#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void printLine() {
    cout << "========================================" << std::endl;
}

void printHeader() {
    printLine();
    cout << "|       GUESS THE NUMBER GAME          |" << std::endl;
    printLine();
}

void printInstructions() {
    cout << "| Instructions:                        |" << std::endl;
    cout << "| I have selected a random number      |" << std::endl;
    cout << "| between 1 and 100. Try to guess it!  |" << std::endl;
    printLine();
}

int main() {
    srand(std::time(0));
    int randomNumber = std::rand() % 100 + 1;
    int guess;
    int attempts = 0;

    printHeader();
    printInstructions();

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > randomNumber) {
            cout << "| Your guess is too high. Try again!  |" << std::endl;
        } else if (guess < randomNumber) {
            cout << "| Your guess is too low. Try again!   |" << std::endl;
        } else {
            cout << "| Congratulations! You guessed it!    |" << std::endl;
            cout << "| It took you " << attempts << " attempts.      |" << std::endl;
        }
        printLine();
    } while (guess != randomNumber);

    cout << "Thank you for playing. Goodbye!" << std::endl;
    return 0;
}
