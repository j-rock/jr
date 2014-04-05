#include "ContactMessenger.h"

namespace jr
{

void ContactMessenger::BeginContact(b2Contact* contact)
{
  Entity* entA = (Entity*)contact->GetFixtureA()->GetBody()->GetUserData();
  Entity* entB = (Entity*)contact->GetFixtureB()->GetBody()->GetUserData();
  Message* mesgA = entA->getCollideMessage();
  Message* mesgB = entB->getCollideMessage();
  entA->takeMessage(mesgB);
  entB->takeMessage(mesgA);
}

void ContactMessenger::EndContact(b2Contact* contact)
{
  Entity* entA = (Entity*)contact->GetFixtureA()->GetBody()->GetUserData();
  Entity* entB = (Entity*)contact->GetFixtureB()->GetBody()->GetUserData();
  Message* mesgA = entA->getUncollideMessage();
  Message* mesgB = entB->getUncollideMessage();
  entA->takeMessage(mesgB);
  entB->takeMessage(mesgA);
}

}

