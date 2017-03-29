/*
 * engine.cpp
 *
 *  Created on: Mar 28, 2017
 *      Author: randy
 */
#include <engine.h>

Engine::Engine()
{
	keepRunning = false;
	gfxMgr = 0;
	inputMgr = 0;
	entityMgr = 0;
	gameMgr = 0;

}

Engine::~Engine()
{

}


void Engine::init()
{
	keepRunning = true;
	// construct
	gfxMgr = new GfxMgr(this);
	inputMgr = new InputMgr(this);
	entityMgr = new EntityMgr(this);
	gameMgr = new GameMgr(this);

	// initialize
	gfxMgr->init();
	inputMgr->init();
	entityMgr->init();
	gameMgr->init();
	//gfxMgr->mRoot->startRendering();


}

void Engine::run()
{

	Ogre::Timer* timer = new Ogre::Timer();
	float oldTime = timer->getMilliseconds()/1000.0f;
	float newTime;
	float dt = 0.001f;
	while(keepRunning)
	{
		//std::cerr<<"IN THE RUNNING LOOP"<<std::endl;
		newTime = timer->getMilliseconds()/1000.0f;
		dt = newTime - oldTime;
		oldTime = newTime;
		tickAll(dt);
	}
	shutdown();

	return;
}

void Engine::tickAll(float dt)
{
	gfxMgr->tick(dt);
	inputMgr->tick(dt);
	entityMgr->tick(dt);
	gameMgr->tick(dt);
}

void Engine::stop()
{

}

void Engine::shutdown()
{
	delete gfxMgr;
}




