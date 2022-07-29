#include<iostream>
#define SDL_MAIN_HANDLED
#include<SDL2/SDL.h>
#include<game.cpp>

const int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;

int main(int argc, char* argv[]){
  // std::cout << "Hello World!" << std::endl;
  SDL_Init(SDL_INIT_EVERYTHING);
  Game *myGame = new Game();
  myGame->init("Hello World", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, false);
  // std::cin.get();
  return 0;
}