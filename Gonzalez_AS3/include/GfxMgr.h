/*
 * GfxMgr.h
 *
 *  Created on: Mar 27, 2017
 *      Author: randygonzalez
 */

#ifndef INCLUDE_GFXMGR_H_
#define INCLUDE_GFXMGR_H_

#include "mgr.h"

class Engine;

class GfxMgr : public Mgr
{
public:
	// Constructor/Destructor
	GfxMgr(Engine *eng);
	virtual ~GfxMgr();

	// Override From Parent Class
	virtual void init();
	virtual void tick(float dt);
	virtual void loadLevel();
	virtual void stop();

	// Configure and Setup Ogre Graphics Engine
    bool setup();
    bool configure(void);
    void chooseSceneManager(void);
    void createCamera(void);
    void createViewports(void);
    void setupResources(void);
    void loadResources(void);

	// All Graphics Management
    Ogre::Root*                 mRoot;
    Ogre::Camera*               mCamera;
    Ogre::SceneManager*         mSceneMgr;
    Ogre::RenderWindow*         mWindow;
    Ogre::String                mResourcesCfg;
    Ogre::String                mPluginsCfg;

    Ogre::OverlaySystem*        mOverlaySystem;

    // OgreBites
    OgreBites::SdkCameraMan*    mCameraMan;     	// Basic camera controller
    OgreBites::ParamsPanel*     mDetailsPanel;   	// Sample details panel
    bool                        mCursorWasVisible;	// Was cursor visible before dialog appeared?
    bool                        mShutDown;

    Ogre::String                 m_ResourcePath;

private:


};



#endif /* INCLUDE_GFXMGR_H_ */
