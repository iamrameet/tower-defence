#include<SDL2/SDL.h>

class Game{
  private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
  public:
    Game();
    ~Game();
    void init(const char* title, int posX, int posY, int width, int height, bool fullscreen){}
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running(){
      return isRunning;
    }
};