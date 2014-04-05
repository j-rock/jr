#include "Entity.h"

namespace jr
{


Entity::Entity(GraphicsComponent* g, LogicComponent* l, PhysicsComponent* p)
{
  gcomp = g;
  lcomp = l;
  pcomp = p;
  subscribe(lcomp->getMessageHandler());
}

Entity::~Entity()
{
  delete gcomp;
  delete pcomp;
  delete lcomp;
}

void Entity::setChildHandlers()
{
  pcomp->setHandlers(gcomp->getMessageHandler(), lcomp->getMessageHandler());
  lcomp->setHandlers(pcomp->getMessageHandler(), gcomp->getMessageHandler());
}

void Entity::setSimHandler(MessageHandler* simulator)
{
  lcomp->setSimHandler(simulator);
}

void Entity::setRendererHandler(MessageHandler* renderer)
{
  gcomp->setRendererHandler(renderer);
}

void Entity::update()
{
  lcomp->update();
  gcomp->update();
  pcomp->update();
}

void Entity::sendPhysicsComponentUpdate()
{
  pcomp->sendUpdates();
}

bbox<float> Entity::getBounds()
{
  return pcomp->getBounds();
}

Message* Entity::getCollideMessage()
{
  return lcomp->getCollideMessage();
}

Message* Entity::getUncollideMessage()
{
  return lcomp->getUncollideMessage();
}

bool Entity::inWorldSpace()
{
  return !(gcomp->usingPixelCoords());
}

void Entity::takeMessage(Message* m)
{
  int LOGIC_HANDLER = 0;
  send(LOGIC_HANDLER, m);
}

void Entity::init()
{
  LogicComponent::init();
}

void Entity::swap()
{
  LogicComponent::swap();
}


PhysicsComponent* Entity::getPhysicsComponent()
{
  return pcomp;
}

}

