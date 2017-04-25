/*
 * UnitAI.h
 *
 *  Created on: Mar 28, 2017
 *      Author: sushil
 */

#ifndef UNITAI_H_
#define UNITAI_H_

#include <Aspect.h>
#include <Command.h>

class UnitAI: public Aspect {

public:

	UnitAI(Entity381* ent);
	~UnitAI();

	void Tick(float dt);
	void SetCommand(Command *c);
	void AddCommand(Command *c);

};





#endif /* UNITAI_H_ */
