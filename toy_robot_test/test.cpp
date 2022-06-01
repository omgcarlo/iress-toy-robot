#include "pch.h"
#include "toy_robot.h"

using namespace ToyRobot;
TEST(TestMain, ExampleTest1) {
	Robot r;
	Position p;
	string user_input = "PLACE 0,0,NORTH";
	r.ReadPlacementCommand(user_input, &p);
	r.SetPosition(p.GetPosition());
	user_input = "MOVE";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());
	user_input = "REPORT";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	EXPECT_EQ(r.GetLastPlace(), "0,1,NORTH");
}
TEST(TestMain, ExampleTest2) {
	Robot r;
	Position p;
	string user_input = "PLACE 0,0,NORTH";

	r.ReadPlacementCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "LEFT";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "REPORT";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	EXPECT_EQ(r.GetLastPlace(), "0,0,WEST");
}
TEST(TestMain, ExampleTest3) {
	Robot r;
	Position p;
	string user_input = "PLACE 0,0,NORTH";

	r.ReadPlacementCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "LEFT";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "REPORT";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	EXPECT_EQ(r.GetLastPlace(), "0,0,WEST");
}

TEST(TestMain, SimpleTest1) {
	Robot r;
	Position p;
	string user_input = "PLACE 1,2,EAST";

	r.ReadPlacementCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "MOVE";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "MOVE";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "LEFT";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "MOVE";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "REPORT";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	EXPECT_EQ(r.GetLastPlace(), "3,3,NORTH");
}
TEST(TestMain, SimpleTest2) {
	Robot r;
	Position p;
	string user_input = "PLACE 1,1,EAST";

	r.ReadPlacementCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "MOVE";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "RIGHT";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "MOVE";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "REPORT";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	EXPECT_EQ(r.GetLastPlace(), "2,0,SOUTH");
}
TEST(TestMain, SimpleTest3) {
	Robot r;
	Position p;
	string user_input = "PLACE 1,1,EAST";

	r.ReadPlacementCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "RIGHT";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "RIGHT";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "MOVE";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "REPORT";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	EXPECT_EQ(r.GetLastPlace(), "0,1,WEST");
}
TEST(TestMain, SimpleTest4) {
	Robot r;
	Position p;
	string user_input = "PLACE 1,1,EAST";

	r.ReadPlacementCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "RIGHT";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "MOVE";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "PLACE 1,1,EAST";
	r.ReadPlacementCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "REPORT";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	EXPECT_EQ(r.GetLastPlace(), "1,1,EAST");
}
TEST(TestMain, OutOfTableTest1) {
	Robot r;
	Position p;
	string user_input = "PLACE 1,1,NORTH";

	r.ReadPlacementCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "MOVE";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "LEFT";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "MOVE";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "MOVE";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "MOVE";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "REPORT";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	EXPECT_EQ(r.GetLastPlace(), "0,2,WEST");
}
TEST(TestMain, OutOfTableTest2) {
	// Out of bounce of the table in y-axis
	Robot r;
	Position p;
	string user_input = "PLACE 1,1,NORTH";

	r.ReadPlacementCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "MOVE";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "MOVE";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "MOVE";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "MOVE";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "MOVE";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "REPORT";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	EXPECT_EQ(r.GetLastPlace(), "1,5,NORTH");
}
TEST(TestMain, OutOfTableTest3) {
	// Out of bounce of the table in x-axis
	Robot r;
	Position p;
	string user_input = "PLACE 1,1,EAST";

	r.ReadPlacementCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "MOVE";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "MOVE";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "MOVE";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "MOVE";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "MOVE";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	user_input = "REPORT";
	r.ReadCommand(user_input, &p);
	r.SetPosition(p.GetPosition());

	EXPECT_EQ(r.GetLastPlace(), "5,1,EAST");
}
TEST(TableClass, SetAndGetXY) {
	// Table t 
	Table t;

	// default value
	// x = 5; y = 5
	EXPECT_EQ(t.GetTableDimensionX(), 5);
	EXPECT_EQ(t.GetTableDimensionY(), 5);

	// set x and y
	t.SetTableDimension(10,12);
	EXPECT_EQ(t.GetTableDimensionX(), 10);
	EXPECT_EQ(t.GetTableDimensionY(), 12);
	EXPECT_TRUE(true);
}
TEST(PositionClass, SetAndGetPosition) {
	// Position
	Position p;
	Movement m;
	Movement m1;

	m.st_place = NORTH;
	m.st_x = 2;
	m.st_y = 0;

	m1.st_place = NORTH;
	m1.st_x = 2;
	m1.st_y = 0;

	p.SetPosition(m);
	EXPECT_EQ(p.GetPosition().st_place, m1.st_place);
	EXPECT_EQ(p.GetPosition().st_x, m1.st_x);
	EXPECT_EQ(p.GetPosition().st_y, m1.st_y);

	EXPECT_TRUE(true);
}