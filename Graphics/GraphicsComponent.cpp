#include "GraphicsComponent.h"
#include <iostream>

namespace jr
{

GraphicsComponent::GraphicsComponent(int prior)
{
  priority = prior;
}

GraphicsComponent::~GraphicsComponent()
{
}

void GraphicsComponent::setRendererHandler(MessageHandler* renderer)
{
  RENDERER_HANDLER = subscribe(renderer);
}

void GraphicsComponent::update()
{
  std::cout << "GRAPHICS COMPONENT UPDATE: ";
  processMessages();
  Message* m = new DrawMeMessage(this);
  send(RENDERER_HANDLER, m);
}

vec<float> GraphicsComponent::getPosition()
{
  return position;
}

void GraphicsComponent::setPosition(vec<float> pos)
{
  std::cout << "Set position called!" << std::endl;
  position = pos;
}

void GraphicsComponent::setVelocity(vec<float> vel)
{
  velocity = vel;
}

void GraphicsComponent::setAngle(float radianAngle)
{
  angle = radianAngle;
}


int GraphicsComponent::getPriority()
{
  return priority;
}

}
