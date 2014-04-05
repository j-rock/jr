#include "Game.h"

#define MS_PER_UPDATE 16

namespace jr
{

void Game::init(vector<Entity*>& ents)
{
  renderer = new Renderer(900, 550, "Game");
  simulator = new Simulator(renderer->getMessageHandler());
  for(std::size_t i=0; i<ents.size(); i++)
    simulator->add(ents[i]);
}

Game::Game()
{
  vector<Entity*> ents;
  init(ents);
}

Game::Game(vector<Entity*>& ents)
{
  init(ents);
}

Game::~Game()
{
  delete simulator;
  delete renderer;
}

void Game::play()
{
  sf::Clock clock;
  while (renderer->isWindowOpen()){
    simulator->update();
    sleep(clock.restart());
    renderer->render();
    renderer->pollEvents();
  }
}

void Game::sleep(sf::Time elapsed)
{
  sf::Time maxSleep = sf::milliseconds(16); //for 60 fps
  sf::Time sleepTime;
  if(maxSleep > elapsed)
    sleepTime = maxSleep - elapsed;
  else
    sleepTime = sf::Time::Zero;
  sf::sleep(sleepTime);
}

}
