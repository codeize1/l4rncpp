#include <iostream>

// Function to draw the Tic-Tac-Toe board
void drawBoard(char board[3][3]) {
    std::cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        std::cout << "| ";
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j] << " | ";
        }
        std::cout << "\n-------------\n";
    }
}

// Function to check for a win
bool checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// Function to check for a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to print the game result
void printResult(char board[3][3], char player) {
    drawBoard(board);
    if (checkWin(board, player)) {
        std::cout << "Player " << player << " wins!\n";
    } else if (checkDraw(board)) {
        std::cout << "It's a draw!\n";
    } else {
        std::cout << "Player " << ((player == 'X') ? 'O' : 'X') << ", it's your turn.\n";
    }
}

// Function to get the player's input
void getInput(int &row, int &col, char board[3][3]) {
    while (true) {
        std::cout << "Enter row (0-2) and column (0-2): ";
        std::cin >> row >> col;
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            break;
        } else {
            std::cout << "Invalid position or position already taken. Try again.\n";
        }
    }
}

int main() {
    // Initialize the board and players
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char player = 'X';

    std::cout << "Welcome to Tic-Tac-Toe!\n";

    // Game loop
    for (int turn = 0; turn < 9; turn++) {
        // Print the game result
        printResult(board, player);

        // Get the player's input
        int row, col;
        getInput(row, col, board);

        // Make the move
        board[row][col] = player;

        // Check for a win after making a move
        if (checkWin(board, player)) {
            break;
        }

        // Switch to the other player
        player = (player == 'X') ? 'O' : 'X';
    }

    // End of the game
    printResult(board, player);

    return 0;
}
