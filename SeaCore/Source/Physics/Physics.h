#pragma once
#include <Box2D/Dynamics/b2World.h>
#include "Helpers/Singleton.h"


class PhysicsWorld : public sea_core::Singleton<PhysicsWorld>
{	
public:
	explicit PhysicsWorld();
	~PhysicsWorld();
	b2World* GetWorld() const { return m_pWorld; };

private:
	b2World* m_pWorld;
};

struct 
{
	b2World* operator()() const { return PhysicsWorld::GetInstance().GetWorld(); }
} Physics;
