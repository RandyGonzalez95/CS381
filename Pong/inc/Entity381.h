/*
 * Entity.h
 *
 *  Created on: Feb 22, 2017
 *      Author: sushil
 */

#ifndef ENTITY381_H_
#define ENTITY381_H_

#include <OgreVector3.h>
#include <OgreSceneNode.h>

#include <Types.h>


class Aspect;

class Entity381
{

public:

	Entity381(EntityType type, Ogre::Vector3 pos);
	virtual ~Entity381();
	void Tick(float dt); // loops through list of aspects
	void DefaultInit();
	std::vector<Aspect*> aspects;

	// Ogre Stuff
	Ogre::SceneNode *ogreSceneNode;
	Ogre::Entity* ogreEntity;


	// Identifying type
	EntityType entityType;


	// material file
	std::string meshfile;

	// Static
	Ogre::Vector3 velocity = Ogre::Vector3::ZERO;
	Ogre::Vector3 position;
	float speed;

	Ogre::Vector3 pos;
	Ogre::Vector3 direction;

	//selection
	bool isSelected;
	bool didSelectSoundPlay;

	//sound
	std::string soundFile;
	bool playSound;
	unsigned int audioId;

	// Score
	int score1 = 0, score2 = 0;

};

class Ball : public Entity381
{
public:
	Ball(Ogre::Vector3 pos);
	~Ball();

	void Tick(float dt);
	void MoveBall(float dt);
	void UpdateSpeed();


};

class Paddle : public Entity381
{
public:
	Paddle(Ogre::Vector3 pos);
	~Paddle();

	void MovePaddle(Ogre::Vector3 dir);

};

class Wall : public Entity381
{
public:
	Wall(Ogre::Vector3 pos);
	~Wall();

};



#endif /* ENTITY381_H_ */
