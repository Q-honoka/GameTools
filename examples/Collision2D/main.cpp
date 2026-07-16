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

	std::cout << "点A\t: (" << pointA.x << ", " << pointA.y << ")" << std::endl;
	std::cout << "点B\t: (" << pointB.x << ", " << pointB.y << ")" << std::endl;

	HitInfo hitInfo = CheckCollision(pointA, pointB);

    if (hitInfo.isHit)
    {
        std::cout << "衝突が検出されました。" << std::endl;
        std::cout << "衝突点\t\t: (" << hitInfo.hitPoint.x << ", " << hitInfo.hitPoint.y << ")" << std::endl;
        std::cout << "衝突法線\t: (" << hitInfo.hitNormal.x << ", " << hitInfo.hitNormal.y << ")" << std::endl;
        std::cout << "めり込みの深さ\t: " << hitInfo.penetrationDepth << std::endl;
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

	std::cout << "点C\t: (" << pointC.x << ", " << pointC.y << ")" << std::endl;
	std::cout << "線分\t: (" << lineSegment.start.x << ", " << lineSegment.start.y << ") から (" << lineSegment.end.x << ", " << lineSegment.end.y << ")" << std::endl;

	HitInfo hitInfoLine = CheckCollision(pointC, lineSegment);

	if (hitInfoLine.isHit)
	{
		std::cout << "点と線分の衝突が検出されました。" << std::endl;
		std::cout << "衝突点\t\t: (" << hitInfoLine.hitPoint.x << ", " << hitInfoLine.hitPoint.y << ")" << std::endl;
		std::cout << "衝突法線\t: (" << hitInfoLine.hitNormal.x << ", " << hitInfoLine.hitNormal.y << ")" << std::endl;
		std::cout << "めり込みの深さ\t: " << hitInfoLine.penetrationDepth << std::endl;
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

	std::cout << "点D\t: (" << pointD.x << ", " << pointD.y << ")" << std::endl;
	std::cout << "円\t: 中心 (" << circle.center.x << ", " << circle.center.y << "), 半径 " << circle.radius << std::endl;

	HitInfo hitInfoCircle = CheckCollision(pointD, circle);

	if (hitInfoCircle.isHit)
	{
		std::cout << "点と円の衝突が検出されました。" << std::endl;
		std::cout << "衝突点\t\t: (" << hitInfoCircle.hitPoint.x << ", " << hitInfoCircle.hitPoint.y << ")" << std::endl;
		std::cout << "衝突法線\t: (" << hitInfoCircle.hitNormal.x << ", " << hitInfoCircle.hitNormal.y << ")" << std::endl;
		std::cout << "めり込みの深さ\t: " << hitInfoCircle.penetrationDepth << std::endl;
	}
	else
	{
		std::cout << "点と円の衝突は検出されませんでした。" << std::endl;
	}

	std::cout << std::endl;

	// ==============================================================
	// 円と円の衝突判定
	// ==============================================================
	Circle circleA(Vector2D(1, 1), 2.0f);
	Circle circleB(Vector2D(2, 2), 2.0f);

	std::cout << "円A\t: 中心 (" << circleA.center.x << ", " << circleA.center.y << "), 半径 " << circleA.radius << std::endl;
	std::cout << "円B\t: 中心 (" << circleB.center.x << ", " << circleB.center.y << "), 半径 " << circleB.radius << std::endl;

	HitInfo hitInfoCircleCircle = CheckCollision(circleA, circleB);

	if (hitInfoCircleCircle.isHit)
	{
		std::cout << "円と円の衝突が検出されました。" << std::endl;
		std::cout << "衝突点\t\t: (" << hitInfoCircleCircle.hitPoint.x << ", " << hitInfoCircleCircle.hitPoint.y << ")" << std::endl;
		std::cout << "衝突法線\t: (" << hitInfoCircleCircle.hitNormal.x << ", " << hitInfoCircleCircle.hitNormal.y << ")" << std::endl;
		std::cout << "めり込みの深さ\t: " << hitInfoCircleCircle.penetrationDepth << std::endl;

	}
	else
	{
		std::cout << "円と円の衝突は検出されませんでした。" << std::endl;
	}

	std::cout << std::endl;

	// ==============================================================
	// 点と矩形の衝突判定
	// ==============================================================
	Vector2D pointE(2, 2);
	Rectangle rect(Vector2D(1, 1), 3.0f, 3.0f);

	std::cout << "点E\t: (" << pointE.x << ", " << pointE.y << ")" << std::endl;
	std::cout << "矩形\t: 左上 (" << rect.leftUpPosition.x << ", " << rect.leftUpPosition.y << "), 幅 " << rect.width << ", 高さ " << rect.height << std::endl;

	HitInfo hitInfoRect = CheckCollision(pointE, rect);

	if (hitInfoRect.isHit)
	{
		std::cout << "点と矩形の衝突が検出されました。" << std::endl;
		std::cout << "衝突点\t\t: (" << hitInfoRect.hitPoint.x << ", " << hitInfoRect.hitPoint.y << ")" << std::endl;
		std::cout << "衝突法線\t: (" << hitInfoRect.hitNormal.x << ", " << hitInfoRect.hitNormal.y << ")" << std::endl;
		std::cout << "めり込みの深さ\t: " << hitInfoRect.penetrationDepth << std::endl;

	}
	else
	{
		std::cout << "点と矩形の衝突は検出されませんでした。" << std::endl;
	}

	std::cout << std::endl;

    return 0;
}