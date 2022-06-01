#ifndef ROBOT_H
#define ROBOT_H
#include "Command.h"
#include "toy_robot.h"

namespace ToyRobot {
	class Robot : public Command {
	public:
		Robot() {};
		virtual ~Robot() {};
		string GetLastPlace();
		void SetPosition(Movement);
	private:
		Movement _m;
	};
}

#endif ROBOT_H /* ROBOT_H */