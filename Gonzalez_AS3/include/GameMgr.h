/*
 * GameMgr.h
 *
 *  Created on: Mar 27, 2017
 *      Author: randygonzalez
 */

#ifndef INCLUDE_GAMEMGR_H_
#define INCLUDE_GAMEMGR_H_

#include <mgr.h>

class GameMgr : public Mgr
{
public:
	GameMgr(Engine *eng);
	virtual ~GameMgr();

	void createScene();

private:

};


#endif /* INCLUDE_GAMEMGR_H_ */
