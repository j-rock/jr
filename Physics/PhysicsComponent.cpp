#include "PhysicsComponent.h"

namespace jr
{

PhysicsComponent::~PhysicsComponent()
{
  //physics simulation takes care of deallocating b2Body
}

void PhysicsComponent::leaveWorld()
{
  body->GetWorld()->DestroyBody(body);
}

void PhysicsComponent::setPosition(vec<float> pos)
{
  b2Vec2 position(pos.x, pos.y);
  body->SetTransform(position, getAngle());
}

void PhysicsComponent::setVelocity(vec<float> vel)
{
  b2Vec2 velocity(vel.x, vel.y);
  body->SetLinearVelocity(velocity);
}

void PhysicsComponent::setAngle(float angle)
{
  body->SetTransform(body->GetPosition(), angle);
}

bbox<float> PhysicsComponent::getBounds()
{
  b2AABB aabb;
  b2Transform t;
  t.SetIdentity();
  aabb.lowerBound = b2Vec2(FLT_MAX,FLT_MAX);
  aabb.upperBound = b2Vec2(FLT_MIN,FLT_MIN); 

  b2Fixture* fixture = body->GetFixtureList();
  while(fixture) {
    const b2Shape *shape = fixture->GetShape();
    const int childCount = shape->GetChildCount();

    for(int child=0; child<childCount; child++){
      const b2Vec2 r(shape->m_radius, shape->m_radius);
      b2AABB shapeAABB;
      shape->ComputeAABB(&shapeAABB, t, child);
      shapeAABB.lowerBound = shapeAABB.lowerBound + r;
      shapeAABB.upperBound = shapeAABB.upperBound - r;
      aabb.Combine(shapeAABB);
    }
    fixture = fixture->GetNext();
  }

  b2Vec2 pos = body->GetPosition();
  bbox<float> b(aabb.lowerBound.x + pos.x
               ,aabb.upperBound.x + pos.x
               ,aabb.lowerBound.y + pos.y
               ,aabb.upperBound.y + pos.y);
  return b;
}

vec<float> PhysicsComponent::getPosition()
{
  b2Vec2 pos = body->GetPosition();
  vec<float> vecPos(pos.x, pos.y);
  return vecPos;
}

vec<float> PhysicsComponent::getVelocity()
{
  b2Vec2 vel = body->GetLinearVelocity();
  vec<float> vecVel(vel.x, vel.y);
  return vecVel;
}

float PhysicsComponent::getAngle()
{
  return body->GetAngle();
}

}

