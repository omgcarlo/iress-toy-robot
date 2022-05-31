/////////////////////////////////////////////
// Toy Robot C++ Technical Challenge
// Date: 05/31/2022
// Created by: Carlo Jacalan
////////////////////////////////////////////
#include <iostream>
#include <string>
#include "toy_robot.h"

using namespace ToyRobot;
bool Command::ReadPlacementCommand(string sCommand) {
	Parser p;
	Movement m;
	bool b_results = true;
	if (p.ParseCommand(sCommand, &m) == true) {

	}
	else {
		return false;
	}
	return b_results;
}
bool Command::ReadCommand(string sCommand) {
	Parser p;
	Movement m;
	if (p.ParseCommand(sCommand, &m) == true) {
		// setters here
	}
	else {
		return false;
	}
	return false;
}
bool Parser::ParseCommand(string sCommand, Movement * m) {
	string s_command;
	string s_placement;
	bool b_results = true;
	Movement m_movement;
	if (sCommand.compare(0,5,"PLACE") == 0) {
		s_command = PLACE;
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
		s_command = MOVE;
	}
	else if (sCommand.compare(0, 4, "LEFT") == 0) {
		s_command = LEFT;
	}
	else if (sCommand.compare(0, 5, "RIGHT") == 0) {
		s_command = RIGHT;
	}
	else {
		b_results = false;
	}

	return b_results;
}
// this function is only used by PLACE command
bool Parser::ParseCoordinates(string sCommand, Movement * m_movement) {
	int i_x;
	int i_y;
	string s_place;
	bool b_results = true;
	try
	{
		// get x
		i_x = stoi(sCommand.substr(6,1));
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
string Robot::GetLastPlace() {
	return "X,Y NORTH";
}
int main()
{
	Robot r;
	string sInput;
	cout << "Input Robot Command:";
	getline(cin,sInput);
	if (!r.ReadPlacementCommand(sInput)) {
		cout << "Input is invalid";
	}
	while (true) {
		getline(cin, sInput);
		if (!r.ReadCommand(sInput)) {
			break;
		}
	}
	cout << r.GetLastPlace();
}
