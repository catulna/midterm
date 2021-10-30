#include "Game.h"

//Loom 학생용 계정 인증이 안되어서 영상을 찍을 수 없어 일단 멈췄습니다... 

Game* g_game = 0;

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
bool g_bRunning = false;

int main(int argc, char* args[])
{

  g_game = new Game();
  g_game->init("Setting up SDL 10/22", 100, 100, 640, 480, 0);
  while (g_game->running())
  {
    g_game->handleEvents();
    g_game->update();
    g_game->render();
    SDL_Delay(10);

  }

  g_game->clean();
  return 0;
}  