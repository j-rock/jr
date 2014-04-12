#include "Entity.h"

namespace jr
{


Entity::Entity(GraphicsComponent* g, PhysicsComponent* p)
{
  gcomp = g;
  pcomp = p;
  deleteMe = false;
}

Entity::~Entity()
{
  delete gcomp;
  delete pcomp;
}

bbox<float> Entity::getBounds()
{
  return pcomp->getBounds();
}

PhysicsComponent* Entity::getPhysicsComponent()
{
  return pcomp;
}

bool Entity::shouldDelete()
{
  return deleteMe;
}

bool Entity::isParent()
{
  return children.size() > 0;
}

void Entity::setDrawer(Drawer* d)
{
  gcomp->setDrawer(d);
}

bool Entity::wantsToSwitch()
{
  return newContext.size() > 0;
}

vector<Entity*>& Entity::getNewContext()
{
  return newContext;
}

void Entity::switchContext(vector<Entity*> ents)
{
  newContext.clear();
  for(std::size_t i=0; i<ents.size(); i++)
    newContext.push_back(ents[i]);
}

void Entity::setPriority(int p)
{
  gcomp->setPriority(p);
}

vector<Entity*>& Entity::getChildren()
{
  return children;
}

void Entity::scheduleDeletion()
{
  deleteMe = true;
}


void Entity::spawn(Entity* child)
{
  children.push_back(child);
}

}

