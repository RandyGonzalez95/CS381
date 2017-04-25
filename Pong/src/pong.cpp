//============================================================================
// Name        : pong.cpp
// Author      : Randy Gonzalez, Nirmit Patel
// Version     :
// Copyright   : All rights reserved
// Description : Game Implementation
//============================================================================

#include <pong.h>
#include <iostream>
#include <cstring>
#include <string>

Pong::Pong(void)
{

}

Pong::~Pong(void)
{
}




#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
#else
    int main(int argc, char *argv[])
#endif
    {
	// Create application object
	Engine *engine;

	try {
		engine = new Engine();
		engine->Initialize();
		engine->run();
	} catch(Ogre::Exception& e)  {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
	    MessageBox(NULL, e.getFullDescription().c_str(), "An exception has occurred!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
	    std::cerr << "An exception has occurred: " <<
		e.getFullDescription().c_str() << std::endl;
#endif
	}

	return 0;
    }

#ifdef __cplusplus
}
#endif


