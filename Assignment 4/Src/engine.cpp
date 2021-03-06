/*
 * engine.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: sushil
 */

#include "../Inc/engine.h"

#include <OgreTimer.h>

Engine::Engine(){
	gfxMgr = 0;
	inputMgr = 0;
	entityMgr = 0;
	gameMgr = 0;
	//moveTo = 0;
	keepRunning = true;

}

Engine::~Engine(){

}

void Engine::stop(){
	keepRunning = false;
}

void Engine::init(){
// construct
	gfxMgr    = new GfxMgr(this);
	std::cout << "Constructed GfxMgr" << std::endl;
	inputMgr = new InputMgr(this);
	entityMgr = new EntityMgr(this);
	gameMgr = new GameMgr(this);
	//command = new Command(this, );
	//moveTo = new MoveTo(this->gameMgr->, this->inputMgr->point);
// initialize
	gfxMgr->init();
	inputMgr->init();
	entityMgr->init();
	gameMgr->init();
	//command->init();
	//moveTo->init();
// load level to play
	gfxMgr->loadLevel();
	inputMgr->loadLevel();
	entityMgr->loadLevel();
	gameMgr->loadLevel();
}

void Engine::tickAll(float dt){
	gfxMgr->tick(dt);
	inputMgr->tick(dt);
	entityMgr->tick(dt);
	gameMgr->tick(dt);
	//command->tick(dt);
	//moveTo->tick(dt);
}

void Engine::shutdown(){
	inputMgr->stop();
	gfxMgr->stop();
	entityMgr->stop();
	gameMgr->stop();
}
void Engine::run(){
	Ogre::Timer* timer = new Ogre::Timer();
	std::cout << "Got ogre timer" << std::endl;
	float oldTime = timer->getMilliseconds()/1000.0f;
	std::cout << "Time: " << oldTime << std::endl;
	float newTime;
	float dt = 0.001f;
	std::cout << "Entering while loop" << std::endl;
	while(keepRunning){
		newTime = timer->getMilliseconds()/1000.0f;
		dt = newTime - oldTime;
		oldTime = newTime;
//		std::cout << "dt: " << dt << std::endl;
		tickAll(dt);
	}
	shutdown();

	return;
}
