#include "TimeManager.h"

/// <summary>
/// 引数付きコンストラクタ
/// </summary>
/// <param name="target">設定したいFPS</param>
TimeManager::TimeManager(int target = 60) :
	targetFPS(target),
	startTime(std::chrono::steady_clock::now),
	targetFrameTime(1000.0f / targetFPS)
{ }

/// <summary>
/// 更新処理
/// </summary>
void TimeManager::Update()
{

}

/// <summary>
/// FPSを設定する
/// </summary>
/// <param name="target">設定したいFPS</param>
void TimeManager::SetFPS(int target)
{
	targetFPS = target;
}

/// <summary>
/// 現在のFPSを取得する
/// </summary>
/// <returns>現在のFPS</returns>
int TimeManager::GetFPS() const
{
	return targetFPS;
}