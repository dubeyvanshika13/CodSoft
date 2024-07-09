#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE];
char currentPlayer = 'X';

void initializeBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    cout << "    0     1     2" << endl;
    cout << "  +-----+-----+-----+" << endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int line = 0; line < 3; ++line) {
            cout << i << " ";
            for (int j = 0; j < SIZE; ++j) {
                if (line == 1) {
                    cout << "|  " << board[i][j] << "  ";
                } else {
                    cout << "|     ";
                }
            }
            cout << "|" << endl;
        }
        cout << "  +-----+-----+-----+" << endl;
    }
}

bool makeMove(int row, int col) {
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) return true;
    }
    // Check diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) return true;
    return false;
}

bool checkDraw() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    char playAgain;
    do {
        initializeBoard();
        bool gameWon = false;
        bool gameDraw = false;
        while (!gameWon && !gameDraw) {
            displayBoard();
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;
            if (makeMove(row, col)) {
                gameWon = checkWin();
                if (gameWon) {
                    displayBoard();
                    cout << "Player " << currentPlayer << " wins!" << endl;
                } else {
                    gameDraw = checkDraw();
                    if (gameDraw) {
                        displayBoard();
                        cout << "The game is a draw!" << endl;
                    } else {
                        switchPlayer();
                    }
                }
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        }
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    
    return 0;
}
