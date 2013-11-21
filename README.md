Lab6
====

Moving Robot
===
This file contains the code to move a robot. The robot makes a small left turn followed by a small left turn. It then moves forward and then backwards.
The last two movements are a large right turn and a large left turn. Lastly, there is a pretty long delay before the actions begin again. 

Extra Files
===
This program utilizes MoveBot.c and MoveBot.h

Functions
===
initMotors() - initializes the motors;
----
MoveForward() - moves forward;
MoveBack() - moves backward;
TurnLeft() - turns left;
TurnRight() - turns right;
StopBot() - stops the robot;
Delay() - does an action for 1000000 cycles;
ShortDelay() - half of Delay();
