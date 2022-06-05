#include <iostream>
#include <string>
#include "Parser.h"
#include "Common.h"

using namespace std;
using namespace ToyRobot;

namespace ToyRobot {
	// This function is to parse whole string command
	// Input : string sCommand 
	// Output: command * c, Movement * m
	bool Parser::ParseCommand(string sCommand, commands* c, Coordinates* coordinates) {
		bool b_results = true;
		Coordinates c_coordinates;
		if (sCommand.compare(0, 5, "PLACE") == 0) {
			*c = ::PLACE;
			if (ParseCoordinates(sCommand, &c_coordinates)) {
				coordinates->st_place = c_coordinates.st_place;
				coordinates->st_x = c_coordinates.st_x;
				coordinates->st_y = c_coordinates.st_y;
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
		else if (sCommand.compare(0, 8, "OBSTACLE") == 0) {
			*c = ::OBSTACLE;
		}
		else {
			b_results = false;
		}
		return b_results;
	}
	// this function is only used by PLACE & OBSTACLE command
	// Input : string command 
	// Output: Coordinates * coordinates
	bool Parser::ParseCoordinates(string sCommand, Coordinates* coordinates) {
		int i_x;
		int i_y;
		string s_place;
		bool b_results = true;
		try
		{
			if (sCommand.compare(0, 5, "PLACE") == 0) {
				// get x
				i_x = stoi(sCommand.substr(6, 1));
				//get y
				i_y = stoi(sCommand.substr(8, 1));
				//get placement
				s_place = (sCommand.substr(10));
				// set to struct
				coordinates->st_x = i_x;
				coordinates->st_y = i_y;

				if (s_place.compare("NORTH") == 0) {
					coordinates->st_place = NORTH;
				}
				else if (s_place.compare("SOUTH") == 0) {
					coordinates->st_place = SOUTH;
				}
				else if (s_place.compare("EAST") == 0) {
					coordinates->st_place = EAST;
				}
				else if (s_place.compare("WEST") == 0) {
					coordinates->st_place = WEST;
				}
				else {
					b_results = false;
				}
			}
			else if (sCommand.compare(0, 8, "OBSTACLE") == 0) {
				// get x
				i_x = stoi(sCommand.substr(9, 1));
				//get y
				i_y = stoi(sCommand.substr(10, 1));
				// set to struct
				coordinates->st_x = i_x;
				coordinates->st_y = i_y;
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
	/// <summary>
	/// This function is only used by Table Dimension Setting
	/// </summary>
	/// <param name="sCommand">Input : string sCommand </param>
	/// <param name="t">Output: Table* t</param>
	/// <returns></returns>
	bool Parser::ParseTableDimension(string sCommand, Table* t) {
		int i_x;
		int i_y;
		string s_place;
		bool b_results = true;
		try
		{
			// get x
			i_x = stoi(sCommand.substr(0, 1));
			//get y
			i_y = stoi(sCommand.substr(2, 1));
			// set to table
			t->SetTableDimension(i_x, i_y);
		}
		catch (const std::exception&)
		{
			return false;
		}
		return b_results;
	}
	/// <summary>
	/// Parse Robot Id from command
	/// </summary>
	/// <param name="sCommand"> command from getline</param>
	/// <param name="r_id">output: robot id</param>
	/// <returns>function status</returns>
	bool Parser::ParseRobotId(string sCommand, int * r_id) {
		bool b_results = true;
		try {
			if (sCommand.compare(0, 4, "MOVE") == 0) {
				*r_id = stoi(sCommand.substr(5,1));
			}
			else if (sCommand.compare(0, 4, "LEFT") == 0) {
				*r_id = stoi(sCommand.substr(5, 1));
			}
			else if (sCommand.compare(0, 5, "RIGHT") == 0) {
				*r_id = stoi(sCommand.substr(6, 1));
			}
			else if (sCommand.compare(0, 6, "REPORT") == 0) {
				*r_id = stoi(sCommand.substr(7, 1));
			}
			else {
				b_results = false;
			}
		}
		catch (...) {
			b_results = false;
		}
		
		return b_results;
	}
}