#include <Box2D/Box2D.h>
#include <iostream>


int main()
{
  //set up world
  b2Vec2 gravity(0.0f, -9.81f);
  b2World world(gravity);

  //set up ground
  b2BodyDef groundDef;
  groundDef.position.Set(0.0f, -10.0f);
  b2Body* groundBody = world.CreateBody(&groundDef);
  b2PolygonShape groundBox;
  groundBox.SetAsBox(50.0f, 10.0f);
  groundBody->CreateFixture(&groundBox, 0.0f);

  //set up fun object
  b2BodyDef bDef;
  bDef.type = b2_dynamicBody;
  bDef.fixedRotation = true;
  bDef.position.Set(0.0f, 4.0f);
  b2Body* body = world.CreateBody(&bDef);
  b2PolygonShape dBox;
  dBox.SetAsBox(1.0f, 1.0f);
  b2FixtureDef fixD;
  fixD.shape = &dBox;
  fixD.density = 1.0f;
  fixD.friction = 0.3f;
  body->CreateFixture(&fixD);

  //gearing up for simulation
  float32 timeStep = 1.0f / 60.0f;
  int32 velocityIterations = 8;
  int32 positionIterations = 3;
  for(int32 i=0; i<60; i++){
    world.Step(timeStep, velocityIterations, positionIterations);
    b2Vec2 position = body->GetPosition();
    float32 angle = body->GetAngle();
    std::cout << position.x << " " << position.y << " " << angle << std::endl;
  }

  return 0;
}

