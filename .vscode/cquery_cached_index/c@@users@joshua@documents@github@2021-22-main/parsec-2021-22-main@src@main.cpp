#include "main.h"

void initialize() {
	pros::lcd::initialize();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
	pros::Controller master(CONTROLLER_MASTER);

	pros::Motor rightFront(1);
	pros::Motor rightBack(2);
	pros::Motor leftFront(3);
	pros::Motor leftBack(4);

	while (true){
		int power = master.get_analog(ANALOG_RIGHT_Y);
		int turn = master.get_analog(ANALOG_LEFT_X);

		int right = power + turn;
		int left = power - turn;

		rightFront.move(right);
		rightBsck.move(right);
		leftFront.move(left);
		leftBack.move(left);

		pros::delay(2);
	}
}
