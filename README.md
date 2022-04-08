# Rock, Paper and Scissors Game using C++ Programming Language

## Introduction and Technologies Used

This codebase implements the Rock, Paper and Scissors game made by using multiple object oriented principles of C++. It is a game played between the User and the Computer. There are three moves a player in the game can make \(R\)ock, \(P\)aper and \(S\)cissors. The Results of the game will be as follows depending on both player's moves.

| Player 1       | Player 2       | Result         |
|:--------------:|:--------------:|:--------------:|
| Rock           | Rock           | Draw           |
| Rock           | Paper          | Player 2 Wins  |
| Rock           | Scissors       | Player 1 Wins  |
| Paper          | Rock           | Player 1 Wins  |
| Paper          | Paper          | Draw           |
| Paper          | Scissors       | Player 2 Wins  |
| Scissors       | Rock           | Player 2 Wins  |
| Scissors       | Paper          | Player 1 Wins  |
| Scissors       | Scissors       | Draw           |

You can play multiple rounds in a single game with the computer. At the end, when you wish to exit the game, the program would show the final result and display the winner accordingly.

### Technology Used

All the tools and programming languages used in the code are as follows :

- C++ 11+

- GTest for Testing

## Low Level Design of the Program

### Classes Used

- Player - It is an abstract class which implements some of the common functions of the User and the Computer like Updating Scores, Fetching Scores and Choices. A Player has only 2 data members - Choice and Score and three pure virtual functions. The User and the Computer have seperate implemention of both, hence using runtime binding.

- User - It is a derived class of Player Class. It implements pure virtual functions of the Base Class. We ask for the user's input for the Round.

- Computer - It is a derived class of Player Class. It implements the pure virtual functions of the Base Class. We generate a random number between 0-2 inclusive and map these to 0 - Rock, 1 - Paper and 2 - Scissors.

- RockPaperScissorGame - It is the main class which drives the whole game. It consists of 2 Players - user and the computer, initialized in the constructor, and also sets a seed for the random function. Apart from constructor and destructor, we have 4 important functions - playGame() which is responsible for repeating the rounds in the game untill the user quits, getRoundWinner() which implements logic to decide winner of the current round, displayScore() is used to display score of the players and getWinner() decides the winner at the end of the game and displays the result.

### What concept used and Why ?

- Player is made abstract so that the derived classes can inherit the common features from the base class.
- The Rock, Paper and Scissors Game is a game between two players and not essentially a user and a computer. Hence, using an abstract class helps to reuse the code to extend its functionalities as well.
- Use of Inheritance and Polymorphism help in repeating the same code again and again.
- Hiding data and member function definition help achieve Abstraction and Encapsulation using Classes.

### Test Written

- Test to check initialization of both the Players. (1)
- Test to check all possible outcomes of the game, input anomalies are handled while taking input. (3)
- Test to check score upation for both the Players. (1)

## Setup Guide

### Installations

Installation of tools used is necessary if not already done. Refer these links to download ([C++](https://code.visualstudio.com/docs/cpp/config-mingw#:~:text=Install%20Visual%20Studio%20Code.,helpful%20C%2B%2B%20tools%20and%20libraries)) and ([GTest](https://github.com/google/googletest/blob/main/googletest/README.md)) to your project.

### Running the Rock, Paper and Scissors Program

To run the program, execute these commands in the terminal in the project's directory.

```Bash
g++ -std=c++0x main.cpp -o main
./main
```

User Input can be either of

- R for Rock,
- P for Paper or
- S for Scissors

### Running Tests for the Program

To run test for the program, execute these commands in the terminal in the project's directory.

```Bash
g++ -std=c++0x test.cpp -lgtest  -lgtest_main -pthread -o test
./test
```
