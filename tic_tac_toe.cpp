#include <iostream>
using namespace std;

// Function to draw the Tic-Tac-Toe board
void drawBoard(char board[3][3]) {
  cout << "-------------\n";
  for (int i = 0; i < 3; i++) {
    cout << "| ";
    for (int j = 0; j < 3; j++) {
      cout << board[i][j] << " | ";
    }
    cout << "\n-------------\n";
  }
}

// Function to check for a win
bool checkWin(char board[3][3], char player) {
  // Check rows, columns, and diagonals
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
      return true;
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
      return true;
  }
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
    cout << "Player " << player << " wins!\n";
  } else {
    if (checkDraw(board)) {
      cout << "It's a draw!\n";
    } else {
      cout << "Player " << (player == 'X' ? 'O' : 'X') << ", it's your turn.\n";
    }
  }
}

// Function to get the player's input
void getInput(int &row, int &col, char board[3][3]) {
  while (true) {
    cout << "Enter row (0-2) and column (0-2): ";
    cin >> row >> col;
    row = row < 0 ? 0 : (row > 2 ? 2 : row);
    col = col < 0 ? 0 : (col > 2 ? 2 : col);
    if (board[row][col] == ' ') {
      break;
    } else {
      cout << "Position already taken. Try again.\n";
    }
  }
}

// Function to check if a position is already taken
bool isPositionTaken(char board[3][3], int row, int col) {
  return board[row][col] != ' ';
}

int main() {
  // Initialize the board and players
  char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
  char player = 'X';

  cout << "Welcome to Tic-Tac-Toe!\n";

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
