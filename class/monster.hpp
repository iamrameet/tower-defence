#ifndef MONSTER_HPP
#define MONSTER_HPP

#include<SDL2/SDL.h>
#include "class/monster-path.hpp"

class Monster{
private:
  SDL_Renderer *renderer;
  MonsterPath *monsterPath;
  SDL_FRect *rect;
  Vector2 direction;
  int _pos = 0;
public:
  Vector2 position;
  Vector2 velocity;
  Monster(SDL_Renderer *renderer, MonsterPath *path);
  ~Monster();
  void update();
  void render();
  void move(int direction);
};

#endif