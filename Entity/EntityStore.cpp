#include "EntityStore.h"

namespace jr
{

EntityStore::EntityStore(Drawer* d)
{
  drawer = d;
}

EntityStore::~EntityStore()
{
  map<Entity*, Entity*>::iterator it;
  for(it=entities.begin(); it!=entities.end(); it++)
    delete it->first;
  delete drawer;
}

void EntityStore::add(Entity* ent)
{
  entities[ent] = ent;
  ent->setDrawer(drawer);
}

void EntityStore::remove(Entity* ent)
{
  if(contains(ent))
    entities.erase(ent);
}

void EntityStore::update()
{
  parents.clear();
  deleteMes.clear();
  map<Entity*, Entity*>::iterator it;
  for(it=entities.begin(); it!=entities.end(); it++){
    Entity* ent = it->first;
    ent->update();

    if(ent->isParent())
      parents.push_back(ent);
    if(ent->shouldDelete())
      deleteMes.push_back(ent);
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

