#include "SeaCore_pch.h"
#include "Physics.h"


PhysicsWorld::PhysicsWorld()
	: m_pWorld(new b2World(b2Vec2(0.0f, -9.81f)))
{
}

PhysicsWorld::~PhysicsWorld()
{
	delete m_pWorld;
}
