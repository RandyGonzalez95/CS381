/*
 * mgr.h
 *
 *  Created on: Mar 9, 2017
 *      Author: sushil
 */

#ifndef MGR_H_
#define MGR_H_

class Engine;

class Mgr
{
public:
	Engine *engine;

	Mgr(Engine *eng);
	virtual ~Mgr();

	virtual void tick(float dt) = 0;
	virtual void init() = 0;
	virtual void loadLevel() = 0;
	virtual void stop() = 0;
};



#endif /* MGR_H_ */
