#include "EntityStore.h"

namespace jr
{

EntityStore::EntityStore()
{
  Entity::init();
}

EntityStore::~EntityStore()
{
  map<Entity*, Entity*>::iterator it;
  for(it=entities.begin(); it!=entities.end(); it++)
    delete it->first;
}

void EntityStore::add(Entity* ent)
{
  entities[ent] = ent;
}

void EntityStore::remove(Entity* ent)
{
  if(contains(ent))
    entities.erase(ent);
}

void EntityStore::update()
{
  map<Entity*, Entity*>::iterator it;
  for(it=entities.begin(); it!=entities.end(); it++){
    Entity* ent = it->first;
    ent->update();
  }
  Entity::swap();
}

void EntityStore::sendPhysicsComponentUpdates()
{
  map<Entity*, Entity*>::iterator it;
  for(it=entities.begin(); it!=entities.end(); it++){
    Entity* ent = it->first;
    ent->sendPhysicsComponentUpdate();
  }
}


bool EntityStore::contains(Entity* ent)
{
  return entities.count(ent);
}

}

