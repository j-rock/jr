#include "EntityStore.h"

namespace jr
{

EntityStore::EntityStore()
{
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
  parents = new vector<Entity*>();
  deleteMes = new vector<Entity*>();
  map<Entity*, Entity*>::iterator it;
  for(it=entities.begin(); it!=entities.end(); it++){
    Entity* ent = it->first;
    ent->act();

    if(ent->isParent())
      parents->push_back(ent);
    if(ent->shouldDelete())
      deleteMes->push_back(ent);
  }
}

bool EntityStore::contains(Entity* ent)
{
  return entities.count(ent);
}

vector<Entity*>& EntityStore::getParents()
{
  return parents;
}

vector<Entity*>& EntityStore::deletes()
{
  return deleteMes;
}

}

