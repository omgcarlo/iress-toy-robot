#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "Position.h"
#include "Common.h"

namespace ToyRobot {
	class Obstacle {
	public:
		Obstacle() {};
		Obstacle(int id){
			_obs_id = id;
		};
		virtual ~Obstacle() {};
		bool SetObstacle(Position);
		bool CheckObstacle(Position);
	private:
		std::vector<Coordinates> _obstacles;
		int _obs_id;
	};
}

#endif OBSTACLE_H /* OBSTACLE_H */