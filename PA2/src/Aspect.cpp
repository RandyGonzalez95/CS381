/*
 * Aspect.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: randygonzalez
 */


#include "Aspect.h"

Aspect::Aspect()
{

}

Aspect::Aspect(Entity381* ent)
{

}

Aspect::~Aspect()
{

}

void Aspect::Tick(float dt)
{

}

PhysicsAspect::PhysicsAspect(void)
{

}


PhysicsAspect::~PhysicsAspect()
{

}

void PhysicsAspect::UpdatePostion()
{

}

void PhysicsAspect::Tick(float dt)
{
	//position = position + (velocity * fe.timeSinceLastFrame);
	//entity->position = entity->position + (entity->velocity *dt);
}

RenderableAspect::RenderableAspect()
{

}

RenderableAspect::~RenderableAspect()
{

}

void RenderableAspect::RenderBoat()
{

}


void RenderableAspect::Tick(float dt)
{

}
