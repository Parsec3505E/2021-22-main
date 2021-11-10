//Electrical Constants and Port Number Class
//Author: Josh Szkiba
//Last Modified: Oct 27, 2021

class DrivetrainConstants final {

  public:
    //Motors
    static const int RIGHT_FRONT = 1;
    static const int RIGHT_BACK = 2;
    static const int LEFT_FRONT = 3;
    static const int LEFT_BACK = 4;

    //Sensors
    static const char TOP_RIGHT_ENCODER = 'A';
    static const char BOTTOM_RIGHT_ENCODER = 'B';
    static const char TOP_LEFT_ENCODER = 'C';
    static const char BOTTOM_LEFT_ENCODER = 'D';
    static const char TOP_BACK_ENCODER = 'E';
    static const char BOTTOM_BACK_ENCODER = 'F';

};
