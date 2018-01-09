//Zachary Palmer

#include "TTT.hpp"
#include <iostream>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
  int rDepth;  //recursion Depth
  int iHeight; //initial Height

  if( argc != 3) { //Checking to make sure the number of arguments is correct
    std::cout << "Please Supply Two Arguments: 1.) Recursion Depth 2.) Initial Window Height" << std::endl;
    return -1;
  }
  else if(argv[1]-1 < 0) { //Checking to make sure recursion depth is greater than 1
    std::cout << "Recursion depth must be 1 or greater." << std::endl;
    return -2;
  }
  else { //output the checked arguments and store them in variables
    rDepth = atoi(argv[1])-1;
    iHeight = atoi(argv[2]);
    std::cout << "Depth: " << rDepth << std::endl << "Height: " << iHeight << std::endl;
  }
  sf::RenderWindow window(sf::VideoMode(iHeight,iHeight), "Original"); //display window

  while (window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event)) {
      if(event.type == sf::Event::Closed)
      window.close();
    }
    recDiamond rDiamond(rDepth,(iHeight/2),(iHeight/2),(iHeight/2)); //construct original sierpinski triangle
    window.clear(sf::Color::White); //set background color for window
    window.draw(rDiamond); //draw sierpinski triangle (recursivly creats and draws triangles until depth is 0)
    window.display();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      //if the up arrow key is pressed increase recursion by 1;
      if(rDepth < 10) {
        rDepth++;
        std::cout << "Recursion level: " << rDepth << std::endl;
      }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      //if the down arrow key is pressed decrease recurstion by 1
      if(rDepth > 0) {
        rDepth--;
        std::cout << "Recursion level: " << rDepth << std::endl;
      }
      else {
        std::cout << "Recursion cannot be less than 1" << std::endl;
      }
    }
  }
  return 0;
}


recDiamond::recDiamond(int d, double X, double Y, double S)
{
  x = X;
  y = Y;
  s = S;
  depth = d;
  S2 = (s*sqrt(2));
  diamond.setPointCount(4);
  if(d%2==0) {
    diamond.setFillColor(sf::Color::Black);
  } else {
    diamond.setFillColor(sf::Color::Red);
  }
  diamond.setPoint(0,sf::Vector2f(x-(s/2),  y));
  diamond.setPoint(2,sf::Vector2f(x+(s/2),      y));
  diamond.setPoint(1,sf::Vector2f(x,      y+(s/2)));
  diamond.setPoint(3,sf::Vector2f(x,      y-(s/2)));

}

void recDiamond::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(diamond,states);
  if(depth >0) { //construct the three children triangles(depth, two vertexes, side length)
    recDiamond a(depth-1,  x-(s)*.5,     y+s*.5,  s*.5);
    recDiamond b(depth-1,  x+(s)*.5,     y+s*.5,  s*.5);
    recDiamond c(depth-1,  x-(s)*.5,     y-s*.5,  s*.5);
    recDiamond d(depth-1,  x+(s)*.5,     y-s*.5,  s*.5);
    //call the draw method on the children
    target.draw(a);
    target.draw(b);
    target.draw(c);
    target.draw(d);
  }
}
