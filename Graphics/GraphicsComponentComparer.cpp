#include "GraphicsComponentComparer.h"

namespace jr
{

GraphicsComponentComparer::GraphicsComponentComparer()
{
}

GraphicsComponentComparer::~GraphicsComponentComparer()
{
}

bool GraphicsComponentComparer::operator()(void* a, void* b)
{
  return ((GraphicsComponent*)a)->getPriority() > ((GraphicsComponent*)b)->getPriority();
}

}

