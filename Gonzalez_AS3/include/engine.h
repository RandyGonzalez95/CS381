/*
 * engine.h
 *
 *  Created on: Mar 27, 2017
 *      Author: randygonzalez
 */

#ifndef INCLUDE_ENGINE_H_
#define INCLUDE_ENGINE_H_

#include <GfxMgr.h>
#include <InputMgr.h>
#include <EntityMgr.h>
#include <GameMgr.h>

class Engine
{
public:
	Engine();
	~Engine();


	EntityMgr*      entityMgr;
	GfxMgr*         gfxMgr;
	InputMgr*       inputMgr;
	GameMgr*        gameMgr;
	//SelectionMgr* selectionMgr;
	//ControlMgr*   controlMgr;

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
