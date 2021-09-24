#include "main.h"
#include "Subsystems/Drivetrain.hpp"

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
