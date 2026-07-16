#include <iostream>

// TimeManager.h をインクルード
#include "TimeManager.h"

/*
*	【サンプルコードについて】
*	このファイルはTimeManagerの機能確認を目的として、
*	生成AIを利用して作成したコードをベースに、
*	内容を確認・修正して使用しています。
*/

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