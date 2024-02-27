#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>

class Animation{
	public:
		Animation(int interval) : time_tick(interval) {};

		void load_images(const std::vector<unsigned int> &images);
		void animate(void);
	private:
		std::vector<unsigned int> images;
		float time_tick;
};

#endif