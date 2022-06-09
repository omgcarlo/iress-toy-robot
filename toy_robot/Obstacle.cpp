#include <iostream>
#include <string>
#include "Obstacle.h"
#include "Position.h"
#include "Common.h"
#include <vector>


using namespace std;
using namespace ToyRobot;
namespace ToyRobot {
	bool Obstacle::AddObstacle(Position pos, unsigned int size ) {
		// Add checking if position is over
		// Add size to the obstacle

		// Add checking for any robot within the position
		// Denied obstacle if robots are in the position/coordinates

		// Need testing for this statement
		//umap_obs.insert(pos.GetPosition(), size);
		return true;
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