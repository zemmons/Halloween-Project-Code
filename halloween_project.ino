#include <Servo.h>
#include <Wire.h>

Servo motor; // declares servo motor
int trig = 6;
int echo = 7; // attaches range sensor

void setup()
{
  Serial.begin(9600); // starts serial monitor
  motor.attach(9);// attaches servo
  pinMode(8, OUTPUT); // sets led as output
}

void loop(){
// establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration, inches, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echo, INPUT);
  duration = pulseIn(echo, HIGH); // sends pulse to range sensor

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);


if (inches < 15)
  {
for (int i=0;i <179; i=i+20)
{
  motor.write(i); //turns motor to set location
  delay(50);
}
    {
      digitalWrite(13,HIGH);
      delay(200);
      digitalWrite(13,LOW);
      delay(200);
      digitalWrite(13,HIGH);
      delay(200);
      digitalWrite(13,LOW);
      delay(200); // all of above flashes led 
    }
  for (int i=180; i>5; i=i-5)
  {
    motor.write(i);
    delay(10);
    digitalWrite(13,HIGH);
      delay(100);
      digitalWrite(13,LOW);
      delay(100);// all of above flashes LED
}
  delay(2000);
}
  


}
long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second). This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PI...
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;

}
