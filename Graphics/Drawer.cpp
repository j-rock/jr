#include "Drawer.h"

namespace jr
{

Drawer::Drawer(Renderer* r)
{
  renderer = r;
}

Drawer::~Drawer()
{
}

void Drawer::draw(sf::Drawable* img, int priority)
{
  renderer->draw(img, priority);
}

vec<int> Drawer::world2Pixel(float x, float y)
{
  vec<int> pixel(renderer->pixelConvertX(x),
                 renderer->pixelConvertY(y));
  return pixel;
}

vec<int> Drawer::pixel2Pixel(int x, int y)
{
   sf::Vector2f center = renderer->window->getView().getCenter(); 
   vec<int> pixel(x + center.x, y + center.y);
   return pixel;
}

}

