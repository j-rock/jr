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

int Renderer::pixelConvert(float real)
{
  return Utils::roundf(PIXELS_PER_METER * real);
}

void Renderer::updateBounds(bbox<float> bounds)
{
  pixelBounds.minX = pixelConvert(bounds.minX);
  pixelBounds.maxX = pixelConvert(bounds.maxX);
  pixelBounds.minY = -pixelConvert(bounds.maxY);
  pixelBounds.maxY = -pixelConvert(bounds.minY);
}

int Renderer::pixelConvertX(float realX)
{
  return pixelConvert(realX) - pixelBounds.minX;
}

int Renderer::pixelConvertY(float realY)
{
  return -pixelConvert(realY) - pixelBounds.minY;
}

sf::Vector2i Renderer::pixel2Pixel(vec<float> worldPos)
{
  using Utils::roundf; 
  sf::Vector2i pixelPos(roundf(worldPos.x),roundf(worldPos.y));
  return pixelPos;
}

sf::Vector2i Renderer::world2Pixel(vec<float> worldPos)
{
  sf::Vector2i pixelPos(pixelConvertX(worldPos.x),
                        pixelConvertY(worldPos.y));
  return pixelPos;
}

sf::Vector2i Renderer::extractPixelPos(GraphicsComponent* gcomp)
{
  vec<float> worldPos = gcomp->getPosition();
  if(gcomp->usingPixelCoords())
    return pixel2Pixel(worldPos);
  else
    return world2Pixel(worldPos);
}

void Renderer::addDrawMe(GraphicsComponent* gcomp)
{
  drawQueue.push(gcomp);
}

void Renderer::setCameraPos(vec<float> worldPos)
{
  using Utils::max;

  sf::Vector2i newPos = world2Pixel(worldPos); 

  sf::View view = window->getView();
  view.setCenter(newPos.x, newPos.y);
  window->setView(view);
}


void Renderer::render()
{
   processMessages();
   window->clear();

   while(!drawQueue.empty()){
     GraphicsComponent* gcomp = drawQueue.top();
     drawQueue.pop();
     sf::Vector2i pixelPos = extractPixelPos(gcomp);
     gcomp->setPixelPosition(pixelPos);
     window->draw(*(gcomp->getDrawable()));
   }

   window->display();
}

}

