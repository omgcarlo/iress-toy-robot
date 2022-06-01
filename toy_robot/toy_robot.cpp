/////////////////////////////////////////////
// Toy Robot C++ Technical Challenge
// Date: 05/31/2022
// Created by: Carlo Jacalan
////////////////////////////////////////////
#include <iostream>
#include <string>
#include "toy_robot.h"


using namespace ToyRobot;


/*
int main()
{
	Robot r;
	Position p;
	string sInput;
	p.SetTableDimension(5,5);
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
	return 0;

}
*/


