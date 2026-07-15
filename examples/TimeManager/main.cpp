#include "TimeManager.h"
#include <iostream>

int main()
{
	TimeManager timeManager(60);

	for(int i = 0; i < 10; i++)
	{
		timeManager.Update();
		std::cout << timeManager.GetDeltaTime() << std::endl;
	}

	return 0;
}