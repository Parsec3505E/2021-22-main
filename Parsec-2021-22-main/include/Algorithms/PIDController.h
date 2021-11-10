#pragma once
#include "main.h"

class PIDController
{

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

  protected:
    double updatePID();

};
