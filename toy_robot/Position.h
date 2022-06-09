#ifndef POSITION_H
#define POSITION_H
#include "Table.h"

namespace ToyRobot {
	class Position : public Table {
	public:
		Position() {};
		virtual ~Position() {};
		type CalculateMove(commands, Coordinates, Position*);
		void SetPosition(Coordinates);
		Coordinates GetPosition();
	private:
		Coordinates _c;
	};
}

#endif POSITION_H /* POSITION_H */