#include<SDL2/SDL.h>

class GameObject{
  private:
    int x;
    int y;
    int width;
  public:
    GameObject(SDL_Renderer *renderer);
    ~GameObject();
    void update();
    void render();
};