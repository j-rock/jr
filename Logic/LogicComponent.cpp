#include "LogicComponent.h"
#include <iostream>

namespace jr
{

LogicComponent::LogicComponent()
{
  doUpdate = false;
  data[current()] = 0;
  data[next()] = 0;
}

LogicComponent::~LogicComponent()
{
  int nextBuffer = next();
  for(std::size_t i=0; i<states[nextBuffer].size(); i++)
    delete states[nextBuffer][i];
  
  delete data[0];
  delete data[1];
}

void LogicComponent::setSimHandler(MessageHandler* sim)
{
  SIMULATOR_HANDLER = subscribe(sim);
}

void LogicComponent::setHandlers(MessageHandler* pcomp, MessageHandler* gcomp)
{
  PHYSICS_COMP_HANDLER = subscribe(pcomp);
  GRAPHICS_COMP_HANDLER = subscribe(gcomp);
}

void LogicComponent::update()
{
  copyOver();
  std::cout << "BUNNIES 1" << std::endl;
  processMessages();
  std::cout << "BUNNIES 3" << std::endl;
  if(!doUpdate){
    doUpdate = true;
    return;
  }
  LogicState* currentState = getCurrentState();
  currentState->setData(data[next()]);
  std::cout << "BUNNIES 4" << std::endl;
  currentState->update(this);
}

void LogicComponent::setPosition(vec<float> pos)
{
  for(int i=0; i<5; i++){
    std::cout << "BUNNIES" << std::endl;
    std::cout << "EYEBALL " << i << std::endl;
  }
  getCurrentState()->setPosition(pos);
  std::cout << "LOGIC SET POSITION" << std::endl;
}

void LogicComponent::setVelocity(vec<float> vel)
{
  getCurrentState()->setVelocity(vel);
}

void LogicComponent::setAngle(float angle)
{
  getCurrentState()->setAngle(angle);
}

Message* LogicComponent::getCollideMessage()
{
  return getCurrentState()->getCollideMessage();
}

Message* LogicComponent::getUncollideMessage()
{
  return getCurrentState()->getUncollideMessage();
}

int LogicComponent::bufferIndex = 0;

void LogicComponent::init()
{
  bufferIndex = 0;
}

void LogicComponent::swap()
{
  bufferIndex = next();
}

void LogicComponent::copyOver()
{
  int nextBuffer = next();
  int curr = current();

  states[nextBuffer].clear();
  std::size_t size = states[curr].size(); 
  for(std::size_t i=0; i<size; i++)
    states[nextBuffer].push_back(states[curr][i]);

  if(data[nextBuffer])
    delete data[nextBuffer];
  if(!data[curr])
    data[curr] = getNewDefaultData();
  data[nextBuffer] = data[curr]->clone();
}

LogicState* LogicComponent::safePop()
{
  if(states[next()].empty())
    return getNewDefaultState();
  LogicState* ret = states[next()].back();
  states[next()].pop_back();
  return ret;
}

void LogicComponent::pop()
{
  int nextBuffer = next();
  if(states[nextBuffer].empty())
    return;
  delete states[nextBuffer].back();
  states[nextBuffer].pop_back();
}

void LogicComponent::push(LogicState* state)
{
  vector<LogicState*>* s = &(states[next()]);
  if(s->empty())
    s->push_back(state);
  else
    s->insert(--(s->end()), state);
}

void LogicComponent::disableUpdate()
{
  doUpdate = false;
}

LogicState* LogicComponent::getCurrentState()
{
  if(states[current()].empty())
    return getNewDefaultState();
  return states[current()].back();
}

int LogicComponent::current()
{
  return bufferIndex;
}

int LogicComponent::next()
{
  return 1 - current();
}

void LogicComponent::processMessages()
{
  LogicState* currentState = getCurrentState();
  while(!messages.empty()){
    Message* m = messages.top();
    messages.pop();
    m->actor = currentState;
    m->process();
    delete m;
  }
}

}


