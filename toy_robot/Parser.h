#ifndef PARSER_H
#define PARSER_H
#include "toy_robot.h"

namespace ToyRobot {
	class Parser {
	public:
		Parser() {
			_command.assign("");
			_placement.assign("NORTH");
			_x = 0;
			_y = 0;
		};
		virtual ~Parser() {};
		bool ParseCommand(string, commands*, Movement*);
		bool ParseCoordinates(string, Movement*);
	private:
		string _command;
		string _placement;
		int _x;
		int _y;
	};
}

#endif PARSER_H /* PARSER_H */