#include <stdio.h>
#include <string>

#include "Engine.h"

using namespace std;

Engine* _engine;

int main(int argc, char** args) {
	_engine = new Engine;

	
	if (_engine->Init("HelicopterGame"))
	{
		printf("Engine successfully started.\n");
	}
	else
	{
		printf("Engine failed to start.\n");
		_engine->Cleanup();
		return -1;
	}

	_engine->Run();

	_engine->Cleanup();
	delete _engine;

	return 0;
}