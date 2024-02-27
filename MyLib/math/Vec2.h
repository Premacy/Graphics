#ifndef VEC2_H
#define VEC2_H

#include <iostream>
#include <string>
#include <cmath>

namespace Math{

	class Vec2{

	public:

		Vec2(): x(0), y(0) {};
		Vec2(float _x, float _y): x(_x), y(_y) {};
		Vec2(const Vec2 &v);

		void operator =(const Vec2 &v);

		static float scalar_product(const Vec2 &v1, const Vec2 &v2);
		static float len(const Vec2 &v);
		static float dist(const Vec2 &v1, const Vec2 &v2);

		float scalar_product(const Vec2 &v1);
		float len(void) const;
		float dist(const Vec2 &v) const;

		//std::size_t size(void) const;

		float operator [](const unsigned int i);

		bool is_null(void) const;

		friend bool operator ==(const Vec2 &v1, const Vec2 &v2);

		friend Vec2 operator +(const Vec2 &v1, const Vec2 &v2);
		friend Vec2 operator -(const Vec2 &v1, const Vec2 &v2);
		friend Vec2 operator *(float scalar, const Vec2 &v);

		friend std::ostream& operator <<(std::ostream &stream, const Vec2 &v);

		//std::string to_string(void) const;

		float x, y;
	};
};

#endif