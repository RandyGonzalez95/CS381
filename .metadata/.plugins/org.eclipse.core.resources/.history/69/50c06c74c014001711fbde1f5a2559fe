/*
 * aspect.h
 *
 *  Created on: Mar 27, 2017
 *      Author: randygonzalez
 */

#ifndef INCLUDE_ASPECT_H_
#define INCLUDE_ASPECT_H_

#include <Entity381.h>

class Aspect
{

public:
	Aspect(Entity381* ent);
	virtual ~Aspect();

	virtual void Tick(float dt) = 0;
	Entity381 *entity;


};

class Renderable: public Aspect
{
public:
	Renderable(Entity381* ent);
	~Renderable();
	virtual void Tick(float dt);
};


class Physics: public Aspect
{
public:
	Physics(Entity381* ent);
	~Physics();
	virtual void Tick(float dt);
};



#endif /* INCLUDE_ASPECT_H_ */
