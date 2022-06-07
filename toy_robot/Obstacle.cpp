#include <iostream>
#include <string>
#include "Obstacle.h"
#include "Position.h"
#include "Common.h"
#include <vector>

using namespace std;
using namespace ToyRobot;
namespace ToyRobot {
	bool Obstacle::AddObstacle(Position pos ) {
		this->_obstacles.push_back(_obstacles.size()+1);
		return false;
	}
	bool Obstacle::CheckObstacle(Position pos) {
		for(Coordinates& coordinate: _obstacles){
			if (coordinate.st_x == pos.GetPosition().st_x &&
				coordinate.st_y == pos.GetPosition().st_y &&
				coordinate.st_z == pos.GetPosition().st_z) {
				return true;
			}
		}
		return false;
	}
}