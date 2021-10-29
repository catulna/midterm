#include "Game.h"

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

  }

  g_game->clean();
  return 0;
}  