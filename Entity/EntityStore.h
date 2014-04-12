#ifndef ENTITY_ENTITYSTORE_H
#define ENTITY_ENTITYSTORE_H

#include <map>
#include <vector>
#include "Entity.h"
#include "../Graphics/Drawer.h"

namespace jr
{

using std::map;
using std::vector;

class EntityStore
{
	public:
		EntityStore(Drawer* d);
		~EntityStore();

    void add(Entity* ent);
    void remove(Entity* ent);
    void update();
    vector<Entity*>& getParents();
    vector<Entity*>& deletes();
    vector<Entity*>& getNewContext();
    bool wantsToSwitchContext();

	private:
    map<Entity*, Entity*> entities;
    vector<Entity*> parents;
    vector<Entity*> deleteMes;
    vector<Entity*> newContext;
    Drawer* drawer;

    bool contains(Entity* ent);
};

}
#endif
