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
	if (p.ParseCommand(sCommand) == true) {
		// g
		// setters here
	}
	else {
		return false;
	}

}
bool Command::ReadCommand(string sCommand) {
	Parser p;
	if (p.ParseCommand(sCommand) == true) {
		// setters here
	}
	else {
		return false;
	}
	
}
bool Parser::ParseCommand(string sCommand) {
	string s_command;
	string s_placement;
	int i_x;
	int i_y;

	return false;
}

int main()
{
	Robot r;
	string sInput;
	cout << "Input Robot Command:";
	cin >> sInput;
	r.ReadCommand(sInput);
    
}
