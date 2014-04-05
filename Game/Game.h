#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <vector>
#include <SFML/System.hpp>
#include "../Graphics/Renderer.h"
#include "../Entity/Entity.h"
#include "Simulator.h"

namespace jr
{

using std::vector;
using Utils::bbox;

class Game
{
  public:
    Game();
    Game(vector<Entity*>& ents);
    virtual ~Game();

    void play();

  private:
    Simulator* simulator;
    Renderer* renderer;

    void init(vector<Entity*>& ents);
    void sleep(sf::Time elapsed);
};

}
#endif
