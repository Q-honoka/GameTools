/*
*	このヘッダファイルは、ゲーム内の入力情報を管理するクラスを定義します。
*	外部からの入力情報を受け取り、キーやマウスの状態を管理しています。
*/

class InputManager
{
public:
	InputManager(); // コンストラクタ

	void UpdateKeys(const char* keys);	// キー入力情報の更新
	void UpdateMouse(int mouseX, int mouseY, const bool mouseButton[3]); // マウス情報の更新

	bool IsKeyPressed(int key) const;		// 指定されたキーが押されているかを判定
	bool IsKeyReleased(int key) const;	// 指定されたキーが離されたかを判定
	bool IsKeyHeld(int key) const;		// 指定されたキーが押され続けているかを判定

	void GetMousePosition(int& mouseX, int& mouseY);	// マウスの座標を取得
	bool IsMouseButtonPressed(int button) const;	// 指定されたマウスボタンが押されているかを判定
	bool IsMouseButtonReleased(int button) const;	// 指定されたマウスボタンが離されたかを判定
	bool IsMouseButtonHeld(int button) const;	// 指定されたマウスボタンが押され続けているかを判定

private:
	// 入力情報を格納する構造体
	struct InputInfo
	{
		char key[256];		// キー入力の状態を格納する配列
		char prevKey[256];	// 前回のキー入力の状態を格納する配列

		int mouseX; // マウスのX座標
		int mouseY; // マウスのY座標
		bool mouseButton[3];		// マウスボタンの状態（左、中、右）
		bool prevMouseButton[3];	// 前回のマウスボタンの状態（左、中、右）
	};

	InputInfo inputInfo;		// 入力情報のデータ構造体を格納するベクター
}