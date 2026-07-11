/*
*	このヘッダファイルは、2次元ベクトルを表すデータ構造体を定義します。
*/

struct Vector2D
{
	float x;	// X成分
	float y;	// Y成分

	// ---コンストラクタ------------------------------------------------------------
	Vector2D() : x(0.0f), y(0.0f) {}
	Vector2D(float x, float y) : x(x), y(y) {}

	// ---演算子オーバーロード------------------------------------------------------
	// ベクトルの単項マイナス演算子
	Vector2D operator-() const
	{
		return Vector2D(-x, -y);
	}
	// ベクトルの加算
	Vector2D operator+(const Vector2D& other) const
	{
		return Vector2D(x + other.x, y + other.y);
	}
	// ベクトルの減算
	Vector2D operator-(const Vector2D& other) const
	{
		return Vector2D(x - other.x, y - other.y);
	}
	// ベクトルのスカラー倍
	Vector2D operator*(float scalar) const
	{
		return Vector2D(x * scalar, y * scalar);
	}
	// ベクトルのスカラー除算
	Vector2D operator/(float scalar) const
	{
		return Vector2D(x / scalar, y / scalar);
	}
	// ベクトルの加算代入演算子
	Vector2D& operator+=(const Vector2D& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}
	// ベクトルの減算代入演算子
	Vector2D& operator-=(const Vector2D& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}
	// ベクトルのスカラー倍代入演算子
	Vector2D& operator*=(float scalar)
	{
		x *= scalar;
		y *= scalar;
		return *this;
	}
	// ベクトルのスカラー除算代入演算子
	Vector2D& operator/=(float scalar)
	{
		x /= scalar;
		y /= scalar;
		return *this;
	}
	// ベクトルの等価演算子
	bool operator==(const Vector2D& other) const
	{
		return x == other.x && y == other.y;
	}
	// ベクトルの非等価演算子
	bool operator!=(const Vector2D& other) const
	{
		return !(*this == other);
	}

	// ---メンバ関数---------------------------------------------------------------
	// ベクトルの長さを計算する
	float Length() const
	{
		return std::sqrt(x * x + y * y);
	}
	// ベクトルの2乗の長さを計算する
	float LengthSquared() const
	{
		return x * x + y * y;
	}
	// ベクトルを正規化して自身を更新する
	Vector2D& Normalize()
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
	Vector2D Normalized() const
	{
		float len = Length();
		if (len == 0)
			return Vector2D{0.0f, 0.0f};
		return Vector2D(x / len, y / len);
	}

	// ---メンバ関数---------------------------------------------------------------
	// ベクトルの長さが0かどうかを判定する
	bool IsZero() const
	{
		return x == 0.0f && y == 0.0f;
	}
	// ベクトルを0にする
	void SetZero()
	{
		x = 0.0f;
		y = 0.0f;
	}
	// ベクトルの成分を設定する
	void Set(float newX, float newY)
	{
		x = newX;
		y = newY;
	}
};

// ベクトルの左辺にスカラーを掛ける演算子
inline Vector2D operator*(float scalar, const Vector2D& v)
{
	return Vector2D(v.x * scalar, v.y * scalar);
}

// ベクトルの内積を計算する関数
inline float Dot(const Vector2D& a, const Vector2D& b)
{
	return (a.x) * (b.x) + (a.y) * (b.y);
}

// ベクトルの距離を計算する関数
inline float Distance(const Vector2D& a, const Vector2D& b)
{
	float dx = (a.x) - (b.x);
	float dy = (a.y) - (b.y);
	return std::sqrt(dx * dx + dy * dy);
}

// ベクトルの距離の2乗を計算する関数
inline float DistanceSquared(const Vector2D& a, const Vector2D& b)
{
	float dx = (a.x) - (b.x);
	float dy = (a.y) - (b.y);
	return dx * dx + dy * dy;
}