#pragma once

#include <vector>
#include <algorithm>
#include <initializer_list>

#include "Quaternion.h"

namespace Math{

template<typename T>
class MathVector : public std::vector<T>{
public:
	MathVector( ) = default;
	MathVector( const MathVector &v ) = default;

	explicit MathVector( std::size_t size ): std::vector<T>(size) {}
	explicit MathVector( std::initializer_list<T> l) : std::vector<T>(l) {}
	explicit MathVector( std::vector<T> v ) : std::vector<T>(v) {}

	template<class InputIter> MathVector(InputIter begin, InputIter end) : std::vector<T>(begin, end){};

	MathVector& operator=(const MathVector &v) = default;

	~MathVector( ) = default;

	friend MathVector operator +(const MathVector &v1, const MathVector &v2);
	friend MathVector operator *(const MathVector &v1, const MathVector &v2);
	friend MathVector operator /(const MathVector &v1, const MathVector &v2);

	MathVector& +=(const MathVector &v);
	MathVector& -=(const MathVector &v);

	friend MathVector operator *(const MathVector &v1, const T &scalar);
	friend MathVector operator /(const MathVector &v1, const T & calar);

	MathVector& operator *=(const T &scalar);
	MathVector& operator /=(const T &scalar);

	static T scalarProduct(const MathVector &v1, const MathVector &v2);
};

template<typename T> 
class MathVector3 : public MathVector{
public:
	
};

}
