#ifndef GRAPHICS_GRAPHICSCOMPONENTCOMPARER_H
#define GRAPHICS_GRAPHICSCOMPONENTCOMPARER_H

#include "../Utils/Comparer.h"

namespace jr
{

class GraphicsComponentComparer : public Comparer
{
	public:
		GraphicsComponentComparer();
		~GraphicsComponentComparer();
    virtual bool operator()(void* a, void* b);
};

}

#include "GraphicsComponent.h"
#endif
