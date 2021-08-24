#include "main.h"

void initialize() {
	pros::lcd::initialize();
	pros:Motor spinny(3);
}

void disabled() {}

void competition_initialize() {}

void autonomous() {

}

void opcontrol() {
	spinny.move();


}
