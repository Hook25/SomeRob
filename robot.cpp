#include "robot.h"

Robot::Robot(Motor_pins dx, Motor_pins sx, Motor_options podx, Motor_options posx){
    dx_motor = Stepper(odx.StepsPerRevolution, dx.IN1, dx.IN2, dx.IN3, dx.IN4);
    sx_motor = Stepper(odx.StepsPerRevolution, sx.IN1, sx.IN2, sx.IN3, sx.IN4);
    dx_motor.setSpeed(4);
    sx_motor.setSpeed(4);
    odx = podx;
    osx = posx;
}
void Robot::PlayRight(double factor){
    dx_motor.step(odx.StepsPerRevolution * factor);
}
void Robot::PlayLeft(double factor){
    sx_motor.step(osx.StepsPerRevolution * factor);
}
