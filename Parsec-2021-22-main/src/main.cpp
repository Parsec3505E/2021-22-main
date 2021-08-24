#include "main.h"

class drivetrain {
	
}

void initialize() {
	pros::lcd::initialize();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
	pros::Controller master (pros::E_CONTROLLER_MASTER);

	pros::Motor spinny(2);

	while (true){
		spinny.move(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
	}
}
