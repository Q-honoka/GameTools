#include "Shape2D.h"

// ---衝突判定の結果を表す構造体------------------------------------------------s
struct HitInfo
{
	bool isHit;			// ヒットしたかどうか
	Vector2D hitPoint;	// 衝突点の座標
	Vector2D hitNormal;	// 衝突面の法線ベクトル
	float penetrationDepth;	// めり込みの深さ
};