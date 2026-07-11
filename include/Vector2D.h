/*
*	このヘッダファイルは、2次元ベクトルを表すデータ構造体を定義します。
*/

template<typename T>
struct Vector2D
{
	T x;	// X成分
	T y;	// Y成分

	// ---コンストラクタ------------------------------------------------------------
	Vector2D() : x(0), y(0) {}
	Vector2D(T x, T y) : x(x), y(y) {}

	// ---演算子オーバーロード------------------------------------------------------
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
	// ベクトルのスカラー除算代入演算子
	Vector2D<T>& operator/=(T scalar)
	{
		x /= scalar;
		y /= scalar;
		return *this;
	}
	// ベクトルの等価演算子
	bool operator==(const Vector2D<T>& other) const
	{
		return x == other.x && y == other.y;
	}
	// ベクトルの非等価演算子
	bool operator!=(const Vector2D<T>& other) const
	{
		return !(*this == other);
	}

	// ---メンバ関数---------------------------------------------------------------
	// ベクトルの長さを計算する
	float Length() const
	{
		float dx = static_cast<float>(this->x);
		float dy = static_cast<float>(this->y);
		return std::sqrt(dx * dx + dy * dy);
	}
	// ベクトルの2乗の長さを計算する
	float LengthSquared() const
	{
		float dx = static_cast<float>(this->x);
		float dy = static_cast<float>(this->y);
		return dx * dx + dy * dy;
	}
	// ベクトルを正規化して自身を更新する
	Vector2D<T>& Normalize()
	{
		float len = Length();
		if (len != 0)
		{
			x /= len;
			y /= len;
		}
		return *this;
	}
	// ベクトルを正規化した値を返す（自身は更新しない）
	Vector2D<T> Normalized() const
	{
		float len = Length();
		if (len == 0)
			return Vector2D<T>(0, 0);
		return Vector2D<T>(x / len, y / len);
	}
};

// ベクトルの内積を計算する関数
template<typename T>
inline float Dot(const Vector2D<T>& a, const Vector2D<T>& b)
{
	return static_cast<float>(a.x) * static_cast<float>(b.x) + static_cast<float>(a.y) * static_cast<float>(b.y);
}

// ベクトルの距離を計算する関数
template<typename T>
inline float Distance(const Vector2D<T>& a, const Vector2D<T>& b)
{
	float dx = static_cast<float>(a.x) - static_cast<float>(b.x);
	float dy = static_cast<float>(a.y) - static_cast<float>(b.y);
	return std::sqrt(dx * dx + dy * dy);
}

// ベクトルの距離の2乗を計算する関数
template<typename T>
inline float DistanceSquared(const Vector2D<T>& a, const Vector2D<T>& b)
{
	float dx = static_cast<float>(a.x) - static_cast<float>(b.x);
	float dy = static_cast<float>(a.y) - static_cast<float>(b.y);
	return dx * dx + dy * dy;
}