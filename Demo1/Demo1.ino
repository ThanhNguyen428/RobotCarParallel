/*
 * @Author: ELEGOO
 * @Date: 2019-10-22 11:59:09
 * @LastEditTime: 2020-06-28 14:55:26
 * @LastEditors: Changhua
 * @Description: conqueror robot tank
 * @FilePath: 
 */
#include <avr/wdt.h>
#include <stdio.h>
#include "DeviceDriverSet_xxx0.h"
#include "DeviceDriverSet_xxx1.h"
#include "ApplicationFunctionSet_xxx0.cpp"

DeviceDriverSet_Motor AppMotor;
Application_xxx Application_SmartRobotCarxxx0;


DeviceDriverSet_ULTRASONIC myUltrasonic;

void setup() {
  AppMotor.DeviceDriverSet_Motor_Init();
  Serial.begin(9600);
  myUltrasonic.DeviceDriverSet_ULTRASONIC_Init();
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  if (((unsigned int)pulseIn(ECHO_PIN, HIGH) / 58) < 8) {
    parkAlongTheRight();
    exit(0);
  } else {
    ApplicationFunctionSet_SmartRobotCarMotionControl(Forward /*direction*/, 100 /*speed*/);
    delay(1000);
    ApplicationFunctionSet_SmartRobotCarMotionControl(stop_it /*direction*/, 100 /*speed*/);
  }
  myUltrasonic.DeviceDriverSet_ULTRASONIC_Test();

}


void parkAlongTheRight() {
  ApplicationFunctionSet_SmartRobotCarMotionControl(Left /*direction*/, 100 /*speed*/);
  delay(1000);
  ApplicationFunctionSet_SmartRobotCarMotionControl(stop_it /*direction*/, 90 /*speed*/);
  

}
