#ifndef POSITION_H
#define POSITION_H
#include "Table.h"
#include "toy_robot.h"

namespace ToyRobot {
	class Position : public Table {
	public:
		Position() {};
		virtual ~Position() {};
		type CalculateMove(commands, Movement, Position*);
		void SetPosition(Movement);
		Movement GetPosition();
	private:
		Movement _m;
	};
}

#endif POSITION_H /* POSITION_H */