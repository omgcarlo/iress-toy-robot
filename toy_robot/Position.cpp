#include <iostream>
#include <string>
#include "Position.h"
#include "toy_robot.h"
#include "Parser.h"

using namespace std;
using namespace ToyRobot;
namespace ToyRobot {
	Movement Position::GetPosition() {
		return this->_m;
	}

	type Position::CalculateMove(commands c, Movement m, Position* p) {
		switch (c)
		{
		case ToyRobot::PLACE:
			p->SetPosition(m);
			break;
		case ToyRobot::MOVE:
			if (m.st_place == ::NORTH) {
				if (m.st_y < p->GetTableDimensionX()) {
					m.st_y++;
				}
				else {
					return ::OVER;
				}
			}
			else if (m.st_place == ::SOUTH) {
				if (m.st_y > 0) {
					m.st_y--;
				}
				else {
					return ::OVER;
				}
			}
			else if (m.st_place == ::EAST) {
				if (m.st_x < p->GetTableDimensionX()) {
					m.st_x++;
				}
				else {
					return ::OVER;
				}
			}
			else if (m.st_place == ::WEST) {
				if (m.st_x > 0) {
					m.st_x--;
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
			if (m.st_place == ::NORTH) {
				m.st_place = ::WEST;
			}
			else if (m.st_place == ::SOUTH) {
				m.st_place = ::EAST;
			}
			else if (m.st_place == ::EAST) {
				m.st_place = ::NORTH;
			}
			else if (m.st_place == ::WEST) {
				m.st_place = ::SOUTH;
			}
			else {
				return ::FAILED;
			}
			break;
		case ToyRobot::RIGHT:
			if (m.st_place == ::NORTH) {
				m.st_place = ::EAST;
			}
			else if (m.st_place == ::SOUTH) {
				m.st_place = ::WEST;
			}
			else if (m.st_place == ::EAST) {
				m.st_place = ::SOUTH;
			}
			else if (m.st_place == ::WEST) {
				m.st_place = ::NORTH;
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
		p->SetPosition(m);

		return SUCCESS;
	}
	void Position::SetPosition(Movement m) {
		this->_m.st_place = m.st_place;
		this->_m.st_x = m.st_x;
		this->_m.st_y = m.st_y;
	}
}