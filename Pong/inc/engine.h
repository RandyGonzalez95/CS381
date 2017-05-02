/*
 * engine.h
 *
 *  Created on: Mar 9, 2017
 *      Author: sushil
 */

#ifndef ENGINE_H_
#define ENGINE_H_

#include <GfxMgr.h>
#include <inputMgr.h>
#include <EntityMgr.h>
#include <gameMgr.h>
#include <UiMgr.h>
#include <SoundMgr.h>

class Engine
{
private:
public:
	Engine();
	~Engine();


	EntityMgr*      entityMgr;
	GfxMgr*         gfxMgr;
	InputMgr*       inputMgr;
	GameMgr*        gameMgr;
	UiMgr*			uiMgr;
	OgreSND::SoundMgr*		soundMgr;
	//SelectionMgr* selectionMgr;
	//ControlMgr*   controlMgr;

	void init();
	void run();
	void tickAll(float dt);
	void stop();
	void shutdown();

	//
	bool keepRunning;


};



#endif /* ENGINE_H_ */
