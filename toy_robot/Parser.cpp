#include <iostream>
#include <string>
#include "Parser.h"
#include "toy_robot.h"
using namespace std;
using namespace ToyRobot;
namespace ToyRobot {
	// Input : string command 
	// Output: command * c
	//         Movement * m
	bool Parser::ParseCommand(string sCommand, commands* c, Movement* m) {
		bool b_results = true;
		Movement m_movement;
		if (sCommand.compare(0, 5, "PLACE") == 0) {
			*c = ::PLACE;
			if (ParseCoordinates(sCommand, &m_movement)) {
				m->st_place = m_movement.st_place;
				m->st_x = m_movement.st_x;
				m->st_y = m_movement.st_y;
			}
			else {
				b_results = false;
			}
		}
		else if (sCommand.compare(0, 4, "MOVE") == 0) {
			*c = ::MOVE;
		}
		else if (sCommand.compare(0, 4, "LEFT") == 0) {
			*c = ::LEFT;
		}
		else if (sCommand.compare(0, 5, "RIGHT") == 0) {
			*c = ::RIGHT;
		}
		else if (sCommand.compare(0, 6, "REPORT") == 0) {
			*c = ::REPORT;
		}
		else {
			b_results = false;
		}
		return b_results;
	}
	// this function is only used by PLACE command
	bool Parser::ParseCoordinates(string sCommand, Movement* m_movement) {
		int i_x;
		int i_y;
		string s_place;
		bool b_results = true;
		try
		{
			// get x
			i_x = stoi(sCommand.substr(6, 1));
			//get y
			i_y = stoi(sCommand.substr(8, 1));
			//get placement
			s_place = (sCommand.substr(10));
			// set to struct
			m_movement->st_x = i_x;
			m_movement->st_y = i_y;

			if (s_place.compare("NORTH") == 0) {
				m_movement->st_place = NORTH;
			}
			else if (s_place.compare("SOUTH") == 0) {
				m_movement->st_place = SOUTH;
			}
			else if (s_place.compare("EAST") == 0) {
				m_movement->st_place = EAST;
			}
			else if (s_place.compare("WEST") == 0) {
				m_movement->st_place = WEST;
			}
			else {
				b_results = false;
			}
		}
		catch (const std::exception&)
		{
			return false;
		}
		return b_results;
	}
}