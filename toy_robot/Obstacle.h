#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "Position.h"
#include "Common.h"

namespace ToyRobot {
	class Obstacle {
	public:
		Obstacle() {};
		virtual ~Obstacle() {};
		bool SetObstacle(Position);
		bool CheckObstacle(Position);
	private:
		Coordinates _coordinates;
	};
}

#endif OBSTACLE_H /* OBSTACLE_H */