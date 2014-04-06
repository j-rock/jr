#include "Renderer.h"

namespace jr
{

Renderer::Renderer(int width, int height, std::string title)
{
  window = new sf::RenderWindow(sf::VideoMode(width, height), title);
  PIXELS_PER_METER = 100;
}

Renderer::~Renderer()
{
  delete window;
}

bool Renderer::isWindowOpen()
{
  return window->isOpen();
}

void Renderer::pollEvents()
{
  sf::Event event;
  while(window->pollEvent(event)){
    if(event.type == sf::Event::Closed){
      window->close();
      return;
    }
    if(event.type == sf::Event::Resized)
    {
      sf::FloatRect visibleArea(0,0,event.size.width, event.size.height);
      window->setView(sf::View(visibleArea));
    }
  }
}


void Renderer::updateBounds(bbox<float> bounds)
{
  pixelBounds.minX = pixelConvert(bounds.minX);
  pixelBounds.maxX = pixelConvert(bounds.maxX);
  pixelBounds.minY = -pixelConvert(bounds.maxY);
  pixelBounds.maxY = -pixelConvert(bounds.minY);
}

int Renderer::pixelConvert(float real)
{
  return Utils::roundf(PIXELS_PER_METER * real);
}

int Renderer::pixelConvertX(float realX)
{
  return pixelConvert(realX) - pixelBounds.minX;
}

int Renderer::pixelConvertY(float realY)
{
  return -pixelConvert(realY) - pixelBounds.minY;
}

void Renderer::render()
{
   window->clear();

   //TODO - have some sort of DrawStruct
   /*
      while(!drawQueue.empty())
        draw = drawQueue.top(); drawQueue.pop();
        window->draw(draw)....
   */

   window->display();
}

}

