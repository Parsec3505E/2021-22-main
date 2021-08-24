#include "main.h"

void initialize() {
	pros::lcd::initialize();

}

void disabled() {}

void competition_initialize() {}

void autonomous() {

}

void opcontrol() {
	pros::Motor spinny(1);
	spinny.move(127);


}
