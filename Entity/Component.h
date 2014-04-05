#ifndef ENTITY_COMPONENT_H
#define ENTITY_COMPONENT_H

#include "../Utils/vec.h"

namespace jr
{

using Utils::vec;

class Component
{
	public:
		virtual ~Component();
    virtual void setPosition(vec<float> pos) = 0;
    virtual void setVelocity(vec<float> vel) = 0;
    virtual void setAngle(float angle) = 0;
};

}
#endif
