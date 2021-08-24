#include "main.h"

#define RIGHT_FRONT 1
#define RIGHT_BACK 2
#define LEFT_FRONT 3
#define LEFT_BACK 4

class Drivetrain {

	private:
		pros::Motor* rightFront;
		pros::Motor* rightBack;
		pros::Motor* leftFront;
		pros::Motor* leftBack;

		Drivetrain() {
			rightFront = new pros::Motor(RIGHT_FRONT);
			rightBack = new pros::Motor(RIGHT_BACK);
			leftFront = new pros::Motor(LEFT_FRONT);
			leftBack = new pros::Motor(LEFT_BACK);

		}

		void updatePower(int left, int right) {
			rightFront->move(right);
			rightBack->move(right);
			leftFront->move(left);
			leftBack->move(left);
		}

	protected:
		void stop() {
			updatePower(0, 0);
		}
};

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
