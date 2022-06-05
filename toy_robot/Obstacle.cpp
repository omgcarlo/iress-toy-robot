#include <iostream>
#include <string>
#include "Obstacle.h"
#include "Position.h"
#include "Common.h"

using namespace std;
using namespace ToyRobot;
namespace ToyRobot {
	bool Obstacle::SetObstacle(Position pos ) {
		this->_coordinates = pos.GetPosition();
		return false;
	}
	bool Obstacle::CheckObstacle(Position pos) {
		if (this->_coordinates.st_x == pos.GetPosition().st_x &&
			this->_coordinates.st_y == pos.GetPosition().st_y &&
			this->_coordinates.st_z == pos.GetPosition().st_z) {
			return true;
		}
		return false;
	}
}