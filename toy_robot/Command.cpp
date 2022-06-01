#include "Command.h"
#include "toy_robot.h"
#include "Parser.h"
#include "Position.h"

using namespace std;
using namespace ToyRobot;
namespace ToyRobot {
	bool Command::ReadPlacementCommand(string sCommand, Position* pos) {
		Parser p;
		Movement m;
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
	type Command::ReadCommand(string sCommand, Position* pos) {
		Parser p;
		Movement m;
		commands c;
		bool b_results = true;
		type t_results;
		if (p.ParseCommand(sCommand, &c, &m) == true) {
			m = pos->GetPosition();
			t_results = pos->CalculateMove(c, m, pos);
			_pos = *pos;
		}
		else {
			b_results = false;
		}
		return t_results;
	}
}