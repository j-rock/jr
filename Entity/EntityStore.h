#ifndef ENTITY_ENTITYSTORE_H
#define ENTITY_ENTITYSTORE_H

#include <map>
#include "Entity.h"

namespace jr
{

using std::map;

class EntityStore
{
	public:
		EntityStore();
		~EntityStore();

    void add(Entity* ent);
    void remove(Entity* ent);
    void update();
    void sendPhysicsComponentUpdates();

	private:
    map<Entity*, Entity*> entities;

    bool contains(Entity* ent);
};

}
#endif
