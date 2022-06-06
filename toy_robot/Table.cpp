#include <iostream>
#include <string>
#include "Table.h"
#include "toy_robot.h"

using namespace std;
using namespace ToyRobot;
namespace ToyRobot {
	/// <summary>
	/// Set Table Dimension and limit
	/// </summary>
	/// <param name="x"> int - x-axis</param>
	/// <param name="y"> int - y-axis </param>
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
	bool Table::SetTableShape(table_shape t_shape){
		
	}

}