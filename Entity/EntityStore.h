#ifndef ENTITY_ENTITYSTORE_H
#define ENTITY_ENTITYSTORE_H

#include <map>
#include <vector>
#include "Entity.h"

namespace jr
{

using std::map;
using std::vector;

class EntityStore
{
	public:
		EntityStore();
		~EntityStore();

    void add(Entity* ent);
    void remove(Entity* ent);
    void update();
    vector<Entity*>& getParents();
    vector<Entity*>& deletes();

	private:
    map<Entity*, Entity*> entities;
    vector<Entity*> parents;
    vector<Entity*> deleteMes;

    bool contains(Entity* ent);
};

}
#endif
