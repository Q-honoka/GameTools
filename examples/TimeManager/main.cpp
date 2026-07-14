#include "TimeManager.h"
#include <iostream>

int main()
{
	TimeManager timeManager(60);

	for(int i = 0; i < 10; i++)
	{
		if (i == 8) timeManager.SetFPS(10);
		timeManager.Update();
		std::cout << timeManager.GetDeltaTime() << std::endl;
	}

	return 0;
}