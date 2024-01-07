#pragma once

class Vector3f;

/// \brief A geometric object that has length and direction that can be used to represent positions and/or directions in 2d.
class Vector2f
{
public:
	/// \brief Construct a new vector with uninitialized members.
	constexpr Vector2f() noexcept : x(), y() {}
	/// \brief Construct a new vector with both members initialized to value.
	constexpr explicit Vector2f(const float value) noexcept : x(value), y(value) {}
	/// \brief Construct a new vector with members initialized to values x and y.
	constexpr explicit Vector2f(const float x, const float y) noexcept : x(x), y(y) {}

	/// \brief Returns true if both members are identical.
	constexpr bool operator==(const Vector2f& rhs) const noexcept { return (x == rhs.x) && (y == rhs.y); }
	/// \brief Returns true if either members aren't identical.
	constexpr bool operator!=(const Vector2f& rhs) const noexcept { return (x != rhs.x) || (y != rhs.y); }

	/// \brief Adds the two vectors component-wise and returns the result in a new vector.
	constexpr Vector2f operator+(const Vector2f& rhs) const noexcept { return Vector2f(x + rhs.x, y + rhs.y); }
	/// \brief Subtracts the two vectors component-wise and returns the result in a new vector.
	constexpr Vector2f operator-(const Vector2f& rhs) const noexcept { return Vector2f(x - rhs.x, y - rhs.y); }

	/// \brief Adds the two vectors component-wise, stores the result in this vector and returns a reference.
	constexpr Vector2f& operator+=(const Vector2f& rhs) noexcept { x += rhs.x; y += rhs.y; return *this; }
	/// \brief Subtracts the two vectors component-wise, stores the result in this vector and returns a reference.
	constexpr Vector2f& operator-=(const Vector2f& rhs) noexcept { x -= rhs.x; y -= rhs.y; return *this; }

	/// \brief Multiplies the vector by a value and returns the result in a new vector.
	constexpr Vector2f operator*(const float rhs) const noexcept { return Vector2f(x * rhs, y * rhs); }
	/// \brief Divides the vector by a value and returns the result in a new vector.
	constexpr Vector2f operator/(const float rhs) const noexcept { return Vector2f(x / rhs, y / rhs); }

	/// \brief Multiplies the vector by a value, stores the result in this vector and returns a reference.
	constexpr Vector2f& operator*=(const float rhs) noexcept { x *= rhs; y *= rhs; return *this; }
	/// \brief Divides the vector by a value, stores the result in this vector and returns a reference.
	constexpr Vector2f& operator/=(const float rhs) noexcept { x /= rhs; y /= rhs; return *this; }

	/// \brief Returns a new vector with non-negated members.
	constexpr Vector2f operator+() const noexcept { return *this; }
	/// \brief Returns a new vector with negated members.
	constexpr Vector2f operator-() const noexcept { return Vector2f(-x, -y); }

	/// \brief Returns the length of this vector.
	float Length() const noexcept;
	/// \brief Returns the squared length of this vector.
	constexpr float LengthSqr() const noexcept;

	/// \brief Reduce the vector length so that it doesn't exceed value.
	/// If the length of the vector is 0 and value is less than 0 then it makes it a NaN vector.
	void Limit(const float value) noexcept;
	/// \brief Normalize this vector have a length of 1 unit.
	/// If the length of the vector is 0 then it makes it a zero vector.
	void Normalize() noexcept;
	/// \brief Normalize this vector have a length of 1 unit.
	/// If the length of the vector is 0 then it makes it a NaN vector.
	void NormalizeUnsafe() noexcept;

	/// \brief Returns a vector whose length doesn't exceed value.
	/// If the length of the vector is 0 and value is less than it returns a NaN vector.
	[[nodiscard]] Vector2f Limited(const float value) const noexcept;
	/// \brief Returns a normalized vector with a length of 1 unit.
	/// If the length of the vector is 0 then it returns a zero vector.
	[[nodiscard]] Vector2f Normalized() const noexcept;
	/// \brief Returns a normalized vector with a length of 1 unit.
	/// If the length of the vector is 0 then it returns a NaN vector.
	[[nodiscard]] Vector2f NormalizedUnsafe() const noexcept;

	/// \brief Converts this vector to a Vector3f with 0 in place of Y, and Y in place of Z.
	constexpr Vector3f X0Y() const noexcept;
	/// \brief Converts this vector to a Vector3f with 0 in place of Z.
	constexpr Vector3f XY0() const noexcept;

	/// \brief Shorthand for writing Vector2f(1.f, 0.f).
	static const Vector2f AxisX;
	/// \brief Shorthand for writing Vector2f(0.f, 1.f).
	static const Vector2f AxisY;
	/// \brief Shorthand for writing Vector2f(1.f).
	static const Vector2f One;
	/// \brief Shorthand for writing Vector2f(0.f).
	static const Vector2f Zero;

public:
	float x, y;
};

inline constexpr Vector2f Vector2f::AxisX(1.f, 0.f);
inline constexpr Vector2f Vector2f::AxisY(0.f, 1.f);
inline constexpr Vector2f Vector2f::One(1.f);
inline constexpr Vector2f Vector2f::Zero(0.f);

namespace math
{
	inline constexpr Vector2f Clamp(const Vector2f& value, const Vector2f& min, const Vector2f& max) noexcept;

	/// \brief Returns the distance between two vectors.
	inline float Distance(const Vector2f& a, const Vector2f& b) noexcept;

	/// \brief Returns the squared distance between two vectors.
	inline constexpr float DistanceSqr(const Vector2f& a, const Vector2f& b) noexcept;

	/// \brief Divides the two vectors component-wise and returns the result in a new vector.
	inline constexpr Vector2f Divide(const Vector2f& a, const Vector2f& b) noexcept;

	/// \brief Returns the dot product of two vectors.
	inline constexpr float Dot(const Vector2f& a, const Vector2f& b) noexcept;

	/// \brief Multiplies the two vectors component-wise and returns the result in a new vector.
	inline constexpr Vector2f Multiply(const Vector2f& a, const Vector2f& b) noexcept;

	/// \brief Rotates a vector 90 degrees (clockwise) to the original vector and returns the result in a new vector.
	inline constexpr Vector2f Perpendicular(const Vector2f& vector) noexcept;

	/// \brief Reflects a vector off the vector defined by a normal.
	inline constexpr Vector2f Reflect(const Vector2f& vector, const Vector2f& normal) noexcept;
}