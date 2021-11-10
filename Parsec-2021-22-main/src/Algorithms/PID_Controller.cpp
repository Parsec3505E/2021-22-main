//PID Controller for error correction
//Author: Josh Szkiba
//Last Modified: Nov 1, 2021

#include "main.h"
#include "math.h"

class PIDController {

  private:
    pros::ADIDigitalIn* input_sensor;
    double target;
    double kP;
    double kI;
    double kD;
    double error;
    double prev_error;
    double integral;
    double integral_wind_up;
    double derivative;

  PIDController(double kP, double kI, double kD){
    this->kP = kP;
    this->kI = kI;
    this->kD = kD;

    this->prev_error = prev_error;

    this->integral = integral;

    //Integral error accumulation
    this->integral_wind_up = integral_wind_up;
    integral_wind_up = 10;

    this->derivative = derivative;

    this->target = target;
  }

  protected:
    double updatePID(double input, double target) {

      error = target - input;

      if(abs(error) < integral_wind_up) {
        integral += error;
      }
      else {
        integral = 0;
      }

      derivative = error - prev_error;

      pros::delay(1);

      double output = (kP * error) + (kI * integral) + (kD * derivative);

      return output;



    }

};
