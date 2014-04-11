#include <vector>
#include <jr/Game.h>
#include <jr/Entity.h>
#include "Entity/Entity.h"

using std::vector;

int main()
{
  vector<jr::Entity*> ents;
  ents.push_back(new simple::Wall(20.0, 1.0, 11.0, 5.0));
  ents.push_back(new simple::Wall(20.0, 1.0, -7.0, -5.0));
  ents.push_back(new simple::Box(5.0, 0.0, 40.0));

  ents.push_back(new simple::Cursor(-30.0, -10.0));
  ents.push_back(new simple::Cursor(30.0, 10.0));
  ents.push_back(new simple::Cursor(0.0, 10.0));

  jr::Game g(ents);
  g.play();

  return 0;
}
