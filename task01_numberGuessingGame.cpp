#include <iostream>
#include <cstdlib>
#include <ctime>

void printLine() {
    std::cout << "========================================" << std::endl;
}

void printHeader() {
    printLine();
    std::cout << "|       GUESS THE NUMBER GAME          |" << std::endl;
    printLine();
}

void printInstructions() {
    std::cout << "| Instructions:                        |" << std::endl;
    std::cout << "| I have selected a random number      |" << std::endl;
    std::cout << "| between 1 and 100. Try to guess it!  |" << std::endl;
    printLine();
}

int main() {
    std::srand(std::time(0));
    int randomNumber = std::rand() % 100 + 1;
    int guess;
    int attempts = 0;

    printHeader();
    printInstructions();

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess > randomNumber) {
            std::cout << "| Your guess is too high. Try again!  |" << std::endl;
        } else if (guess < randomNumber) {
            std::cout << "| Your guess is too low. Try again!   |" << std::endl;
        } else {
            std::cout << "| Congratulations! You guessed it!    |" << std::endl;
            std::cout << "| It took you " << attempts << " attempts.      |" << std::endl;
        }
        printLine();
    } while (guess != randomNumber);

    std::cout << "Thank you for playing. Goodbye!" << std::endl;
    return 0;
}
