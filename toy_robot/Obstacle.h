#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "Position.h"
#include "Common.h"
#include <unordered_map>

namespace ToyRobot {
	class Obstacle {
	public:
		Obstacle() {};
		Obstacle(int id){
			_obs_id = id;
		};
		virtual ~Obstacle() {};
		// add size
		bool AddObstacle(Position, unsigned int);
		bool CheckObstacle(Position);
	private:
		std::vector<Coordinates> _obstacles;
		std::unordered_map<Coordinates, unsigned int> umap_obs;

		int _obs_id;
	};
}

#endif OBSTACLE_H /* OBSTACLE_H */