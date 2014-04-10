#include "GraphicsComponent.h"

namespace jr
{

GraphicsComponent::GraphicsComponent()
{
}

GraphicsComponent::~GraphicsComponent()
{
}

void GraphicsComponent::setDrawer(Drawer* d)
{
  drawer = d;
}

}
