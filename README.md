# Tic-Tac-Toe Game

A simple console-based implementation of the classic **Tic-Tac-Toe** game in C++. This program allows two players to compete against each other in a fun and interactive way.

## Features

- Two-player mode with custom player names.
- Dynamic game board that updates after each turn.
- Input validation to prevent invalid or duplicate moves.
- Automatic detection of winners or a draw.

## How It Works

1. **Player Setup**: Players enter their names at the start of the game.
2. **Gameplay**:
   - Players take turns choosing a position on the 3x3 board (1-9 format).
   - The board updates after every valid move.
3. **Win/Draw Detection**:
   - The game checks for a winner after every move.
   - If all positions are filled without a winner, the game declares a draw.

## How I Built It

This project was created using C++ with a focus on modular design and user-friendly interaction. Key highlights of the development process:
- **Planning**: Defined the structure of the game, including the grid, player turns, and win conditions.
- **Coding**: Divided the program into modular functions for easier maintenance, such as `PlayerInput`, `CheckWinner`, and `DisplayResult`.
- **Testing**: Verified the game for all possible outcomes (win, loss, draw) and edge cases like invalid input.
