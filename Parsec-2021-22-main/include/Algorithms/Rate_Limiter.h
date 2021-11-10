#pragma once
#include "time.h"

class Rate_Limiter
{

  private:

    double cap;
    double prev_power;
    time_t prev_time;

  double calc_delta_power();

};
