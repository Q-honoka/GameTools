#include "TimeManager.h"
#include <thread>

/// <summary>
/// 引数付きコンストラクタ
/// </summary>
/// <param name="target">設定したいFPS</param>
TimeManager::TimeManager(int target) :
	targetFPS(target),
	frameCount(0),
	startTime(std::chrono::steady_clock::now()),
	previousFrameTime(startTime),
	targetFrameTime(std::chrono::duration<float>(1.0f / targetFPS)),
	deltaTime({})
{ }

/// <summary>
/// 更新処理
/// </summary>
void TimeManager::Update()
{
	// 前フレームの開始から現在のフレームの開始までの時間（デルタタイム）を求める
	std::chrono::steady_clock::time_point currentFrameTime = std::chrono::steady_clock::now();
	deltaTime = currentFrameTime - previousFrameTime;
	previousFrameTime = currentFrameTime;

	// 次のフレーム開始までの待ち時間を求める
	auto next = currentFrameTime + targetFrameTime;
	frameCount++;

	// スリープ処理が終わったらデルタタイムを求める
	std::this_thread::sleep_until(next);
}

/// <summary>
/// FPSを設定する
/// </summary>
/// <param name="target">設定したいFPS</param>
void TimeManager::SetTargetFPS(int target)
{
	targetFPS = target;
	targetFrameTime = std::chrono::duration<float>(1.0f / targetFPS);
}

/// <summary>
/// 現在のFPSを取得する
/// </summary>
/// <returns>現在のFPS</returns>
int TimeManager::GetTargetFPS() const
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

/// <summary>
/// ゲーム開始からの経過時間を取得する
///	</summary>
/// <returns>経過時間</returns>
float TimeManager::GetElapsedTime() const
{
	auto now = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::duration<float>>(now - startTime);
	return elapsed.count();
}