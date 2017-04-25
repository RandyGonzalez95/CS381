/*
 * Command.h
 *
 *  Created on: Mar 28, 2017
 *      Author: sushil
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include <Entity381.h>
#include <OgreVector3.h>

class Command {

public:
	Command(Entity381* ent);
	virtual ~Command();

	virtual void init();
	virtual void tick(float dt);
	virtual bool done();

	Entity381* entity;


};



#endif /* COMMAND_H_ */
