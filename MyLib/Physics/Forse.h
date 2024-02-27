#ifndef FORSE_H
#define FORSE_H

#include "../math/Vec2.h"

namespace Physics{

	class Forse{

		public:
			Math::Vec2 dir;
			float module;

			Forse(): module(0) {};
			Forse(Math::Vec2 d,float m) : dir(d), module(m) {};
			Forse(Math::Vec2 d): dir(d) {};
			Forse(float m): module(m) {};

			Forse(const Forse &f);
	};
};

#endif