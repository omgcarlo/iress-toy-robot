#ifndef COMMAND_H
#define COMMAND_H
#include "Position.h"
#include "Common.h"
#include <string>

namespace ToyRobot {
	class Command {
	public:
		Command() {};
		virtual ~Command() {};
		bool ReadPlacementCommand(string, Position*);
		type ReadCommand(string, commands*, Position*);
	private:
		string _command;
		Position _pos;
	};
}

#endif COMMAND_H /* COMMAND_H */