# 🔴 🔵 Connect 4 Engine (C++)

A lightweight, high-performance, and object-oriented implementation of the classic **Connect 4** game, built completely from scratch in C++. 

This project features an optimized localized win-detection engine that evaluates winning conditions dynamically based on the player's last move, rather than redundantly scanning the entire 7x6 board.

---

## 🚀 Features

* **Zero-Dependency Architecture:** Written purely in standard C++ (`std::iostream`, `std::chrono`, `std::algorithm`).
* **Localized Win Verification Engine:** Evaluates horizontal, vertical, and both diagonal axes immediately radiating from the exact coordinate of the last dropped token, ensuring $O(1)$ efficiency per turn.
* **Intuitive CLI Interface:** Clean, reactive console output with user input validation and boundary enforcement.
* **Robust Game Loop:** Automatic player alternating system with structural cleanup upon termination.

---

## 🎮 How to Play

Connect 4 is a two-player turn-based game played on a vertical grid.

1. **Player 1** is represented by `1`.
2. **Player 2** is represented by `2`.
3. On your turn, input a column number from **1 to 7**.
4. Your token will drop into the lowest available slot within that column.
5. The first player to form a horizontal, vertical, or diagonal line of **four consecutive tokens** wins the match!

---

## 🛠️ Code Architecture

The core architecture encapsulates game state and rules inside a single cohesive class object:

### `C4_Board` Class Reference

| Member Component | Type | Description |
| :--- | :--- | :--- |
| `board[7][6]` | `int` multi-array | Holds the state of the 7x6 grid (`0` = Empty, `1` = Player 1, `2` = Player 2). |
| `curr_cord` | `int` | Temporarily tracks the row index where the most recent token landed. |
| `move(int idx, int move)` | `void` method | Handles gravity physics, dropping the token into the bottom-most available cell of the column. |
| `display()` | `void` method | Renders the current state of the board onto the terminal window. |
| `win(int idx, int curr_cord)` | `bool` method | The core evaluation engine checking for a 4-in-a-row combination along 4 axes. |

---

## 💻 Getting Started

### Prerequisites
You need a working standard C++ compiler (like GCC or Clang) installed on your system.

### Compilation
Open your terminal/command prompt, navigate to the directory containing the source file, and execute the following command:
