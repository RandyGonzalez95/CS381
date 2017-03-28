/*
 * GameMgr.h
 *
 *  Created on: Mar 27, 2017
 *      Author: randygonzalez
 */

#ifndef INCLUDE_GAMEMGR_H_
#define INCLUDE_GAMEMGR_H_

#include <mgr.h>

class Engine;

class GameMgr : public Mgr
{
public:
	GameMgr(Engine *eng);
	virtual ~GameMgr();

	// Create The Scene
	void createScene();
	void createEntities();
	void MakeGround();
	void MakeSky();
	void MakeFog();

	// Inherited Implementations
	void tick(float dt);
	void init();
	void loadLevel();
	void stop();

private:

};


#endif /* INCLUDE_GAMEMGR_H_ */
