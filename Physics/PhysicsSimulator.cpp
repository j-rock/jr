#include "PhysicsSimulator.h"

namespace jr
{

void PhysicsSimulator::init(vec<float> grav)
{
  b2Vec2 gravity(grav.x, grav.y);
  world = new b2World(gravity);
  listener = new CollideListener();
  world->SetContactListener(listener);
}

PhysicsSimulator::PhysicsSimulator(vec<float> grav)
  : bounds(FLT_MAX,FLT_MIN,FLT_MAX,FLT_MIN)
{
  init(grav);
}

PhysicsSimulator::PhysicsSimulator()
  : bounds(FLT_MAX,FLT_MIN,FLT_MAX,FLT_MIN)
{
  vec<float> grav(0.0f, -19.81);
  init(grav);
}

PhysicsSimulator::~PhysicsSimulator()
{
  delete listener;
  delete world;
}

void PhysicsSimulator::add(Entity* ent)
{
  PhysicsComponent* pc = ent->getPhysicsComponent();
  pc->enterWorld(world);
  pc->setUserData((void*)ent);
  bounds.expandWith(pc->getBounds());
}

void PhysicsSimulator::remove(Entity* ent)
{
  ent->getPhysicsComponent()->leaveWorld();
}

bbox<float> PhysicsSimulator::getBounds()
{
  return bounds;
}

void PhysicsSimulator::update()
{
  float32 timeStep = 1/60.0;
  int32 velocityIterations = 8;
  int32 positionIterations = 3;
  world->Step(timeStep, velocityIterations, positionIterations);
}

}

