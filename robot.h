#include <Stepper.h>
#ifndef ROBOT_H
#define ROBOT_H 
struct Motor_options{
    int StepsPerRevolution;
    int StepperSpeed;
};
struct Motor_pins{
    int IN1;
    int IN2;
    int IN3;
    int IN4;
};
class Robot{
    public:
        Robot(Motor_pins, Motor_pins, Motor_options, Motor_options);
        Robot(){}
        void PlayRight(double);
        void PlayLeft(double);
    private:
        Stepper dx_motor = Stepper(0,0,0,0,0);
        Stepper sx_motor = Stepper(0,0,0,0,0);
        Motor_options odx;
        Motor_options osx;
};
#endif