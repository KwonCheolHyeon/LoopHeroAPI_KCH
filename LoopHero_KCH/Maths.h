#pragma once
#include <math.h>
#define PI 3.141592



namespace ch
{
	/*x도 = x * π / 180라디안

		x라디안 = x * 180 / π도*/

		//180 degree = π radian

		//	1 degree = π / 180 radian

		//	x degree = x * π / 180 radian



		//	π radian = 180 degree

		//	1 radian = 180 / π degree

		//	x radian = x * 180 / π degree

	struct Vector2
	{
		static Vector2 Zero;
		static Vector2 One;
		static Vector2 Two;
		static Vector2 Right;
		static Vector2 TwoPointFive;
		static Vector2 Left;
		static Vector2 Up;
		static Vector2 Down;

		float x;
		float y;

		Vector2(float x, float y)
		{
			this->x = x;
			this->y = y;
		}

		Vector2(const Vector2& other) = default;
		Vector2() = default;
		~Vector2() = default;

		Vector2 operator /(const float value)
		{
			Vector2 temp;
			temp.x = x / value;
			temp.y = y / value;

			return temp;
		}

		Vector2 operator +(const Vector2& other)
		{
			Vector2 temp;
			temp.x = x + other.x;
			temp.y = y + other.y;

			return temp;
		}

		Vector2& operator*(const float other)
		{
			x = x * other;
			y = y * other;

			return *this;
		}

		Vector2 operator -(const Vector2& other)
		{
			Vector2 temp;
			temp.x = x - other.x;
			temp.y = y - other.y;

			return temp;
		}
		
		void operator +=(const Vector2& other)
		{
			x += other.x;
			y += other.y;
		}

		void operator *=(const float value)
		{
			x *= value;
			y *= value;
		}

		float Length()
		{
			return sqrtf(x * x + y * y);
		}

		Vector2& Normailize()
		{
			float length = Length();

			x /= length;
			y /= length;

			return *this;
		}
	};

	namespace math
	{
		inline float DegreeToRadian(float degree)
		{
			return degree * PI / 180.0f;
		}

		inline float RadianToDegree(float radian)
		{
			return radian * (180.0f / PI);
		}

		inline Vector2 Rotate(const Vector2 value, float degree)
		{
			Vector2 ret = Vector2::Zero;
			float radian = DegreeToRadian(degree);
			ret.x = value.x * cosf(radian) - value.y * sinf(radian);
			ret.y = value.x * sinf(radian) + value.y * cosf(radian);

			return ret;
		}
	}

}