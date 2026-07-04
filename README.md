# Mini Game Project — Tic Tac Toe (C++)

A console-based Tic Tac Toe game written in standard C++, built to
demonstrate core programming concepts: loops, arrays, and conditional logic.

## Key Features
- Uses loops, arrays, and conditional statements for all game logic
- Dynamically redraws the game board after every move
- Full win detection (rows, columns, diagonals) and draw detection
- Replay option at the end of each round
- Input validation (rejects out-of-range or already-taken cells)
- Pure standard C++ — no platform-specific headers, so it compiles
  and runs the same way on Windows, macOS, and Linux

## Files
- `TicTacToe.cpp` — the full game source code

## How to Run in Dev-C++
1. Open **Dev-C++**.
2. Go to `File > Open Project or File...` and select `TicTacToe.cpp`
   (or create a new empty Console Application project and paste the code in).
3. Press **F11** (or `Execute > Compile & Run`) to build and run.
4. Follow the on-screen prompts — enter a number 1-9 to place your mark.

## How to Run with Code::Blocks
1. `File > New > Project > Console Application > C++`.
2. Replace the generated `main.cpp` contents with `TicTacToe.cpp`, or
   add `TicTacToe.cpp` to the project and remove the default `main.cpp`.
3. Build and run with **F9**.

## How to Run from the Command Line (g++, any OS)
```bash
g++ -std=c++11 -Wall TicTacToe.cpp -o TicTacToe
./TicTacToe        # on Windows: TicTacToe.exe
```

## How the Board Numbering Works
```
  1 | 2 | 3
 -----------
  4 | 5 | 6
 -----------
  7 | 8 | 9
```
Type the number of the cell you want to claim on your turn.

## Concepts Demonstrated
| Concept              | Where it's used                                      |
|-----------------------|------------------------------------------------------|
| 2D Arrays              | `char board[3][3]` stores the game state             |
| Loops (for/while)      | Drawing the board, scanning rows/cols/diagonals       |
| Conditionals            | Move validation, win/draw detection, turn switching  |
| Functions               | Code is split into small, single-purpose functions   |

## Possible Extensions
- Add a Snake game mode (as suggested in the assignment) as a second file
- Add an AI opponent (minimax algorithm)
- Track and display a running score across replays
