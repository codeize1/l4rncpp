Tic-Tac-Toe
============

A simple Tic-Tac-Toe game for two players.

Features
--------

* **Player vs Player**: Two players can play against each other on a 3x3 board.
* **Check for Win**: The program checks for a win after each move.
* **Check for Draw**: The program checks for a draw if no player has won after 9 moves.
* **Input Validation**: The program validates the input to ensure that the entered row and column values are within the valid range (0-2).

Building and Running
-------------------

1. Save the code to a file named `tic_tac_toe.cpp`.
2. Compile the program using the following command: `g++ tic_tac_toe.cpp -o tic_tac_toe`
3. Run the program using the following command: `./tic_tac_toe`

Gameplay
--------

* Each player takes turns entering a row and column value to place their mark on the board.
* The first player to get three of their marks in a row (horizontally, vertically, or diagonally) wins the game.
* If all 9 squares on the board are filled and no player has won, the game is a draw.

Functions
---------

* `drawBoard`: Draws the Tic-Tac-Toe board.
* `checkWin`: Checks if a player has won the game.
* `checkDraw`: Checks if the game is a draw.
* `printResult`: Prints the game result.
* `getInput`: Gets the player's input and validates it.
* `isPositionTaken`: Checks if a position on the board is already taken.

Code Structure
--------------

* The `main` function initializes the board and players, and starts the game loop.
* The game loop prints the game result, gets the player's input, makes the move, checks for a win or draw, and switches to the other player.

## Conclusion

This program provides a simple implementation of the classic Tic-Tac-Toe game. It includes input validation, win and draw detection, and a user-friendly interface. It can be extended to include additional features such as AI opponents or different board sizes.
