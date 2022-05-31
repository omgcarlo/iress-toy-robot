#ifndef TOY_ROBOT_H
#define TOY_ROBOT_H

#include <iostream>
#include <string>
#define OK true
#define NG false

using namespace std;
namespace ToyRobot {
	enum commands {
		PLACE,
		MOVE,
		LEFT,
		RIGHT,
		REPORT
	};
	enum placement {
		NORTH,
		SOUTH,
		EAST,
		WEST,
	};
	struct Movement {
		int st_x;
		int st_y;
		placement st_place;
	};
	class Command {
	public:
		Command() {};
		bool ReadPlacementCommand(string);
		bool ReadCommand(string);
	private:
		string _command;

	};
	class Robot : public Command {
	public:
		Robot() {};
		string GetLastPlace();
	private:
		Movement _m;
	};
	class Position {
	public:
		Position() {};
		bool CalculateMove(commands, Movement);
		Movement GetCurrentPosition(); 
	};

	class Parser {
	public:
		Parser() {
			_command.assign("");
			_placement.assign("NORTH");
			_x = 0;
			_y = 0;
		};
		bool ParseCommand(string , Movement*);
		bool ParseCoordinates(string,Movement*);
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