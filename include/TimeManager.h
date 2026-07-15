/*
*	このヘッダファイルは、ゲーム内のFPSや時間を管理するクラスを定義します。
*/

#include <chrono>

class TimeManager
{
public:
	TimeManager(int target = 60);	// 引数付きコンストラクタ
	void Update();				// 更新処理
	void SetTargetFPS(int target);	// FPSを設定する
	int GetTargetFPS() const;			// 現在のFPSを取得する
	float GetDeltaTime() const;	// 1フレームにかかった時間を取得する
	unsigned int GetFrameCount() const;		// フレームカウントを取得する
	float GetElapsedTime() const;			// ゲーム開始からの経過時間を取得する
private:
	int targetFPS;	// 目標FPS
	unsigned int frameCount;	// フレームカウント
	std::chrono::steady_clock::time_point startTime;		// ゲームの開始時間
	std::chrono::steady_clock::time_point previousFrameTime;	// 前回のフレームの時間
	std::chrono::duration<float> targetFrameTime;	// 1フレーム当たりの目標時間(ミリ秒)
	std::chrono::duration<float> deltaTime;		// 1フレームにかかった時間
};