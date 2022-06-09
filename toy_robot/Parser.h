#ifndef PARSER_H
#define PARSER_H
#include "Position.h"
#include "Common.h"


namespace ToyRobot {
	class Parser {
	public:
		Parser() {
			_command.assign("");
			_placement.assign("");
			_x = 0;
			_y = 0;
		};
		virtual ~Parser() {};
		bool ParseCommand(string, commands*, Coordinates*);
		bool ParseCoordinates(string, Coordinates*);
		bool ParseTableDimension(string, Table*);
		bool ParseRobotId(string, int *);
		bool ParseObstacle(string, Position*);
	private:
		string _command;
		string _placement;
		int _x;
		int _y;
		int _robot_id;
	};
}

#endif PARSER_H /* PARSER_H */