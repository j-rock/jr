#include "GraphicsComponent.h"

namespace jr
{

GraphicsComponent::GraphicsComponent()
{
}

GraphicsComponent::~GraphicsComponent()
{
  //drawer will be deleted by entitystore
}

void GraphicsComponent::drawWorld(float x, float y)
{
  vec<int> pixelCoords = drawer->world2Pixel(x, y);
  doDraw(pixelCoords.x, pixelCoords.y);
}

void GraphicsComponent::drawPixel(int x, int y)
{
  vec<int> pixelCoords = drawer->pixel2Pixel(x, y);
  doDraw(pixelCoords.x, pixelCoords.y);
}

void GraphicsComponent::doDraw(int x, int y)
{
  setPosition(x, y);
  drawer->draw(getDrawable(), priority);
}

void GraphicsComponent::setDrawer(Drawer* d)
{
  drawer = d;
}

void GraphicsComponent::setPriority(int p)
{
  priority = p;
}

void GraphicsComponent::setAngle(float a)
{
  (void)a;
}

}
