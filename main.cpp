#include<iostream>
#define SDL_MAIN_HANDLED
#include<SDL2/SDL.h>
#include "game.hpp"

const int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;
Game* myGame = nullptr;

int main(int argc, char* argv[]){
  const int FPS = 60;
  const int frameDelay = 1000 / FPS;
  uint32_t frameStart;
  int frameTime;

  myGame = new Game();
  myGame->init("Hello World", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

  while(myGame->running()){

    frameStart = SDL_GetTicks();

    myGame->handleEvents();
    myGame->update();
    myGame->render();

    frameTime = SDL_GetTicks() - frameStart;
    if(frameDelay > frameTime){
      SDL_Delay(frameDelay - frameTime);
    }
  }

  myGame->clean();
  return 0;
}