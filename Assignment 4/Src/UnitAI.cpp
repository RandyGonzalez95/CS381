/*
 * UnitAI.cpp
 *
 *  Created on: Apr 3, 2017
 *      Author: jwoo
 */
#include <UnitAI.h>
#include <engine.h>






UnitAI::UnitAI(Entity381* ent) : Aspect(ent){

}

UnitAI::~UnitAI(){

}

void UnitAI::Tick(float dt){

	Command *temp;

	if(commands.front() == NULL)
	{
		return;
	}

	// Run through list of commands on our queue
	for(unsigned int i = 0; i<commands.size(); i++)
	{
		// Check if we are done with current command
		if(!commands.front()->done())
		{
			commands.front()->tick(dt);
		}
		else // Pop and delete the front command
		{
			std::cerr<<"Queue Popped"<<std::endl;
			temp = GetCommand();
			commands.pop();
			delete temp;
		}
	}
}

Command * UnitAI::GetCommand(){
	return commands.front();
}


void UnitAI::AddCommand(Command *c){

	std::cout<<"command added to queue"<<std::endl;

	// Enqueue Commands
	commands.push(c);
}

















