#include "main.h"

class PID {

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

  PID(pros::ADIDigitalIn input_sensor, double kP, double kI, double kD){
    this->input_sensor = input_sensor;
    this->kP = kP;
    this->kI = kI;
    this->kD = kD;
  }


};
