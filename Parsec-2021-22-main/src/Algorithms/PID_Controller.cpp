#include "main.h"

class PIDController {

  private:
    pros::ADIDigitalIn input_sensor;
    double target;
    double kP;
    double kI;
    double kD;
    double error;
    double prev_error;
    double integral;
    double derivative;

  PIDController(pros::ADIDigitalIn input_sensor, double kP, double kI, double kD){
    this->input_sensor = input_sensor;
    this->kP = kP;
    this->kI = kI;
    this->kD = kD;
  }

  void updatePID(PIDController &controller, double target) {

  }

};
