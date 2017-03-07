/*
 * Aspects.h
 *
 *  Created on: Mar 6, 2017
 *      Author: randygonzalez
 */

#ifndef INCLUDE_ASPECTS_H_
#define INCLUDE_ASPECTS_H_

#include "Entity381.h"

class Aspect
{
public:
	Aspect(Entity381* ent);
	virtual ~Aspect();

	virtual void Tick(float dt) = 0;

private:
	Entity381 *entity;
};



#endif /* INCLUDE_ASPECTS_H_ */
