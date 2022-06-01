#include <iostream>
#include <string>
#include "Robot.h"
#include "toy_robot.h"

using namespace std;
using namespace ToyRobot;
namespace ToyRobot {
	void Robot::SetPosition(Movement m) {
		this->_m.st_place = m.st_place;
		this->_m.st_x = m.st_x;
		this->_m.st_y = m.st_y;
	}

	string Robot::GetLastPlace() {
		string sOutput;
		sOutput.append(to_string(_m.st_x));
		sOutput.append(",");
		sOutput.append(to_string(_m.st_y));
		sOutput.append(",");
		switch (_m.st_place)
		{
		case ::NORTH:
			sOutput.append("NORTH");
			break;
		case ::SOUTH:
			sOutput.append("SOUTH");
			break;
		case ::EAST:
			sOutput.append("EAST");
			break;
		case ::WEST:
			sOutput.append("WEST");
			break;
		default:
			break;
		}
		return sOutput;
	}
}