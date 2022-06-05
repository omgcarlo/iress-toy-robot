#include <iostream>
#include <string>
#include "Common.h"
#include "Position.h"
#include "Parser.h"

using namespace std;
using namespace ToyRobot;
namespace ToyRobot {
	Coordinates Position::GetPosition() {
		return this->_c;
	}
	type Position::CalculateMove(commands c, Coordinates coordinates, Position* p) {
		switch (c)
		{
		case ToyRobot::PLACE:
			p->SetPosition(coordinates);
			break;
		case ToyRobot::MOVE:
			if (coordinates.st_place == ::NORTH) {
				if (coordinates.st_y < p->GetTableDimensionX()) {
					coordinates.st_y++;
				}
				else {
					return ::OVER;
				}
			}
			else if (coordinates.st_place == ::SOUTH) {
				if (coordinates.st_y > 0) {
					coordinates.st_y--;
				}
				else {
					return ::OVER;
				}
			}
			else if (coordinates.st_place == ::EAST) {
				if (coordinates.st_x < p->GetTableDimensionX()) {
					coordinates.st_x++;
				}
				else {
					return ::OVER;
				}
			}
			else if (coordinates.st_place == ::WEST) {
				if (coordinates.st_x > 0) {
					coordinates.st_x--;
				}
				else {
					return ::OVER;
				}
			}
			else {
				return ::FAILED;
			}

			break;
		case ToyRobot::LEFT:
			if (coordinates.st_place == ::NORTH) {
				coordinates.st_place = ::WEST;
			}
			else if (coordinates.st_place == ::SOUTH) {
				coordinates.st_place = ::EAST;
			}
			else if (coordinates.st_place == ::EAST) {
				coordinates.st_place = ::NORTH;
			}
			else if (coordinates.st_place == ::WEST) {
				coordinates.st_place = ::SOUTH;
			}
			else {
				return ::FAILED;
			}
			break;
		case ToyRobot::RIGHT:
			if (coordinates.st_place == ::NORTH) {
				coordinates.st_place = ::EAST;
			}
			else if (coordinates.st_place == ::SOUTH) {
				coordinates.st_place = ::WEST;
			}
			else if (coordinates.st_place == ::EAST) {
				coordinates.st_place = ::SOUTH;
			}
			else if (coordinates.st_place == ::WEST) {
				coordinates.st_place = ::NORTH;
			}
			else {
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
		p->SetPosition(coordinates);

		return SUCCESS;
	}
	void Position::SetPosition(Coordinates coordinates) {
		this->_c.st_place = coordinates.st_place;
		this->_c.st_x = coordinates.st_x;
		this->_c.st_y = coordinates.st_y;
	}
}