/*
 * InputMgr.h
 *
 *  Created on: Mar 27, 2017
 *      Author: randygonzalez
 */

#ifndef INCLUDE_INPUTMGR_H_
#define INCLUDE_INPUTMGR_H_

#include <mgr.h>

class Engine;

class InputMgr : public Mgr, public Ogre::FrameListener, public Ogre::WindowEventListener, public OIS::KeyListener, public OIS::MouseListener, OgreBites::SdkTrayListener
{
public:
	InputMgr(Engine *eng);
	virtual ~InputMgr();

	virtual void init();
	virtual void tick(float dt);
	virtual void loadLevel();
	virtual void stop();

	// Change Speed and Heading of Entities
	void updateCamera(const Ogre::FrameEvent& fe);
	void updateVelocity(const Ogre::FrameEvent& fe);


	void createFrameListener(void);
	void createViewPorts(void);

	// Input Management
    bool frameRenderingQueued(const Ogre::FrameEvent& evt);

    bool keyPressed(const OIS::KeyEvent &arg);
    bool keyReleased(const OIS::KeyEvent &arg);
    bool mouseMoved(const OIS::MouseEvent &arg);
    bool mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
    bool mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
    // Adjust mouse clipping area
    void windowResized(Ogre::RenderWindow* rw);
    // Unattach OIS before window shutdown (very important under Linux)
    void windowClosed(Ogre::RenderWindow* rw);


    // OgreBites
    OgreBites::InputContext     mInputContext;
    OgreBites::SdkTrayManager*	mTrayMgr;

    //OIS Input devices
    OIS::InputManager*          mInputManager;
    OIS::Mouse*                 mMouse;
    OIS::Keyboard*              mKeyboard;

    // Camera Node
    Ogre::SceneNode* 			cameraNode;


private:

};



#endif /* INCLUDE_INPUTMGR_H_ */
