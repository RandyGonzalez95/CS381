/*
 * gameMgr.h
 *
 *  Created on: Mar 11, 2017
 *      Author: sushil
 */

#ifndef GAMEMGR_H_
#define GAMEMGR_H_

#include <mgr.h>
#include <OgreMeshManager.h>


class GameMgr : public Mgr {

private:
	void createEnts();
	void createSky();
	void createGround();


public:
	GameMgr(Engine *engine);
	~GameMgr();
	void init();
	void tick(float dt);
	void loadLevel();
	void stop();

	Ogre::Plane ocean;

};



#endif /* GAMEMGR_H_ */
