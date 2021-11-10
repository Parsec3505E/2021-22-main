#pragma once
#include "main.h"

class Drivetrain
{

  private:
    pros::Motor* rightFront;
    pros::Motor* rightBack;
    pros::Motor* leftFront;
    pros::Motor* leftBack;

  void updatePower();

  protected:
    void stop();

};
