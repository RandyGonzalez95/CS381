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
private:

protected:

public:

	Entity381();
	~Entity381();
	void Tick(float dt);
	void DefaultInit();


	std::list<Aspect*> aspects;
};



#endif /* ENTITY381_H_ */
