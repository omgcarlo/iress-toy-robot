#include <iostream>
#include <string>
#include "Robot.h"
#include "Common.h"

using namespace std;
using namespace ToyRobot;
namespace ToyRobot {
	Robot::Robot(int id) {
		_id = id;
	}
	void Robot::SetNumberOfRobots(int number_of_robots) {
		if (number_of_robots < 1) {
			number_of_robots = 1;
		}
		for (int i = 0; i < number_of_robots; i++)
		{
			this->_v_robot.push_back(i);
		}
	}
	unsigned int Robot::GetNumberOfRobots() {
		return (unsigned int)this->_v_robot.size();
	}
	Robot Robot::GetRobot(int robot_id) {
		return this->_v_robot.at(robot_id);
	}
	void Robot::SetPosition(Coordinates m) {
		this->_m.st_place = m.st_place;
		this->_m.st_x = m.st_x;
		this->_m.st_y = m.st_y;
	}
	void Robot::SetPosition(unsigned int robot_id, Coordinates m) {
		for (Robot& r: this->_v_robot) {
			if (r.GetRobotId() == robot_id){
				this->_v_robot.at(robot_id).SetPosition(m);
				return;
			}
		}
	
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
	Position Robot::GetRobotPosition() {
		Position pos;
		pos.SetPosition(_m);
		return pos;
	}
	unsigned int Robot::GetRobotId() {
		return this->_id;
	}
	bool Robot::IsRobotCollided(Position new_pos) {
		Position robot_pos;
		int i_collide_score = 0;
		
		for (Robot& r : this->_v_robot) {
			robot_pos = r.GetRobotPosition();
			i_collide_score = 0;
			if (robot_pos.GetPosition().st_place == new_pos.GetPosition().st_place) {
				i_collide_score++;
			}
			if (robot_pos.GetPosition().st_x == new_pos.GetPosition().st_x) {
				i_collide_score++;
			}
			if (robot_pos.GetPosition().st_y == new_pos.GetPosition().st_y) {
				i_collide_score++;
			}
			if (i_collide_score == 3) {
				return true;
			}
		}
		return false;
	}
}