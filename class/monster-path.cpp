#include<SDL2/SDL.h>
#include "class/monster-path.hpp"

MonsterPath::Checkpoint::Checkpoint(int x = 0, int y = 0): Vector2(x, y){}

MonsterPath::MonsterPath(SDL_Renderer *renderer){
  this->renderer = renderer;
}

void MonsterPath::update(){}
void MonsterPath::render(){
  for(int i = 1; i < checkpoint_count; i++){
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLineF(renderer, checkpoints[i-1]->x, checkpoints[i-1]->y, checkpoints[i]->x, checkpoints[i]->y);
  }
}
bool MonsterPath::addCheckpoint(Checkpoint* checkpoint){
  if(checkpoint_count < 10){
    checkpoints[checkpoint_count++] = checkpoint;
    return true;
  }
  return false;
}
MonsterPath::Checkpoint* MonsterPath::getCheckpoint(int index){
  if(index >= 0 && index < checkpoint_count){
    return checkpoints[index];
  }
  return nullptr;
}