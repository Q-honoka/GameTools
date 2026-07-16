#include "Shape2D.h"

// ---衝突判定の結果を表す構造体------------------------------------------------s
struct HitInfo
{
	bool isHit;			// ヒットしたかどうか
	Vector2D hitPoint;	// 衝突点の座標
	Vector2D hitNormal;	// 衝突面の法線ベクトル
	float penetrationDepth;	// めり込みの深さ
};

// 衝突判定結果を初期化する関数
HitInfo InitializeHitInfo()
{
	HitInfo hitInfo;
	hitInfo.isHit = false;
	hitInfo.hitPoint = Vector2D(0, 0);
	hitInfo.hitNormal = Vector2D(0, 0);
	hitInfo.penetrationDepth = 0.0f;
	return hitInfo;
}

// ---衝突判定関数の宣言------------------------------------------------------------
// 点と点の衝突判定
inline HitInfo CheckCollision(const Vector2D& a, const Vector2D& b)
{
	HitInfo hitInfo = InitializeHitInfo();

	if (Distance(a, b) <= 0.00001f)
	{
		hitInfo.isHit = true;
		hitInfo.hitPoint = a;
		hitInfo.hitNormal = Vector2D(0, 0);
		hitInfo.penetrationDepth = 0.0f;
	}

	return hitInfo;
}

// 点と線分の衝突判定
inline HitInfo CheckCollision(const Vector2D& point, const LineSegment& line)
{
	HitInfo hitInfo = InitializeHitInfo();

	Vector2D lineVec = line.end - line.start;
	Vector2D pointVec = point - line.start;

	Vector2D lineDir = lineVec.Normalized();
	float dot = Dot(pointVec, lineDir);

	if (dot < 0.0f)
	{
		hitInfo.isHit = false;
		return hitInfo;
	}

	if (dot > lineVec.Length())
	{
		hitInfo.isHit = false;
		return hitInfo;
	}

	hitInfo.isHit = true;
	hitInfo.hitPoint = line.start + lineDir * dot;
	hitInfo.hitNormal = Vector2D(-lineDir.y, lineDir.x); // 法線ベクトルを計算
	hitInfo.penetrationDepth = 0.0f; // 点と線分の衝突ではめり込みはない

	return hitInfo;
}