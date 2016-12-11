#include <SFML/System.hpp>
#include "Box2D-master/Box2D/Box2D/Box2D.h"

class RectBody{
  b2BodyDef bodyDef;
  b2PolygonShape dynamicBox;
  b2FixtureDef fixtureDef;
  public:
    void init(b2World* world);
    b2Vec2 getposition();
    b2Body* body;
};

class CircleBody{
  b2BodyDef bodyDef;
  b2PolygonShape circleShape;
  b2FixtureDef fixtureDef;
  public:
    void init(b2World* world);
    b2Vec2 getposition();
    b2Body* body;
};

