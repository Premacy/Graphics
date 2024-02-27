#ifndef SPRITE_H
#define SPRITE_H

#include "../math/Vec2.h"

class Sprite{
	public:

		Sprite();
		Sprite(const Sprite &s);

		~Sprite();

		void draw();

	private:
		Vec2 pos;
};