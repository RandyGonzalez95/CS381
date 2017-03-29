/*
 * InputMgr.h
 *
 *  Created on: Mar 28, 2017
 *      Author: randy
 */

#ifndef INCLUDE_INPUTMGR_H_
#define INCLUDE_INPUTMGR_H_

#include <mgr.h>

class Engine;

class InputMgr : public Mgr, public Ogre::WindowEventListener, public Ogre::FrameListener, public OIS::KeyListener, public OIS::MouseListener, OgreBites::SdkTrayListener
{
public:
	InputMgr(Engine* eng);
	virtual ~InputMgr();

	virtual void init();
	virtual void tick(float dt);
	virtual void loadLevel();
	virtual void stop();

	// Key Handlers for Camera And Velocity
	void updateCamera(const Ogre::FrameEvent &fe);

	void updateSelection(float dt);
	void updateDesiredSpeedHeading(float dt);

	// Set up Input System
	void createFrameListener(void);

	virtual bool frameRenderingQueued(const Ogre::FrameEvent& fe);

	// Need to Override
	virtual bool keyPressed(const OIS::KeyEvent &arg);
    virtual bool keyReleased(const OIS::KeyEvent &arg);
    virtual bool mouseMoved(const OIS::MouseEvent &arg);
    virtual bool mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
    virtual bool mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
    // Adjust mouse clipping area
    virtual void windowResized(Ogre::RenderWindow* rw);
    // Unattach OIS before window shutdown (very important under Linux)
    virtual void windowClosed(Ogre::RenderWindow* rw);


    OgreBites::InputContext  	mInputContext;
    OgreBites::SdkTrayManager*	mTrayMgr;
    OgreBites::ParamsPanel*     mDetailsPanel;   	// Sample details panel
    OgreBites::SdkCameraMan*	mCameraMan;

    OIS::InputManager*			mInputManager;
    OIS::Mouse*					mMouse;
    OIS::Keyboard*				mKeyboard;

    Ogre::SceneNode* 			cameraNode;

    float keyboardTimer;
    float selectionTimer;
    const float selectionTime = 0.2f;
    const float keyTime = 0.2f;
private:

};



#endif /* INCLUDE_INPUTMGR_H_ */
