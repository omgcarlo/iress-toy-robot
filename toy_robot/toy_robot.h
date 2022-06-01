#ifndef TOY_ROBOT_H
#define TOY_ROBOT_H

#include <iostream>
#include <string>

using namespace std;
namespace ToyRobot {
	enum commands {
		PLACE,
		MOVE,
		LEFT,
		RIGHT,
		REPORT,
		OBSTACLE
	};
	enum placement {
		NORTH,
		SOUTH,
		EAST,
		WEST,
	};
	enum type{
		FAILED = 0,
		SUCCESS = 1,
		STOP = 2,
		OVER = 3,
	};
	struct Movement {
		int st_x;
		int st_y;
		placement st_place;
	};
}
#endif /* TOY_ROBOT_H */