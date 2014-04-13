#include "CollideListener.h"

namespace jr
{

void CollideListener::BeginContact(b2Contact* contact)
{
  b2Fixture* fixA = contact->GetFixtureA();
  b2Fixture* fixB = contact->GetFixtureB();
  void* voidA = fixA->GetBody()->GetUserData();
  void* voidB = fixB->GetBody()->GetUserData();
  Entity* entA = (Entity*)voidA; //TODO - If can't dyn_cast, then what?
  Entity* entB = (Entity*)voidB;
  entA->collideWith(entB);
  entB->collideWith(entA);
}

void CollideListener::EndContact(b2Contact* contact)
{
  b2Fixture* fixA = contact->GetFixtureA();
  b2Fixture* fixB = contact->GetFixtureB();
  void* voidA = fixA->GetBody()->GetUserData();
  void* voidB = fixB->GetBody()->GetUserData();
  Entity* entA = (Entity*)voidA;
  Entity* entB = (Entity*)voidB;
  entA->endCollideWith(entB);
  entB->endCollideWith(entA);
}

}

