#ifndef ROBOT_H
#define ROBOT_H
#include "Command.h"
#include <vector>

namespace ToyRobot {
	class Robot : public Command {
	public:
		Robot() {};
		Robot(int);
		virtual ~Robot() {};
		string GetLastPlace();
		void SetPosition(Coordinates);
		void SetPosition(unsigned int, Coordinates);
		Position GetRobotPosition();
		void SetNumberOfRobots(int);
		unsigned int GetNumberOfRobots();
		Robot GetRobot(int);
		bool IsRobotCollided(Position);
		unsigned int GetRobotId();
	private:
		std::vector<Robot> _v_robot;
		Coordinates _m;
		unsigned int _id;
	};
}

#endif ROBOT_H /* ROBOT_H */