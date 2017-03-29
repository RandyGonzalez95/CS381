/*
 * engine.h
 *
 *  Created on: Mar 28, 2017
 *      Author: randy
 */
#ifndef INCLUDE_ENGINE_H_
#define INCLUDE_ENGINE_H_

#include <gfxMgr.h>
#include <InputMgr.h>
#include <EntityMgr.h>
#include <GameMgr.h>

class Engine
{
public:
	Engine();
	~Engine();

	GfxMgr* gfxMgr;
	InputMgr *inputMgr;
	EntityMgr* entityMgr;
	GameMgr* gameMgr;



	void init();
	void run();
	void tickAll(float dt);
	void stop();
	void shutdown();

	//
	bool keepRunning;

private:
};



#endif /* INCLUDE_ENGINE_H_ */
