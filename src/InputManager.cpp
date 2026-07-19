#include "InputManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
InputManager::InputManager() :
	inputInfo
{ }

/// <summary>
/// キー入力情報の更新
/// </summary>
/// <param name="keys">キー入力情報を格納した文字列</param>
void InputManager::UpdateKeys(const char* keys)
{
	inputInfo.prevKey = inputInfo.key;
	inputInfo.key = keys;
}

/// <summary>
/// マウス情報の更新
/// </summary>
/// <param name="mouseX">マウスのX座標</param>
/// <param name="mouseY">マウスのY座標</param>
/// <param name="mouseButton">マウス入力状態（左、中、右）</param>
void InputManager::UpdateMouse(int mouseX, int mouseY, const bool mouseButton[3])
{
	inputInfo.mouseX = mouseX;
	inputInfo.mouseY = mouseY;
	for (int i = 0; i < 3; i++)
	{
		inputInfo.prevMouseButton[i] = inputInfo.mouseButton[i];
		inputInfo.mouseButton[i] = mouseButton[i];
	}
}

/// <summary>
/// 指定されたキーが押されているかを判定
/// </summary>
/// <param name="key">調べたいキー</param>
/// <returns>押されたかどうか</returns>
bool InputManager::IsKeyPressed(int key) const
{
	bool prevState = inputInfo.prevKey[key];
	bool currentState = inputInfo.key[key];
	return !prevState == currentState && currentState;
}

/// <summary>
/// 指定されたキーが離されたかを判定
/// </summary>
/// <param name="key">調べたいキー</param>
/// <returns>離されたかどうか</returns>
bool InputManager::IsKeyReleased(int key) const
{
	bool prevState = inputInfo.prevKey[key];
	bool currentState = inputInfo.key[key];
	return !prevState == currentState && !currentState;
}

/// <summary>
/// 指定されたキーが押され続けているかを判定
/// </summary>
/// <param name="key">調べたいキー</param>
/// <returns>押され続けているかどうか</returns>
bool InputManager::IsKeyHeld(int key) const
{
	bool prevState = inputInfo.prevKey[key];
	bool currentState = inputInfo.key[key];
	return prevState == currentState && currentState;
}

/// <summary>
/// マウスの座標を取得する
/// </summary>
/// <param name="mouseX">マウスのX座標を格納する変数のアドレス</param>
/// <param name="mouseY">マウスのY座標を格納する変数のアドレス</param>
void InputManager::GetMousePosition(int& mouseX, int& mouseY)
{
	mouseX = inputInfo.mouseX;
	mouseY = inputInfo.mouseY;
}

/// <summary>
/// 指定されたマウスボタンが押されているかを判定
/// </summary>
/// <param name="button">調べたいマウスボタン(0=左, 1=中, 2=右)</param>
/// <returns>押されているかどうか</returns>
bool InputManager::IsMouseButtonPressed(int button) const
{
	bool prevState = inputInfo.prevMouseButton[button];
	bool currentState = inputInfo.mouseButton[button];
	return !prevState == currentState && currentState;
}

/// <summary>
/// 指定されたマウスボタンが離されたかを判定
/// </summary>
/// <param name="button">調べたいマウスボタン(0=左, 1=中, 2=右)</param>
/// <returns>離されたかどうか</returns>
bool InputManager::IsMouseButtonReleased(int key) const
{
	bool prevState = inputInfo.prevMouseButton[button];
	bool currentState = inputInfo.mouseButton[button];
	return !prevState == currentState && !currentState;
}

/// <summary>
/// 指定されたマウスボタンが押され続けているかを判定
/// </summary>
/// <param name="button">調べたいマウスボタン(0=左, 1=中, 2=右)</param>
/// <returns>押され続けているかどうか</returns>
bool InputManager::IsMouseButtonHeld(int key) const
{
	bool prevState = inputInfo.prevMouseButton[button];
	bool currentState = inputInfo.mouseButton[button];
	return prevState == currentState && currentState;
}