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


void Entity::instantiate(Entity* child)
{
  children.push_back(child);
}

}

