#ifndef PHYSICS_PHYSICSSIMULATOR_H
#define PHYSICS_PHYSICSSIMULATOR_H

#include <Box2D/Box2D.h>
#include "PhysicsComponent.h"
#include "../Entity/Entity.h"
#include "../Utils/vec.h"

namespace jr
{

using Utils::vec;

class PhysicsSimulator
{
	public:
		PhysicsSimulator();
    PhysicsSimulator(vec<float> grav);
		virtual ~PhysicsSimulator();
    
    void add(Entity* ent);
    void remove(Entity* ent);
    void update();
    bbox<float> getBounds();

	private:
    b2World* world;
    bbox<float> bounds;

    void init(vec<float> grav);


};

}
#endif
