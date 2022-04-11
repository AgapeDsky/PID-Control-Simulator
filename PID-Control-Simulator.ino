#include "PIDController.h"
#include <math.h>

float computePeriod = 0.02;

float result = 0.;
float target = 1.0;
float pidResult = 0.0;
float prevResult = 0.0;
float prevResult2 = 0.0;
float prevResult3 = 0.0;

PIDController motor = PIDController();

void setup() {
  Serial.begin(9600);
  // mode, Kp, Ti, Td, ff, fc, cp, is_active
  motor.init(2, 5, 1, 1, 1, 1, computePeriod, true);
  motor.setActive(true);
}

void loop() {
  // Kendali Kecepatan
//  pidResult = motor.compute_action(target, result, 1);
//  result = 0.18/(0.2+computePeriod)*(pidResult*computePeriod+0.2*prevResult);
//  Serial.println(result);
//  delay(20);
//  prevResult = result;

  // Kendali Posisi
  pidResult = motor.compute_action(target,result, 1);
  result = (pidResult-0.1/computePeriod/computePeriod*(prevResult2-2*prevResult)+0.7*prevResult/computePeriod)/(0.1/computePeriod/computePeriod+0.7/computePeriod+1);
  Serial.println(result);
  delay(20);
  prevResult2 = prevResult;
  prevResult = result;
}
