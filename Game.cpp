#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) 
  {
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if (m_pWindow != 0) {
        m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
          if (m_pRenderer != 0) {
            SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
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

    SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/rider.bmp");

    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);

    SDL_QueryTexture(m_pTexture, NULL, NULL, &m_soureceRectangle.w, &m_soureceRectangle.h);

    m_destnationRectangle.w = m_soureceRectangle.w;
    m_destnationRectangle.h = m_soureceRectangle.h;

    m_destnationRectangle.x = m_soureceRectangle.x = 0;
    m_destnationRectangle.y = m_soureceRectangle.y = 0;
    
m_bRunning = true;
return true;
}

void Game::update()
{

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