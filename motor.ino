#include "motors.h"
#include "sched.h"
Motor m(2,3,4,5);
LittleScheduler l;
int Steps = 0;
boolean direction = true;// gre
int d = 0;
int steps_left=4095;
void setup() {
  l.add_task(step, 2, 0, &steps_left);
  Serial.begin(9600);
}
void reverse_direction(){
  direction = !direction;
  steps_left = 4*4095;
}
void step(void *a){
  if(steps_left > 0){
    int val = direction ? forward : backward;
    m.Step(val);
    steps_left--;
  }else{
    reverse_direction();
  }
}
void loop() {
  unsigned int time = millis();
  l.run_sched(time);
}
