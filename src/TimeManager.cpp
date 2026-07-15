#include "TimeManager.h"
#include <thread>

/// <summary>
/// 引数付きコンストラクタ
/// </summary>
/// <param name="target">設定したいFPS</param>
TimeManager::TimeManager(int target = 60) :
	targetFPS(target),
	frameCount(0),
	startTime(std::chrono::steady_clock::now()),
	targetFrameTime(std::chrono::duration<float>(1.0f / targetFPS)),
	deltaTime({})
{ }

/// <summary>
/// 更新処理
/// </summary>
void TimeManager::Update()
{
	// 次のフレーム開始までの待ち時間を求める
	std::chrono::steady_clock::time_point frameStartTime = std::chrono::steady_clock::now();
	auto next = frameStartTime + targetFrameTime;

	// スリープ処理が終わったらデルタタイムを求める
	std::this_thread::sleep_until(next);
	deltaTime = std::chrono::steady_clock::now() - frameStartTime;
	frameCount++;
}

/// <summary>
/// FPSを設定する
/// </summary>
/// <param name="target">設定したいFPS</param>
void TimeManager::SetFPS(int target)
{
	targetFPS = target;
	targetFrameTime = std::chrono::duration<float>(1.0f / targetFPS);
}

/// <summary>
/// 現在のFPSを取得する
/// </summary>
/// <returns>現在のFPS</returns>
int TimeManager::GetFPS() const
{
	return targetFPS;
}

/// <summary>
/// 1フレームにかかった時間を返す
/// </summary>
/// <returns>デルタタイム</returns>
float TimeManager::GetDeltaTime() const
{
	return deltaTime.count();
}

/// <summary>
/// フレームカウントを取得する
/// </summary>
/// <returns>フレームカウント</returns>
unsigned int TimeManager::GetFrameCount() const
{
	return frameCount;
}