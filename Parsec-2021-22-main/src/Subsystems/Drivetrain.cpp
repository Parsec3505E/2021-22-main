//Parent Drivetrain Class
//Author: Josh Szkiba
//Last Modified: Nov 6, 2021

#include "main.h"
#include "Constants/ElectricalConstants.h"

class Drivetrain {

	private:
		//Motors
		pros::Motor* rightFront;
		pros::Motor* rightBack;
		pros::Motor* leftFront;
		pros::Motor* leftBack;

		//Encoders
		pros::ADIEncoder* rightEncoder;
		pros::ADIEncoder* leftEncoder;
		pros::ADIEncoder* backEncoder;

		protected:
			Drivetrain() {
				//Motor Objects
				rightFront = new pros::Motor(DrivetrainConstants::RIGHT_FRONT);
				rightBack = new pros::Motor(DrivetrainConstants::RIGHT_BACK);
				leftFront = new pros::Motor(DrivetrainConstants::LEFT_FRONT);
				leftBack = new pros::Motor(DrivetrainConstants::LEFT_BACK);

				//Encoder Objects
				rightEncoder = new pros::ADIEncoder(DrivetrainConstants::TOP_RIGHT_ENCODER, DrivetrainConstants::BOTTOM_RIGHT_ENCODER);
				leftEncoder = new pros::ADIEncoder(DrivetrainConstants::TOP_LEFT_ENCODER, DrivetrainConstants::BOTTOM_LEFT_ENCODER);
				backEncoder = new pros::ADIEncoder(DrivetrainConstants::TOP_BACK_ENCODER, DrivetrainConstants::BOTTOM_BACK_ENCODER);

				}

		//Motor/Drive Methods
		void setBrake(){
			rightFront->set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
			rightBack->set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);

			leftFront->set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
			leftBack->set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);

		}

		void setCoast(){
			rightFront->set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
			rightBack->set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

			leftFront->set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
			leftBack->set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

		}

		void updatePower(int left, int right) {
			rightFront->move(right);
			rightBack->move(right);
			leftFront->move(left);
			leftBack->move(left);
		}

		//Encoder Methods
		void resetEncoders() {
			rightEncoder->reset();
			leftEncoder->reset();
			backEncoder->reset();
		}

		double getRightEncoder(){
		return rightEncoder->get_value();
		}

		double getLeftEncoder(){
		return leftEncoder->get_value();
		}

		double getBackEncoder(){
		return backEncoder->get_value();
		}

	protected:
		void stop() {
			updatePower(0, 0);
		}

};
