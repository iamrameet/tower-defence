#include<iostream>
#include "game.hpp"
#define SDL_MAIN_HANDLED
#include<SDL2/SDL.h>
#include "class/monster.hpp"
#include "class/monster-path.hpp"

// SDL_Texture *texture = nullptr;
// SDL_Rect src_rect, dest_rect;

MonsterPath* monsterPath = nullptr;
Monster *monster = nullptr;
Game::Game(){}

void Game::init(const char* title, int posX, int posY, int width, int height, bool fullscreen){
  int flags = 0;

  if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
    std::cout << "Sub-systems initialised!" << std::endl;
    if(fullscreen)
      flags = SDL_WINDOW_FULLSCREEN;
    window = SDL_CreateWindow(title, posX, posY, width, height, flags);
    renderer = SDL_CreateRenderer(window, -1, 0);
    isRunning = true;

    monsterPath = new MonsterPath(renderer);
    monsterPath->addCheckpoint(new MonsterPath::Checkpoint(0, 0));
    monsterPath->addCheckpoint(new MonsterPath::Checkpoint(100, 100));
    monsterPath->addCheckpoint(new MonsterPath::Checkpoint(200, 400));
    monsterPath->addCheckpoint(new MonsterPath::Checkpoint(400, 500));

    monster = new Monster(renderer, monsterPath);
  }
  // SDL_Surface *tmpSurface = IMG_Load("assets/forest.png");
  // texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
  // SDL_FreeSurface(tmpSurface);
}

void Game::handleEvents(){
  SDL_Event event;
  SDL_PollEvent(&event);
  switch(event.type){
    case SDL_QUIT:
      isRunning = false;
      break;
    case SDL_KEYDOWN:
      switch(event.key.keysym.sym){
        case SDLK_LEFT:
          monster->move(-1);
          break;
        case SDLK_RIGHT:
          monster->move(1);
          break;
      }
  }
}

void Game::update(){
  counter++;
  SDL_PumpEvents();
  const uint8_t* keysArray = const_cast <Uint8*> (SDL_GetKeyboardState(NULL));
  // if (keysArray[SDL_SCANCODE_RIGHT] || keysArray[SDL_SCANCODE_UP])
  //   std::cout << "MESSAGE: Right and Up arrows are pressed..." << std::endl;
  // if(keysArray[SDL_SCANCODE_RIGHT]){
  //   monster->move(1);
  // }else if(keysArray[SDL_SCANCODE_LEFT]){
  //   monster->move(-1);
  //   std::cout << "moving left" << std::endl;
  // }
  monster->update();
  // dest_rect.h = 64;
  // dest_rect.w = 64;
  // dest_rect.x = counter;
}

void Game::render(){
  SDL_RenderClear(renderer);
  // SDL_RenderCopy(renderer, texture, NULL, &dest_rect);
  monsterPath->render();
  monster->render();
  SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
  SDL_RenderPresent(renderer);
}

void Game::clean(){
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
}