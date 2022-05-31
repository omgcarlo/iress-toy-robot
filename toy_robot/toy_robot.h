#ifndef TOY_ROBOT_H
#define TOY_ROBOT_H

#include <iostream>
#include <string>
#define OK true
#define NG false

using namespace std;
namespace ToyRobot {
	class Robot : public Command {
	public:
		Robot() {};
	};
	class Position {
	public:
		Position() {};

	};
	class Command {
	public:
		Command() {};
		bool ReadPlacementCommand(string);
		bool ReadCommand(string);
		
	private:
		bool IsValidCommand(string);
		string _command;

	};
	class Parser {
	public:
		Parser() {
			_command.assign("");
			_placement.assign("NORTH");
			_x = 0;
			_y = 0;
		};
		bool ParseCommand(string s);
	private:
		string _command;
		string _placement;
		int _x;
		int _y;
	};
	class Table {

	};
}
#endif /* TOY_ROBOT_H */