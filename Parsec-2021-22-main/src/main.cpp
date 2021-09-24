#include "main.h"

void initialize() {
	pros::lcd::initialize();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
	pros::Controller master(CONTROLLER_MASTER);

	pros::ADIDigitalOut piston('A');

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
		rightBack.move(right);
		leftFront.move(left);
		leftBack.move(left);

		if (master.get_digital_new_press(DIGITAL_A)) {
			piston.set_value(true);
		}
		else {
			piston.set_value(false);
		}

		pros::delay(2);
	}
}
