# toy-robot-challenge
C++ Technical Challenge
##### Table of Contents  
* [Description and requirements](#description)  
* [Constraints](#constraints)  
* [Example](#example)  
<a name="description"/>

## Description and Requirements:
The application is a simulation of a toy robot moving on a square table top, of dimensions 5 units x 5 units. 

There are no other obstructions on the table surface. 

The robot is free to roam around the surface of the table, but must be prevented from falling to destruction. 

Any movement that would result in the robot falling from the table must be prevented, however further valid movement commands must still be allowed. 

Create a console application that can read in commands of the following form - 

`PLACE X,Y,F`

`MOVE`

`LEFT`

`RIGHT` 

`REPORT`

`PLACE` will put the toy robot on the table in position X,Y and facing NORTH, SOUTH, EAST or WEST. 

The origin (0,0) can be considered to be the SOUTH WEST most corner. 

It is required that the first command to the robot is a PLACE command, after that, any sequence of commands may be issued, in any order, including another PLACE command. 
The application should discard all commands in the sequence until a valid PLACE command has been executed.


`MOVE` will move the toy robot one unit forward in the direction it is currently facing.

`LEFT` and `RIGHT` will rotate the robot 90 degrees in the specified direction without changing the position of the robot. 

`REPORT` will announce the X,Y and F of the robot. 

This can be in any form, but standard output is sufficient. 

A robot that is not on the table can choose to ignore the MOVE, LEFT, RIGHT and REPORT commands. 

Input can be from a file, or from standard input, as the developer chooses. 
Provide test data to exercise the application. 
It is **not required** to provide any graphical output showing the movement of the toy robot. 
The application should handle error states appropriately and be robust to user input.

<a name="constraints"/>

## Constraints: 
The toy robot must not fall off the table during movement. This also includes the initial placement of the toy robot. Any move that would cause the robot to fall must be ignored.

### Visualization
To visualize the robot movement and starting point please see reference below:

**PLACE at 0,0,NORTH**

As you could see we started at the bottom left corner of the table to mark the 0,0(x,y) coordinate

![0_place](https://user-images.githubusercontent.com/13585907/171349681-9fbae0f6-2255-47ea-be05-2aa77e53e09c.PNG)

**MOVE**

When MOVE command is entered, we move the robot(bug) to 1 coordinate where the robot(bug) is facing

![1_move](https://user-images.githubusercontent.com/13585907/171349691-ab8f1205-0914-4c2d-8701-5db7869ba764.PNG)

**LEFT/RIGHT**

When LEFT command is entered, we move turn the robot(bug) to the left/right.

![2_left](https://user-images.githubusercontent.com/13585907/171349723-3d81b11e-2df5-4eff-a636-25142e8d2123.PNG)

**REPORT**

When REPORT command is entered, we get the position of the robot(bug)

![3_move_report](https://user-images.githubusercontent.com/13585907/171349731-23da5053-7a16-465f-a975-61aa9cfda006.PNG)

### Limitations

The following features are yet to be implemented:

* Make the table size configurable
* Add 2 (or n) robots on the table
* Add more directions
* Add obstacles
* Support a different shaped table
* Macros
* Add a 3rd dimension

<a name="example"/>

## Example Input and Output: 
### example 1
Input
<pre>
PLACE 0,0,NORTH 
MOVE 
REPORT 
</pre>
Output: 
<pre>
0,1,NORTH 
</pre>
### example #2
Input
<pre>
PLACE 0,0,NORTH 
LEFT 
REPORT 
</pre>
Output: 
<pre>
0,0,WEST 
</pre>
### example #3
Input
<pre>
PLACE 1,2,EAST 
MOVE 
MOVE 
LEFT 
MOVE 
REPORT 
</pre>
Output: 
<pre>
3,3,NORTH
