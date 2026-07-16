#include "Vector2D.h"

/*
*	このヘッダファイルは、2Dの形を表すデータ構造体を定義しています。
*/

// ---円を表す構造体------------------------------------------------------------
struct Circle
{
	Vector2D center;	// 円の中心座標
	float radius;		// 円の半径
};

// ---矩形を表す構造体----------------------------------------------------------
struct Rectangle
{
	Vector2D leftUpPosition;	// 左上座標
	float width;				// 幅
	float height;				// 高さ
};

// ---線分を表す構造体----------------------------------------------------------
struct LineSegment
{
	Vector2D start;	// 始点座標
	Vector2D end;	// 終点座標
};