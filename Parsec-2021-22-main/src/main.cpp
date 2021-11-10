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


	pros::Motor rightBack(11, true);
	pros::Motor rightFront(2, true);
	pros::Motor leftFront(9);
	pros::Motor leftBack(4);

	pros::Motor spinner(20);

	pros::Motor outtake(8);

	pros::Motor arm(19);

	pros::Motor intake(10);

	outtake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	int piston_state = 0;

	int intake_state = 0;

	while (true) {
		bool piston_button = master.get_digital_new_press(DIGITAL_B);
		bool intake_button = master.get_digital_new_press(DIGITAL_UP);
		bool outtake_button = master.get_digital_new_press(DIGITAL_DOWN);
		bool intake_stop = master.get_digital_new_press(DIGITAL_LEFT);

		//Drive Control
		int power = master.get_analog(ANALOG_RIGHT_Y);
		int turn = master.get_analog(ANALOG_LEFT_X);

		int right = power - turn;
		int left = power + turn;

		rightFront.move(right);
		rightBack.move(right);
		leftFront.move(left);
		leftBack.move(left);

		//Arm Control
		if (master.get_digital(DIGITAL_R1)) {
			arm.move_velocity(100);
		}
		else if (master.get_digital(DIGITAL_R2)) {
			arm.move_velocity(-100);
		}
		else {
			arm.move_velocity(0);
		}

		//Piston Control
		if(piston_button && piston_state % 2 == 0) {
			piston.set_value(true);
			piston_state++;
		}

		else if(piston_button && piston_state % 2 != 0) {
			piston.set_value(false);
			piston_state++;
		}

		//Spinner Control
		if (master.get_digital(DIGITAL_L1)) {
			outtake.move_velocity(20);
		}
		else if (master.get_digital(DIGITAL_L2)) {
			outtake.move_velocity(-20);
		}
		else {
			outtake.move_velocity(0);
			std::cout << (outtake.get_brake_mode());

		}

		//Stick/outtake Controller
		if (master.get_digital(DIGITAL_Y)) {
			spinner.move_velocity(100);
		}
		else if (master.get_digital(DIGITAL_A)) {
			spinner.move_velocity(-100);
		}
		else {
			spinner.move_velocity(0);
		}

		if(intake_button) {
			intake.move(127);
		}
		else if(outtake_button) {
			intake.move(-127);
		}
		else if(intake_stop){
			intake.move(0);
		}

		pros::delay(2);

	}

}
