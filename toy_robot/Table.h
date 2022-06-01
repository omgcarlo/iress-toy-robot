#ifndef TABLE_H
#define TABLE_H

namespace ToyRobot {
	class Table {
	public:
		Table() {
			_dimensionX = 5;
			_dimensionY = 5;
		};
		virtual ~Table() {};
		void SetTableDimension(int, int);
		int GetTableDimensionX();
		int GetTableDimensionY();

	private:
		int _dimensionX;
		int _dimensionY;
	};
}

#endif TABLE_H /* TABLE_H */