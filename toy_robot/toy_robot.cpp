/////////////////////////////////////////////
// Toy Robot C++ Technical Challenge
// Date: 05/31/2022
// Created by: Carlo Jacalan
////////////////////////////////////////////
#include <iostream>
#include <string>
#include "toy_robot.h"

using namespace ToyRobot;
// 
bool Position::CalculateMove(commands c, Movement m, Position *p) {
	switch (c)
	{
	case ToyRobot::PLACE:
		break;
	case ToyRobot::MOVE:
		break;
	case ToyRobot::LEFT:
		break;
	case ToyRobot::RIGHT:
		break;
	case ToyRobot::REPORT:
		break;
	default:
		break;
	}
	return false;
}
void Robot::SetPosition(Movement m) {
	this->_m.st_place = m.st_place;
	this->_m.st_x = m.st_x;
	this->_m.st_y = m.st_y;
}
void Position::SetPosition(Movement m) {
	this->_m.st_place = m.st_place;
	this->_m.st_x = m.st_x;
	this->_m.st_y = m.st_y;
}
bool Command::ReadPlacementCommand(string sCommand, Position* pos) {
	Parser p;
	Movement m;
	commands c;
	bool b_results = true;
	if (p.ParseCommand(sCommand,&c, &m) == true) {
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
bool Command::ReadCommand(string sCommand, Position * pos) {
	Parser p;
	Movement m;
	commands c;
	if (p.ParseCommand(sCommand,&c, &m) == true) {
		if (!pos->CalculateMove(c, m, pos)) {
			return false;
		}
	}
	else {
		return false;
	}
	return false;
}
bool Parser::ParseCommand(string sCommand, commands * c, Movement * m) {
	commands c_command;
	bool b_results = true;
	Movement m_movement;
	if (sCommand.compare(0,5,"PLACE") == 0) {
		c_command = PLACE;
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
		c_command = MOVE;
	}
	else if (sCommand.compare(0, 4, "LEFT") == 0) {
		c_command = LEFT;
	}
	else if (sCommand.compare(0, 5, "RIGHT") == 0) {
		c_command = RIGHT;
	}
	else {
		b_results = false;
	}
	c = &c_command;
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
	Position p;
	string sInput;
	cout << "Input Robot Command:";
	getline(cin,sInput);
	if (!r.ReadPlacementCommand(sInput, &p)) {
		cout << "Input is invalid";
	}
	while (true) {
		getline(cin, sInput);
		if (!r.ReadCommand(sInput,&p)) {
			break;
		}
	}
	cout << r.GetLastPlace();
}
