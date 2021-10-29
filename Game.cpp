#include "Game.h"
#include "SDL_image.h"

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) 
  {
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if (m_pWindow != 0) {
        m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
          if (m_pRenderer != 0) {
            SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
          } 
          else {
            return false; 
          }
    } 
    else {
      return false; 
      }
    } 
    else {
      return false; 
    }

    SDL_Surface* pTempSurface = IMG_Load("Assets/animate-alpha.png");

    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);

    m_soureceRectangle.w = 128;
    m_soureceRectangle.h = 82;

    m_destnationRectangle.w = m_soureceRectangle.w;
    m_destnationRectangle.h = m_soureceRectangle.h;

    m_destnationRectangle.x = 0;
    m_destnationRectangle.y = 0;
    
m_bRunning = true;
return true;
}

void Game::update()
{
  m_soureceRectangle.x = 128 * ((SDL_GetTicks()/100) % 6);
}

void Game::render()
{
  SDL_RenderClear(m_pRenderer);
  SDL_RenderCopy(m_pRenderer, m_pTexture, &m_soureceRectangle, &m_destnationRectangle);
  SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
 return m_bRunning;
}

void Game::handleEvents()
{
  SDL_Event event;
  if(SDL_PollEvent(&event))
  {
    switch (event.type) {
    case SDL_QUIT:
    m_bRunning = false;
    break;
    default:
    break;
    }
  }
}

void Game::clean()
{
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}