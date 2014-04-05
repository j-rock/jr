#include "LogicState.h"

namespace jr
{

LogicState::~LogicState()
{
}

void LogicState::pop(LogicComponent* lcomp)
{
  lcomp->pop();
}

void LogicState::push(LogicComponent* lcomp, LogicState* state)
{
  lcomp->push(state);
}

}

