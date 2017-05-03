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

	this->playSound = false;

	this->soundFile = "Boat-Sound.wav";
	this->audioId = 0;
	DefaultInit();
}

Entity381::~Entity381()
{
	this->aspects.clear();
}

void Entity381::DefaultInit(){
	this->soundFile = "Boat-Sound.wav";
	this->audioId = 0;
}

void Entity381::Tick(float dt)
{
	// Loop through aspects
	for(unsigned int i = 0; i< aspects.size(); i++)
		aspects[i]->Tick(dt);
}

Ball::Ball(Ogre::Vector3 pos) : Entity381(EntityType::Ball, pos)
{
	this->meshfile = "sphere.mesh";
	speed = 600;
	direction = Ogre::Vector3(1,-1,0);
}

Ball::~Ball(){}

void Ball::Tick(float dt)
{
	MoveBall(dt);
}


void Ball::MoveBall(float dt)
{
	this->ogreSceneNode->translate( (direction*(speed*dt)));
	this->pos = this->ogreSceneNode->getPosition();


	// Check Left Side
	if((pos.x - 40) <= -250)
	{
		// Reset the Ball
		ogreSceneNode->setPosition(400, 0, 0);
		direction *= Ogre::Vector3(-1, 1, 1 );

		// Update Score
		score2++;
	}
	// Check Right Wall
	else if((pos.x + 40) >= 1050)
	{
		ogreSceneNode->setPosition(400, 0, 0);
		direction *= Ogre::Vector3(-1, 1, 1 );

		// Update Score
		score1++;
	}
	//Check Top
	else if((pos.y +40) >= 400 && direction.y > 0)
	{
		ogreSceneNode->setPosition(pos.x, 360, pos.z);
		direction *= Ogre::Vector3(1, -1, 1 );

	}
	// Check Bottom
	else if((pos.y -40 ) <= -400 && direction.y < 0)
	{
		ogreSceneNode->setPosition(pos.x, -360, pos.z);
		direction *= Ogre::Vector3(1, -1, 1 );
	}

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

Wall::Wall(Ogre::Vector3 pos) : Entity381(EntityType::Wall, pos){
	this->meshfile = "cube.mesh";
}
Wall::~Wall(){}








