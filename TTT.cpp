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
    std::cout << "Enter the X and Y coordinates of the place you want to pick: ";
    std::cin >> xMove;
    std::cin >> yMove;
    if( game.getMoves()%2 == 0 ) {
      game.pickSpot(xMove, yMove, true);
    } else {
      game.pickSpot(xMove, yMove, false);
    }
  }
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


// allows the user/AI to pick a spot in the tic tac toe board based on the x and y
// coordinate if XorO is false then the player is o's and if its true the player
// is x's
void gameBoard::pickSpot(int x, int y, bool XorO)
{
  int marker = 0;
  if(XorO){
    marker = 1;
  }
  state[x][y] = marker;
  moves++;
}
