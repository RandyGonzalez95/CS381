/*
 * Command.cpp
 *
 *  Created on: Mar 28, 2017
 *      Author: sushil
 */

#include <Command.h>
#include <math.h>
#include <OgreMath.h>

Command::Command(Entity381 *ent)
{
	entity = ent;
}

Command::~Command()
{

}

void Command::init()
{

}

void Command::tick(float dt)
{

}

bool Command::done()
{
	return true;
}










