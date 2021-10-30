#include "Game.h"
#include <iostream>

Game* g_game = 0;

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
bool g_bRunning = false;

int main(int argc, char* args[])
{
  if(TheGame::Instance()->init("Chapter1",100,100,640,480,false))
  {
    while(TheGame::Instance()->running())
    {
      TheGame::Instance()->handleEvents();
    TheGame::Instance()->update();
    TheGame::Instance()->render();
    SDL_Delay(10);
    }
    
  }
  else
  {
    std::cout << "game init failure" << SDL_GetError() << "\n";
    return -1;
  }

  TheGame::Instance()->clean();

  /*g_game = new Game();
  g_game->init("Setting up SDL 10/22", 100, 100, 640, 480, 0);
  while (g_game->running())
  {
    g_game->handleEvents();
    g_game->update();
    g_game->render();
    SDL_Delay(10);

  }

  g_game->clean();*/


  return 0;
}  