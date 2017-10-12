/*
 * SimpleTimerAlarmExample.pde
 *
 * Based on usage example for Time + TimeAlarm libraries
 *
 * A timer is called every 15 seconds
 * Another timer is called once only after 10 seconds
 * A third timer is called 10 times.
 *
 */
 
#include <SimpleTimer.h>
 
// There must be one global SimpleTimer object.
// More SimpleTimer objects can be created and run,
// although there is little point in doing so.
SimpleTimer timer;

int reseteador;

boolean flag;
boolean flanco;

const int sensor=7;
 
// function to be called just once
void flagTime() 
{
  flag = false; 

}
  
void setup() 
{
  Serial.begin(9600);
  flag = true;
  flanco = true;
  
 reseteador = timer.setTimeout(5000, flagTime);

}
 
void loop() 
{
  pinMode(sensor,INPUT);
  pinMode(13,OUTPUT);
  digitalWrite(13, LOW);
  // this is where the "polling" occurs
  timer.run();
  if (flag == true)
  { 
    if (flanco == true)
    {
    Serial.println('o');
    delay(1000);
    flanco = false;
    }
    if (flanco == false)
    {
    Serial.println('0');
    delay(1000);
    flanco = true;
    }
  }
  else 
  {
    Serial.println('x');
    delay(1000);
  }
  if (digitalRead(sensor) == HIGH)
  {
    timer.restartTimer(reseteador);
    Serial.println('x0000000');
    flag = true; 
    reseteador = timer.setTimeout(10000, flagTime);
  } 
}