/*
*	このヘッダファイルは、ゲーム内のFPSや時間を管理するクラスを定義します。
*/

#include <chrono>

class TimeManager
{
public:
	TimeManager(int target);	// 引数付きコンストラクタ
	void Update();				// 更新処理
	void SetFPS(int target);	// FPSを設定する
	int GetFPS() const;			// 現在のFPSを取得する
	float GetDeltaTime() const;	// 1フレームにかかった時間を取得する
	unsigned int GetFrameCount() const;		// フレームカウントを取得する
private:
	int targetFPS;	// 目標FPS
	unsigned int frameCount;	// フレームカウント
	std::chrono::steady_clock::time_point startTime;		// ゲームの開始時間
	std::chrono::duration<float, std::milli> targetFrameTime;	// 1フレーム当たりの目標時間(ミリ秒)
	std::chrono::duration<float, std::milli> deltaTime;		// 1フレームにかかった時間
};