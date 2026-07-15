#include <iostream>
#include "TimeManager.h"

int main()
{
    TimeManager time_manager(60);

    while (time_manager.GetElapsedTime() < 5.0f)
    {
        time_manager.Update();

        std::cout
            << "Frame : " << time_manager.GetFrameCount()
            << " | DeltaTime : " << time_manager.GetDeltaTime()
            << " | Elapsed : " << time_manager.GetElapsedTime()
            << std::endl;
    }

    std::cout << "\n5秒経過したので終了します。" << std::endl;

    return 0;
}