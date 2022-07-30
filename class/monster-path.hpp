#ifndef MONSTER_PATH_HPP
#define MONSTER_PATH_HPP

#include<SDL2/SDL.h>
#include<class/vector.cpp>

class MonsterPath{
  public:
    class Checkpoint: public Vector2{
      public:
        Checkpoint(int x, int y);
    };
  private:
    SDL_Renderer* renderer;
    Checkpoint* checkpoints[10];
  public:
    int checkpoint_count = 0;
    MonsterPath(SDL_Renderer *renderer);
    ~MonsterPath();
    void update();
    void render();
    bool addCheckpoint(Checkpoint* checkpoint);
    Checkpoint* getCheckpoint(int index);
};

#endif