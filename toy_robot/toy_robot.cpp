/////////////////////////////////////////////
// Toy Robot C++ Technical Challenge
// Date: 05/31/2022
// Created by: Carlo Jacalan
////////////////////////////////////////////
#include <iostream>
#include <string>
#include "toy_robot.h"
#include "Robot.h"
#include "Position.h"
#include <vector>

using namespace ToyRobot;

int main()
{
	Robot r;
	Position p;
	string sInput;
	std::vector<Robot> robot;
	
	cout << "Input Table Size[X,Y]:";
	getline(cin,sInput);
	p.SetTableDimension(5,5);
	cout << "======Toy Robot========\n";
	cout << "=                     =\n";
	cout << "Input Robot Command:\n";
	getline(cin,sInput);

	if (!r.ReadPlacementCommand(sInput, &p)) {
		cout << "Input is invalid";
		return 0;
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
	system("pause");
	return 0;

}



