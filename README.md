# BlockBlitz

A retro-style brick breaker game built with C++ for Windows Console.

![BlockBlitz Screenshot](https://via.placeholder.com/600x400?text=BlockBlitz+Screenshot)

## Description

BlockBlitz is a classic brick breaker arcade game implemented in C++ using the Windows Console API. The player controls a paddle at the bottom of the screen to bounce a ball upward, breaking bricks arranged at the top of the screen.

## Features

- Console-based graphics with colored elements
- Responsive keyboard controls
- Classic brick-breaking gameplay
- Menu system with game instructions
- Win/lose conditions
- Modular code architecture

## How to Play

- Use `A` or `Left Arrow` key to move the paddle left
- Use `D` or `Right Arrow` key to move the paddle right
- Press `Spacebar` to launch the ball
- Press `ESC` to quit the current game

## Installation

### Prerequisites
- Windows operating system
- C++ compiler (GCC, MinGW, or Visual Studio)

### Building from Source
1. Clone the repository:
```
git clone https://github.com/aditya301cs/block-blitz-cpp.git
cd block-blitz-cpp
```

2. Compile the game:
   - Using Make:
     ```
     make
     ```
   - Manually:
     ```
     g++ -o block_blitz main.cpp game.cpp gameplay.cpp -std=c++11
     ```

3. Run the game:
```
./block_blitz
```

## Project Structure

- `main.cpp` - Entry point with menu system
- `game.h` - Header file with declarations
- `game.cpp` - Core game functions and global variables
- `gameplay.cpp` - Gameplay and instruction functions

## Future Improvements

- [ ] Add scoring system
- [ ] Implement multiple levels
- [ ] Add power-ups
- [ ] Include sound effects
- [ ] Add color to console elements
- [ ] Create brick patterns/variations

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

- Inspired by classic arcade brick breaker games
- Created as a learning project for C++ programming and game development fundamentals
