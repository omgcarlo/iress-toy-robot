#ifndef COMMAND_H
#define COMMAND_H
#include "toy_robot.h"
#include "Position.h"

namespace ToyRobot {
	class Command {
	public:
		Command() {};
		virtual ~Command() {};
		bool ReadPlacementCommand(string, Position*);
		type ReadCommand(string, Position*);
	private:
		string _command;
		Position _pos;
	};
}

#endif COMMAND_H /* COMMAND_H */