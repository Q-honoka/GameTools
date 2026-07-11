/*
*	このヘッダファイルは、2次元ベクトルを表すデータ構造体を定義します。
*/

template<typename T>
struct Vector2D
{
	T x;	// X成分
	T y;	// Y成分

	// コンストラクタ
	Vector2D() : x(0), y(0) {}
	Vector2D(T x, T y) : x(x), y(y) {}
};