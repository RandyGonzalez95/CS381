/*
 * gameMgr.h
 *
 *  Created on: Mar 11, 2017
 *      Author: sushil
 */

#ifndef GAMEMGR_H_
#define GAMEMGR_H_

#include <mgr.h>
#include <OgreVector3.h>


class GameMgr : public Mgr
{

private:
	void createEnts();
	void createSky();
	void createGround();
	void createWall();
	void hitPaddle();
	void moveAI(float dt);

	Ogre::Vector3 ball, leftPaddle, rightPaddle; //position of all objects
	Ogre::Vector3 dirVec;


public:
	GameMgr(Engine *engine);
	~GameMgr();
	void init();
	void tick(float dt);
	void loadLevel();
	void stop();


};



#endif /* GAMEMGR_H_ */
