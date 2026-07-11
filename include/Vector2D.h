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

	// ベクトルの加算
	Vector2D<T> operator+(const Vector2D<T>& other) const
	{
		return Vector2D<T>(x + other.x, y + other.y);
	}
	// ベクトルの減算
	Vector2D<T> operator-(const Vector2D<T>& other) const
	{
		return Vector2D<T>(x - other.x, y - other.y);
	}
	// ベクトルのスカラー倍
	Vector2D<T> operator*(T scalar) const
	{
		return Vector2D<T>(x * scalar, y * scalar);
	}
	// ベクトルのスカラー除算
	Vector2D<T> operator/(T scalar) const
	{
		return Vector2D<T>(x / scalar, y / scalar);
	}
	// ベクトルの加算代入演算子
	Vector2D<T>& operator+=(const Vector2D<T>& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}
	// ベクトルの減算代入演算子
	Vector2D<T>& operator-=(const Vector2D<T>& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}
	// ベクトルのスカラー倍代入演算子
	Vector2D<T>& operator*=(T scalar)
	{
		x *= scalar;
		y *= scalar;
		return *this;
	}
};