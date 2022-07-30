#include<SDL2/SDL.h>
#include "class/monster.hpp"
#include<iostream>

Monster::Monster(SDL_Renderer *renderer, MonsterPath *path){
  this->renderer = renderer;
  this->monsterPath = path;
  MonsterPath::Checkpoint* checkpoint = path->getCheckpoint(_pos);
  position.set(checkpoint);
  rect = new SDL_FRect();
  rect->h = 10;
  rect->w = 10;
  rect->x = position.x - rect->w / 2;
  rect->y = position.y - rect->h / 2;
}

void Monster::move(int direction = 1){
  MonsterPath::Checkpoint* checkpoint = monsterPath->getCheckpoint(_pos + direction);
  if(checkpoint){
    _pos += direction;
    position.set(checkpoint);
    rect->x = position.x - rect->w / 2;
    rect->y = position.y - rect->h / 2;
  }
  std::cout << _pos << std::endl;
  // if(_pos + direction >= 0 && _pos + direction < monsterPath->checkpoint_count)
  //   _pos += direction;
}

void Monster::update(){}
void Monster::render(){
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_RenderFillRectF(renderer, rect);
}