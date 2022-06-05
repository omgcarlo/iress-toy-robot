#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "Position.h"
#include "Common.h"

namespace ToyRobot {
	class Obstacle {
	public:
		Obstacle() {};
		virtual ~Obstacle() {};
		bool SetObstacle(int, int, int);
		
	private:
		int _x;	// x - axis
		int _y;	// y - axis
		int _z; // z - axis/face for 3D
		Coordinates _m;
	};
}

#endif OBSTACLE_H /* OBSTACLE_H */