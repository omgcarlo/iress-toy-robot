/////////////////////////////////////////////
// Toy Robot C++ Technical Challenge
// Date: 05/31/2022
// Created by: Carlo Jacalan
////////////////////////////////////////////
#include <iostream>
#include <string>
#include "toy_robot.h"

using namespace ToyRobot;
void Table::SetTableDimension(int x, int y){
	this->_dimensionX = x;
	this->_dimensionY = y;
}
int Table::GetTableDimensionX(){
	return _dimensionX;
}
int Table::GetTableDimensionY(){
	return _dimensionY;
}
// 
type Position::CalculateMove(commands c, Movement m, Position *p) {
	switch (c)
	{
	case ToyRobot::PLACE:
		break;
	case ToyRobot::MOVE:
		if(m.st_place == ::NORTH){
			if(m.st_y < p->GetTableDimensionX()){
				m.st_y++;
			}
			else{
				return ::OVER;
			}
		}
		else if(m.st_place == ::SOUTH){
			if(m.st_y > 0){
				m.st_y--;
			}
			else{
				return ::OVER;
			}
		}
		else if(m.st_place == ::EAST){
			if(m.st_x < p->GetTableDimensionX()){
				m.st_x++;
			}
			else{
				return ::OVER;
			}
		}
		else if(m.st_place == ::WEST){
			if(m.st_x > 0){
				m.st_x--;
			}
			else{
				return ::OVER;
			}
		}
		else{
			return ::FAILED;
		}
		
		break;
	case ToyRobot::LEFT:
		if(m.st_place == ::NORTH){
			m.st_place = ::WEST;
		}
		else if(m.st_place == ::SOUTH){
			m.st_place = ::EAST;
		}
		else if(m.st_place == ::EAST){
			m.st_place = ::SOUTH;
		}
		else if(m.st_place == ::WEST){
			m.st_place = ::NORTH;
		}
		else{
			return ::FAILED;
		}
		break;
	case ToyRobot::RIGHT:
		if(m.st_place == ::NORTH){
			m.st_place = ::WEST;
		}
		else if(m.st_place == ::SOUTH){
			m.st_place = ::EAST;
		}
		else if(m.st_place == ::EAST){
			m.st_place = ::SOUTH;
		}
		else if(m.st_place == ::WEST){
			m.st_place = ::NORTH;
		}
		else{
			return FAILED;
		}
		break;
	case ToyRobot::REPORT:
		return STOP;
		break;
	default:
		return FAILED;
		break;
	}
	p->SetPosition(m);
	
	return SUCCESS;
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
		_pos = *pos;
	}
	else {
		return false;
	}
	return false;
}
// Input : string command 
// Output: command * c
//         Movement * m
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
	string sOutput;
	sOutput.append(_m.st_x + "," + _m.st_y);
	switch (_m.st_place)
	{
	case ::NORTH:
		sOutput.append("NORTH");
		break; 
	case ::SOUTH:
		sOutput.append("SOUTH");
		break; 
	case ::EAST:
		sOutput.append("EAST");
		break; 
	case ::WEST:
		sOutput.append("WEST");
		break; 
	default:
		break;
	}
	return sOutput;
}
int main()
{
	Robot r;
	Position p;
	string sInput;
	p.SetTableDimension(5,5);
	cout << "Input Robot Command:";
	getline(cin,sInput);
	if (!r.ReadPlacementCommand(sInput, &p)) {
		cout << "Input is invalid";
	}
	r.SetPosition(p.GetPosition());
	while (true) {
		getline(cin, sInput);
		if (r.ReadCommand(sInput,&p) == STOP) {
			break;
		}
	}
	r.SetPosition(p.GetPosition());
	cout << r.GetLastPlace();
}
