#ifndef TABLE_H
#define TABLE_H

namespace ToyRobot {
	class Table {
	public:
		Table() {
			_dimensionX = 5;
			_dimensionY = 5;
			_dimensionZ = 4;
		};
		virtual ~Table() {};
		void SetTableDimension(int, int);
		int GetTableDimensionX();
		int GetTableDimensionY();
		int GetTableDimensionZ();
		bool SetTableShape(table_shape);
	private:
		int _dimensionX;
		int _dimensionY;
		int _dimensionZ;
		table_shape _shape;
	};
}

#endif TABLE_H /* TABLE_H */