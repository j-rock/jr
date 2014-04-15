#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <vector>
#include <SFML/System.hpp>
#include "../Graphics/Renderer.h"
#include "../Entity/Entity.h"
#include "../Entity/EntityStore.h"
#include "../Physics/PhysicsSimulator.h"

namespace jr
{

using std::vector;
using Utils::bbox;

class Game
{
  public:
    Game(vector<Entity*>& ents);
    virtual ~Game();

    void play();

  private:
    Renderer* renderer;
    EntityStore* entities;
    PhysicsSimulator* physicsSim;

    void add(Entity* ent);
    void remove(Entity* ent);
    void update();
    void sleep(sf::Time elapsed);

    void addChildren(vector<Entity*>& children);
    void addParentsChildren(vector<Entity*>& parents);
    void removeDeletes(vector<Entity*>& deletes);
    void switchContext(vector<Entity*> ents);
};

}
#endif
