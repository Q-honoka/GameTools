#include <iostream>

// Collision2D.h をインクルード
#include "Collision2D.h"

/*
*	【サンプルコードについて】
*	このファイルはCollision2Dの機能確認を目的として、
*	生成AIを利用して作成したコードをベースに、
*	内容を確認・修正して使用しています。
*/

int main()
{
	// ==============================================================
	// 点と点の衝突判定
	// ==============================================================
	Vector2D pointA(1, 1);
	Vector2D pointB(1, 1);

	std::cout << "点A: (" << pointA.x << ", " << pointA.y << ")" << std::endl;
	std::cout << "点B: (" << pointB.x << ", " << pointB.y << ")" << std::endl;

	HitInfo hitInfo = CheckCollision(pointA, pointB);

    if (hitInfo.isHit)
    {
        std::cout << "衝突が検出されました。" << std::endl;
        std::cout << "衝突点: (" << hitInfo.hitPoint.x << ", " << hitInfo.hitPoint.y << ")" << std::endl;
        std::cout << "衝突法線: (" << hitInfo.hitNormal.x << ", " << hitInfo.hitNormal.y << ")" << std::endl;
        std::cout << "めり込みの深さ: " << hitInfo.penetrationDepth << std::endl;
    }
    else
    {
        std::cout << "衝突は検出されませんでした。" << std::endl;
    }

	std::cout << std::endl;

	// ==============================================================
	// 点と線分の衝突判定
	// ==============================================================
	Vector2D pointC(2, 2);
	LineSegment lineSegment(Vector2D(1, 1), Vector2D(3, 3));

	std::cout << "点C: (" << pointC.x << ", " << pointC.y << ")" << std::endl;
	std::cout << "線分: (" << lineSegment.start.x << ", " << lineSegment.start.y << ") から (" << lineSegment.end.x << ", " << lineSegment.end.y << ")" << std::endl;

	HitInfo hitInfoLine = CheckCollision(pointC, lineSegment);

	if (hitInfoLine.isHit)
	{
		std::cout << "点と線分の衝突が検出されました。" << std::endl;
		std::cout << "衝突点: (" << hitInfoLine.hitPoint.x << ", " << hitInfoLine.hitPoint.y << ")" << std::endl;
		std::cout << "衝突法線: (" << hitInfoLine.hitNormal.x << ", " << hitInfoLine.hitNormal.y << ")" << std::endl;
		std::cout << "めり込みの深さ: " << hitInfoLine.penetrationDepth << std::endl;
	}
	else
	{
		std::cout << "点と線分の衝突は検出されませんでした。" << std::endl;
	}

	std::cout << std::endl;

	// ==============================================================
	// 点と円の衝突判定
	// ==============================================================
	Vector2D pointD(2, 2);
	Circle circle(Vector2D(1, 1), 2.0f);

	std::cout << "点D: (" << pointD.x << ", " << pointD.y << ")" << std::endl;
	std::cout << "円: 中心 (" << circle.center.x << ", " << circle.center.y << "), 半径 " << circle.radius << std::endl;

	HitInfo hitInfoCircle = CheckCollision(pointD, circle);

	if (hitInfoCircle.isHit)
	{
		std::cout << "点と円の衝突が検出されました。" << std::endl;
		std::cout << "衝突点: (" << hitInfoCircle.hitPoint.x << ", " << hitInfoCircle.hitPoint.y << ")" << std::endl;
		std::cout << "衝突法線: (" << hitInfoCircle.hitNormal.x << ", " << hitInfoCircle.hitNormal.y << ")" << std::endl;
		std::cout << "めり込みの深さ: " << hitInfoCircle.penetrationDepth << std::endl;
	}
	else
	{
		std::cout << "点と円の衝突は検出されませんでした。" << std::endl;
	}

    return 0;
}