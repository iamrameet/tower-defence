#include<game.hpp>

Game::Game(){
  isRunning = true;
}

void Game::init(const char* title, int posX, int posY, int width, int height, bool fullscreen){
  window = SDL_CreateWindow(title, posX, posY, width, height, SDL_WINDOW_ALLOW_HIGHDPI);
  renderer = SDL_CreateRenderer(window, -1, 0);
  if(fullscreen)
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
  SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
  SDL_Delay(30000);
}