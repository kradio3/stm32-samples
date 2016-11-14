/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */
#include <Servo.h>

#define LED PC13
#define servoPin PC14
#define servoMinImp 544 
#define servoMaxImp 2400 
Servo myServo;
void setup()
{
myServo.attach(servoPin, servoMinImp, servoMaxImp);
// устанавливаем пин как вывод управления сервоприводом,
// а также для работы сервопривода непосредственно в диапазоне углов от 0 до 180° задаем мин и макс значения импульсов.
// импульсы с большей или меньшей длиной восприниматься не будут.
// для сервоприводов даже одной партии значения длин импульсов могут отличаться, может быть даже и 584-2440.
// поэкспериментируйте и найдите идеальные длины импульсов конкретно для вашего сервопривода.
}
void loop()
{
  // устанавливаем качалку сервопривода в положение 0°(т.к.импульс равен 544мкс)
  myServo.writeMicroseconds(servoMinImp);
  delay(2000);
  // в данной функции можно задавать длины импульсов непосредственно числами.
  // 90°(т.к.vимпульс равен 1520мкс)
  myServo.writeMicroseconds(1520);
  delay(2000);
  // 180°(т.к. импульс равен 2400мкс)
  myServo.writeMicroseconds(servoMaxImp);
  delay(2000);
}
