/*
 * Entity381.cpp
 *
 *  Created on: Feb 22, 2017
 *      Author: sushil
 */

#include <Entity381.h>
#include <Aspect.h>

Entity381::Entity381(EntityType type, Ogre::Vector3 pos) : ogreSceneNode(0), ogreEntity(0)
{
	entityType = type;
	this->position = pos;
	this->aspects.clear();
	Renderable *r = new Renderable(this);
	Physics *p = new Physics(this);
	UnitAI *ai = new UnitAI(this);

	this->aspects.push_back(r);
	this->aspects.push_back(p);
	this->aspects.push_back(ai);
	speed = 10;

}

Entity381::~Entity381()
{
	this->aspects.clear();
}

void Entity381::Tick(float dt)
{
	// Loop through aspects
	for(unsigned int i = 0; i< aspects.size(); i++)
		aspects[i]->Tick(dt);
}

Ball::Ball(Ogre::Vector3 pos) : Entity381(EntityType::Ball, pos)
{

}

Ball::~Ball(){}


void Ball::MoveBall()
{

}

void Ball::UpdateSpeed()
{

}

Paddle::Paddle(Ogre::Vector3 pos): Entity381(EntityType::Paddle, pos)
{
	this->meshfile = "cube.mesh";
}

Paddle::~Paddle()
{

}


void Paddle::MovePaddle(Ogre::Vector3 dir)
{

}









