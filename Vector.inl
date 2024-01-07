#include <Core/Math.h>

inline float Vector2f::Length() const noexcept
{
	return math::Sqrt(x * x + y * y);
}

inline constexpr float Vector2f::LengthSqr() const noexcept
{
	return x * x + y * y;
}

inline void Vector2f::Limit(const float value) noexcept
{
	// assumes that value >= 0.f
	const float length = Length();
	if (length > value)
		*this *= (value / length);
}

inline void Vector2f::Normalize() noexcept
{
	constexpr float epsilon = 0.0000001f;
	const float length = Length();
	if (length > epsilon)
	{
		*this *= 1.f / length;
	}
	else
	{
		x = y = 0.f;
	}
}

inline void Vector2f::NormalizeUnsafe() noexcept
{
	*this *= 1.f / Length();
}

inline Vector2f Vector2f::Limited(const float value) const noexcept
{
	Vector2f result(*this);
	result.Limit(value);
	return result;
}

inline Vector2f Vector2f::Normalized() const noexcept
{
	Vector2f result(*this);
	result.Normalize();
	return result;
}

inline Vector2f Vector2f::NormalizedUnsafe() const noexcept
{
	Vector2f result(*this);
	result.NormalizeUnsafe();
	return result;
}

inline constexpr Vector3f Vector2f::X0Y() const noexcept
{
	return Vector3f(x, 0.f, y);
}

inline constexpr Vector3f Vector2f::XY0() const noexcept
{
	return Vector3f(*this, 0.f);
}

inline constexpr Vector2f math::Clamp(const Vector2f& value, const Vector2f& min, const Vector2f& max) noexcept
{
	return Vector2f(
		(value.x < min.x) ? min.x : (value.x > max.x) ? max.x : value.x,
		(value.y < min.y) ? min.y : (value.y > max.y) ? max.y : value.y);
}

inline float math::Distance(const Vector2f& a, const Vector2f& b) noexcept
{
	return (b - a).Length();
}

inline constexpr float math::DistanceSqr(const Vector2f& a, const Vector2f& b) noexcept
{
	return (b - a).LengthSqr();
}

inline constexpr Vector2f math::Divide(const Vector2f& a, const Vector2f& b) noexcept
{
	return Vector2f(a.x / b.x, a.y / b.y);
}

inline constexpr float math::Dot(const Vector2f& a, const Vector2f& b) noexcept
{
	return a.x * b.x + a.y * b.y;
}

template<>
inline constexpr Vector2f math::Max<Vector2f>(const Vector2f& a, const Vector2f& b) noexcept
{
	return Vector2f(
		(a.x > b.x) ? a.x : b.x,
		(a.y > b.y) ? a.y : b.y);
}

template<>
inline constexpr Vector2f math::Min<Vector2f>(const Vector2f& a, const Vector2f& b) noexcept
{
	return Vector2f(
		(a.x < b.x) ? a.x : b.x,
		(a.y < b.y) ? a.y : b.y);
}

inline constexpr Vector2f math::Multiply(const Vector2f& a, const Vector2f& b) noexcept
{
	return Vector2f(a.x * b.x, a.y * b.y);
}

inline constexpr Vector2f math::Perpendicular(const Vector2f& vector) noexcept
{
	return Vector2f(vector.y, -vector.x);
}

inline constexpr Vector2f math::Reflect(const Vector2f& vector, const Vector2f& normal) noexcept
{
	// -2 * (V dot N) * N + V
	const float dot2 = -2.0f * math::Dot(vector, normal);
	return math::Multiply(Vector2f(dot2), normal) + vector;
}