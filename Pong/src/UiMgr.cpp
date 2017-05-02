/*
 * UiMgr.cpp
 *
 *  Created on: Apr 12, 2017
 *      Author: chad
 */

#include <UiMgr.h>
#include <engine.h>
#include <vector>

UiMgr::UiMgr(Engine* eng): Mgr(eng), mTrayMgr(0)
{
	// Initialize the OverlaySystem (changed for Ogre 1.9)
	    mOverlaySystem = new Ogre::OverlaySystem();
	    engine->gfxMgr->ogreSceneManager->addRenderQueueListener(mOverlaySystem);

	    //Ogre::WindowEventUtilities::addWindowEventListener(engine->gfxMgr->ogreRenderWindow, this);
}

UiMgr::~UiMgr(){ // before gfxMgr destructor

}

void UiMgr::init()
{
	//init sdktrays

    mInputContext.mKeyboard = engine->inputMgr->keyboard;
    mInputContext.mMouse = engine->inputMgr->mouse;
    mTrayMgr = new OgreBites::SdkTrayManager("InterfaceName", engine->gfxMgr->ogreRenderWindow, mInputContext, this);

}

void UiMgr::stop()
{

}

void UiMgr::loadLevel()
{
	// Create new Ogre Material for my splash screen
	Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().create("Background", "General");
	material->getTechnique(0)->getPass(0)->createTextureUnitState("pong.png");
	material->getTechnique(0)->getPass(0)->setDepthCheckEnabled(false);
	material->getTechnique(0)->getPass(0)->setDepthWriteEnabled(false);
	material->getTechnique(0)->getPass(0)->setLightingEnabled(false);

	mTrayMgr->showBackdrop("Background");

	//OgreBites::SelectMenu* menu = mTrayMgr->createThickSelectMenu(OgreBites::TL_CENTER, "MyMenu", "Menu", 200, 3);
	OgreBites::Button *b = mTrayMgr->createButton(OgreBites::TL_BOTTOM, "StartButton", "Start");

	OgreBites::SelectMenu* menu = mTrayMgr->createLongSelectMenu(OgreBites::TL_BOTTOM, "MyMenu", "Options Menu", 300, 170, 5);
	menu->addItem("How To Play");
	menu->addItem("Single Player");
	menu->addItem("Two Player");
	menu->addItem("Choose Difficulty");
	//Ogre::Bites SelectMenu *menu = mTrayMgr->createThickSelectMenu(OgreBites::TL_CENTER, "MyMenu", "Menu", 300, 3);

	//OgreBites::Label *label = mTrayMgr->createLabel(OgreBites::TL_NONE, "Label", "Caption", 200);
}

void UiMgr::tick(float dt)
{
	mTrayMgr->refreshCursor();
}

void UiMgr::windowResized(Ogre::RenderWindow* rw)
{
	unsigned int width, height, depth;
	int left, top;
	rw->getMetrics(width, height, depth, left, top);

	const OIS::MouseState &ms = engine->inputMgr->mouse->getMouseState();
	ms.width = width;
	ms.height = height;
}

void UiMgr::windowClosed(Ogre::RenderWindow* rw)
{

}

bool UiMgr::keyPressed(const OIS::KeyEvent &arg)
{
	std::cout << "Key Pressed: " << arg.key << std::endl;
	return true;
}
bool UiMgr::keyReleased(const OIS::KeyEvent &arg)
{
	return true;
}
bool UiMgr::mouseMoved(const OIS::MouseEvent &arg)
{
    if (mTrayMgr->injectMouseMove(arg)) return true;
    /* normal mouse processing here... */
	return true;
}
bool UiMgr::mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	std::cout << "mouse clicked" << std::endl;
	if (mTrayMgr->injectMouseDown(arg, id)) return true;
	    /* normal mouse processing here... */
	return true;
}
bool UiMgr::mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
    if (mTrayMgr->injectMouseUp(arg, id)) return true;
    /* normal mouse processing here... */
	return true;
}

void UiMgr::buttonHit(OgreBites::Button *b)
{
    if(b->getName()=="StartButton")
    {
        //std::cout <<"Click Me!" << std::endl;
        mTrayMgr->hideBackdrop();
        mTrayMgr->destroyWidget(b->getName());
        mTrayMgr->destroyWidget("MyMenu");
        mTrayMgr->showLogo(OgreBites::TL_BOTTOMRIGHT);
        mTrayMgr->showCursor();

        Ogre::DisplayString helpText = "Randy: 0\n";
        Ogre::DisplayString helpText2 = "Nirmit: 0\n";



        //mTrayMgr->createLabel(OgreBites::TL_BOTTOMLEFT, "Label", "", 200);
        OgreBites::TextBox *text = mTrayMgr->createTextBox(OgreBites::TL_TOPLEFT, "text", "Player 1", 150, 75);
        text->setText(helpText);

        OgreBites::TextBox *text2 = mTrayMgr->createTextBox(OgreBites::TL_TOPRIGHT, "text2", "Player 2", 150, 75);
        text2->setText(helpText2);


        /*mTrayMgr->createLabel(OgreBites::TL_BOTTOM, "Label2", "Caption", 200);
        mTrayMgr->createLabel(OgreBites::TL_BOTTOM, "Label3", "Caption", 200);
        mTrayMgr->createLabel(OgreBites::TL_BOTTOM, "Label4", "Caption", 200);
        mTrayMgr->createLabel(OgreBites::TL_BOTTOM, "Label5", "Caption", 200);*/
    }

}

void UiMgr::itemSelected(OgreBites::SelectMenu *m)
{
    if(m->getName()=="MyMenu")
    {
        std::cout <<"Menu!" << std::endl;
    }

}
