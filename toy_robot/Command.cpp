#include "Command.h"
#include "Parser.h"
#include "Position.h"
#include "Common.h"
#include <string>

using namespace std;
using namespace ToyRobot;
namespace ToyRobot {
	bool Command::ReadPlacementCommand(string sCommand, Position* pos) {
		Parser p;
		Coordinates m;
		commands c;
		bool b_results = true;
		if (p.ParseCommand(sCommand, &c, &m) == true) {
			if (c != commands::PLACE) {
				b_results = false;
			}
			pos->SetPosition(m);
		}
		else {
			return false;
		}
		return b_results;
	}
	type Command::ReadCommand(string sCommand,commands * com, Position* pos) {
		Parser parser;
		Coordinates coordinates;
		commands command;
		type t_results;
		if (parser.ParseCommand(sCommand, &command, &coordinates) == true) {
			if (command == OBSTACLE) {
				parser.ParseCoordinates(sCommand, &coordinates);
				t_results = OTHER;
				return t_results;
			}
			coordinates = pos->GetPosition();
 			t_results = pos->CalculateMove(command, coordinates, pos);
			_pos = *pos;
		}
		return t_results;
	}
}