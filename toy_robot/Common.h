
#ifndef COMMON_H
#define COMMON_H

using namespace std;
namespace ToyRobot {
	enum commands {
		PLACE,
		MOVE,
		LEFT,
		RIGHT,
		REPORT,
		OBSTACLE,
		ROBOT
	};
	enum placement {
		NORTH,
		SOUTH,
		EAST,
		WEST,
		NORTHEAST,
		NORTHWEST,
		SOUTHEAST,
		SOUTHWEST
	};
	enum type {
		FAILED,
		SUCCESS,
		STOP,
		OVER,
		COLLIDED,
		OTHER
	};
	// TODO: DEFINE DIMENSIONS
	enum table_shape {
		SQUARE,
		RECTANGLE,
		CIRCLE,
		TRIANGLE,
	};
	struct Coordinates {
		//int st_robot_id;
		int st_x;
		int st_y;
		int st_z;
		placement st_place;
	};
}

#endif COMMON_H /* COMMON_H */