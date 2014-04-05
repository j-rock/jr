#include "MessageComparer.h"

namespace jr
{

MessageComparer::MessageComparer()
{
}

MessageComparer::~MessageComparer()
{
}

bool MessageComparer::operator()(void* a, void* b)
{
  return ((Message*)a)->priority > ((Message*)b)->priority;
}


}

