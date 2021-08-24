#include "main.h"

void initialize() {
	pros::lcd::initialize();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
	pros::Motor spinny(2);
	spinny.move(127);

	pros::delay(1000);

	spinny.move(0);
}
