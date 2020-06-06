#include "mbed.h"

#include "bbcar.h"


Ticker servo_ticker;

PwmOut pin8(D8), pin9(D9);
//right wheel->D8 left wheel->D9


BBCar car(pin8, pin9, servo_ticker);


int main() {

    // please contruct you own calibration table with each servo

    double pwm_table0[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120};

    double speed_table0[] = {-17.066, -16.747, -15.790, -12.760, -6.619, 0.000, 5.184, 11.404, 14.993, 16.348};

    double pwm_table1[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120};

    double speed_table1[] = {-16.6, -16.349, -15.312, -11.883, -5.503, 0.000, 6.938, 12.760, 15.551, 16.428};


    // first and fourth argument : length of table

    car.setCalibTable(11, pwm_table0, speed_table0, 11, pwm_table1, speed_table1);


    while (1) {

        car.goStraightCalib(5);

        wait(5);

        car.stop();

        wait(5);

    }

}