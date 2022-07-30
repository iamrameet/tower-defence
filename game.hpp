#ifndef GAME_HPP
#define GAME_HPP

#include<SDL2/SDL.h>

class Game{
  private:
    bool isRunning = false;
    SDL_Window *window;
    int counter = 0;
  public:
    SDL_Renderer *renderer;
    Game();
    ~Game();
    void init(const char* title, int posX, int posY, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running(){
      return isRunning;
    }
};

#endif