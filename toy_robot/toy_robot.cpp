/////////////////////////////////////////////
// Toy Robot C++ Technical Challenge
// Date: 05/31/2022
// Created by: Carlo Jacalan
////////////////////////////////////////////
#include <iostream>
#include <string>
#include "toy_robot.h"
#include "Obstacle.h"
#include "Robot.h"
#include "Position.h"
#include "Parser.h"
#include "Table.h"
#include "Common.h"

#include <vector>

using namespace ToyRobot;

int main()
{
	Robot robot;
	Command command;
	Position position;
	Parser parser;
	Table table;
	Obstacle obstacle;
	commands cmd;

	string sInput;
	int robot_id;
	unsigned int n_robots = 1;
	type t_results;
	std::vector<Robot> v_robot;
	
	while(true){
		cout << "Input Table Size[X,Y]:";
		getline(cin,sInput);
		if (parser.ParseTableDimension(sInput, &table)) {
			position.SetTableDimension(table.GetTableDimensionX(),
										table.GetTableDimensionY());
			break;
		}
		else {
			cout << "Invalid Input\n";
			system("pause");
			system("cls");
		}
	}
	cout << "Enter number of Robots\n";
	// Set robot number here
	
	cin >> n_robots;

	robot.SetNumberOfRobots(n_robots);
	cin.ignore();

	for (size_t i = 0; i < robot.GetNumberOfRobots(); i++)
	{
		cout << "Place Robot with ID " << i + 1 << "\n";
		getline(cin, sInput);
		// TODO: need to refactor this - OK
		if (!command.ReadPlacementCommand(sInput, &position)) {
			cout << "Input is invalid";
			return 0;
		}
		robot.SetPosition(i,position.GetPosition());
	}
	// TODO: Collision check - OK - NEED TO CHECK IN PLACEMENT COMMAND
	
	// TODO: Add checking for robot id - OK
	// TODO: Add obstacles - OK - need testing
	// TODO: Add support for new direction - OK for testing

	// TODO: Support different shape 
	// TODO: Add Macros
	// TODO: Add 3D dimension
	
	while (true) {
		getline(cin, sInput);
		// Parse Robot ID, if no ID, default to 1
		if (parser.ParseRobotId(sInput, &robot_id)) {
			// TODO: out of bounds robot id
			position = robot.GetRobot(robot_id - 1).GetRobotPosition();
			t_results = command.ReadCommand(sInput, &cmd,&position);
			switch (t_results)
			{
			case FAILED:
				cout << "Error occured ";
				return 0;
				break;
			case SUCCESS:
				if (robot.IsRobotCollided(position)) {
					cout << "ROBOTS COLLIDED";
					return 0;
				}
				// TODO: Test CheckObstacle
				else if(obstacle.CheckObstacle(position)){
					cout << "Obstacle in the area";
				}
				else{
					robot.SetPosition(robot_id - 1, position.GetPosition());
				}
				
				break;
			case STOP:
				robot.SetPosition(robot_id - 1, position.GetPosition());
				cout << robot.GetRobot(robot_id - 1).GetLastPlace();
				return 0;
				break;
			case OTHER:
				if (cmd == OBSTACLE) {
					obstacle.AddObstacle(position);
				}
				break;
			default:
				break;
			}
			
		}
	}
	system("pause");
	return 0;

}



