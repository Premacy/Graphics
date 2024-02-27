#include "Vec2.h"

namespace Math{

	Vec2::Vec2(const Vec2 &v){
		x = v.x;
		y = v.y;
	}

	float Vec2::scalar_product(const Vec2 &v1, const Vec2 &v2){
		return (v1.x * v2.x + v1.y * v1.y);
	}

	float Vec2::len(const Vec2 &v){
		return Vec2::scalar_product(v, v);
	}

	float Vec2::len(void) const{
		return Vec2::len(*this);
	}

	float Vec2::dist(const Vec2 &v1, const Vec2 &v2){
		Vec2 v = v1 - v2;
		return Vec2::len(v);
	}

	float Vec2::dist(const Vec2 &v) const{
		return Vec2::dist(*this, v);
	}

	void Vec2::operator =(const Vec2 &v){
		x = v.x;
		y = v.y;
	}

	float Vec2::operator [](const unsigned int i){
		if(i >= 2){
			return 0;
		}

		return i == 0 ? x : y;
	}

	bool Vec2::is_null(void) const{
		return (x == 0 && y == 0);
	}

	float Vec2::scalar_product(const Vec2 &v1){
		return scalar_product(*this, v1);
	}

	Vec2 operator +(const Vec2 &v1, const Vec2 &v2){
		Vec2 v(v1.x + v2.x, v1.y + v2.y);
		return v;
	}

	Vec2 operator -(const Vec2 &v1, const Vec2 &v2){
		Vec2 v(v1.x - v2.x, v1.y - v2.y);
		return v;
	}

	Vec2 operator *(float scalar, const Vec2 &v){
		Vec2 r(v.x * scalar, v.y * scalar);
		return r;
	}	

	std::ostream& operator <<(std::ostream &stream, const Vec2 &v){
		stream << "x = " << v.x << ", y =  " << v.y << std::endl;
		return stream;
	}

	bool operator ==(const Vec2 &v1, const Vec2 &v2){
		return ( (v1.x == v2.x) && (v1.y == v2.y) );
	}

	/*std::string to_string(void) const{
		std::string str()
	}*/

};