#ifndef ENTITY_CURSOR_H
#define ENTITY_CURSOR_H

#include <jr/Entity.h>
#include <jr/Utils.h>
#include "../Graphics/NoGraphics.h"
#include "../Physics/NoPhysics.h"

namespace simple
{

class Cursor : public jr::Entity
{
	public:
		Cursor(float x0, float y0);
		~Cursor();
    virtual void update();
};

}
#endif

