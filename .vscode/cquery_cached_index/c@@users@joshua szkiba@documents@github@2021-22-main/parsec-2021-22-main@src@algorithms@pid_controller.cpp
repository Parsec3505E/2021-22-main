#include "main.h"

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
    double derivative;

  PIDController(int port, double kP, double kI, double kD){
    this->input_sensor = new pros::ADIDigitalIn(port);
    this->kP = kP;
    this->kI = kI;
    this->kD = kD;

    this->prev_error = prev_error;

    this->integral = integral;

    this->derivative = derivative;

    this->target = target;
  }

  protected:
    double updatePID(double target) {

      error = target - input_sensor->get_value();

      integral += error;

      derivative = error - prev_error;

      pros::delay(1);

      double output = (kP * error) + (kI * integral) + (kD * derivative);

      return output;



    }

};
