#include "main.h"
#include <cmath>
#include <ctime>

class Rate_Limiter {

  private:

    double cap;
    double prev_power;
    time_t prev_time;
    time_t curr_time;


  Rate_Limiter(double cap) {
    this->cap = cap;

  }

  double calc_delta_power(double req_power){

    double new_power;

    double delta_power = req_power - prev_power;
    double delta_time = curr_time - prev_time;

    double rate = delta_power / delta_time;

    if (rate > cap) {
      rate = cap;
    }
    else if(rate < cap) {
      rate = abs(cap);
    }
    else {
       rate = rate;
    }

    new_power = rate * delta_time;

    curr_time = prev_time;
    req_power = prev_power;

    return new_power;
  }
};
