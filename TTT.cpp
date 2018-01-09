//Zachary Palmer

#include "TTT.hpp"
#include <iostream>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
  std::string user1, user2;
  std::cout << "Please enter the name of the first player (X's) or type AI for an automated player: ";
  std::cin >> user1;
  std::cout << "Please enter the name of the second player (O's) or type AI for an automated player: ";
  std::cin >> user2;
  gameBoard game(user1,user2);
  while(!game.getWon()) {
    game.draw();
    int xMove, yMove;
    bool success = false;
    while(!success) {
      std::cout << "Enter the X coordinates of the place you want to pick: ";
      std::cin >> xMove;
      std::cout << "\nEnter the Y coordinates of the place you want to pick: ";
      std::cin >> yMove;
      if( game.getMoves()%2 == 0 ) {
        success = game.pickSpot(xMove, yMove, true);
      } else {
        success = game.pickSpot(xMove, yMove, false);
      }
      if(!success) {
        std::cout << "ERROR TRY AGAIN\n\n\n";
      }
    }
    game.checkWon();
  }
  game.draw();
  std::cout << "Congrats " << game.getWinner() << " you won this hard fought game!";
  std::cin >> user1;
}

gameBoard::gameBoard(std::string player1, std::string player2)
{
  p1 = player1;
  p2 = player2;
  won = false;
  moves = 0;
  for(int i = 0; i < 3; i++) {
    for(int e = 0; e < 3; e++) {
      state[i][e] = -1;
    }
  }
}

void gameBoard::draw()
{
  for(int i = 0; i < 100; i++) {
    std::cout << std::endl;
  }

  for(int i = 0; i < 3; i++) {
    for(int e = 0; e < 3; e++) {
      if(state[i][e] == 0) {
        std::cout << " O ";
      } else
      if(state[i][e] == 1) {
        std::cout << " X ";
      } else {
        std::cout << "   ";
      }
      if(e < 2) {
        std::cout << "|";
      }
    }
    if(i < 2) {
      std::cout << "\n___|___|___\n";
    } else {
      std::cout << "\n   |   |\n\n";
    }
  }
}

bool gameBoard::pickSpot(int x, int y, bool XorO)
{
  int marker = 0;
  if(XorO){
    marker = 1;
  }
  if( x > 3 || y > 3) {
    return false;
  }
  x--;
  y--;
  if(state[x][y] == -1) {
    state[x][y] = marker;
    moves++;
    return true;
  }
  return false;
}

void gameBoard::checkWon()
{
  int victor;
  if((state[0][0] == state[0][1] && state[0][0] == state[0][2]) ||
     (state[0][0] == state[1][0] && state[0][0] == state[2][0]) ||
     (state[0][0] == state[1][1] && state[0][0] == state[2][2])) {
       victor = state[0][0];
  } else
  if((state[1][0] == state[1][1] && state[1][0] == state[1][2]) ||
     (state[0][1] == state[1][1] && state[0][1] == state[2][1]) ||
     (state[0][2] == state[1][1] && state[0][2] == state[2][0])) {
       victor = state[1][1];
  } else
  if((state[2][0] == state[2][1] && state[2][0] == state[2][2]) ||
     (state[0][2] == state[1][2] && state[0][2] == state[2][2])) {
       victor = state[2][2];
  }
    if(victor != -1) {
      won = true;
      if(victor == 1) {
        winner = p1;
      } else {
        winner = p2;
      }
    }
}
