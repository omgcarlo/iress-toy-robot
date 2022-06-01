#include <iostream>
#include <string>
#include "Table.h"
#include "toy_robot.h"

using namespace std;
using namespace ToyRobot;
namespace ToyRobot {
	void Table::SetTableDimension(int x, int y) {
		this->_dimensionX = x;
		this->_dimensionY = y;
	}
	int Table::GetTableDimensionX() {
		return _dimensionX;
	}
	int Table::GetTableDimensionY() {
		return _dimensionY;
	}

}