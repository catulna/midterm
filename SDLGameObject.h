#pragma once

#include "GameObject.h"
#include "LoaderParams.h"

class SDLGameObject : public GameObject {

public:
SDLGameObject(const LoaderParams* pParams);
virtual void draw() = 0;
virtual void update() = 0;
virtual void clean() = 0;
virtual ~SDLGameObject() {}

protected:
int m_x;
int m_y;
int m_width;
int m_height;
int m_currentRow;
int m_currentFrame;
std::string m_textureID;
};