//Zachary Palmer

#ifndef __TTT_HPP_INCLUDED
#define __TTT_HPP_INCLUDED

#include <string>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

//this class is the game of tic tac toe
class gameBoard
{
public:

// constructor which takes the names of the players
gameBoard(std::string player1, std::string player2);

// draws the current state of the game into the terminal (will be implemented as gui)
void draw();


// allows the user/AI to pick a spot in the tic tac toe board based on the x and y
// coordinate if XorO is false then the player is o's and if its true the player
// is x's returns false if space is taken
bool pickSpot(int x, int y, bool XorO);

// checks if anyone won the game and updates the winnter and won flag
void checkWon();


bool getWon() { return won; }
int getMoves() { return moves; }
std::string getWinner() { return winner; } 

private:

// this is a 2 dimensional array of integers which defines the current state of the game
// a -1 indicates that the space is empty, a 1 indicates that an X is there, a 0 indicates
// that the space has a (you guessed it) zero in it
int state [3][3];

// set to true once the game is won
bool won;

// strings for the user's names
std::string p1, p2, winner;

// counter for the number of moves it takes for a winner to emerge
int moves;
};


#endif // __TTT_HPP_INCLUDED
