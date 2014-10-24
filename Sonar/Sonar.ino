#include <Servo.h>
#include <US020.h>
/*
US-020 sensor on top of servo 
scans distance for different angles
*/
int usTrigPin = 2;
int usEchoPin = 1;
int servoPin = 9;

Servo servo;
US020 sonar(usEchoPin, usTrigPin);


int angles[] = {50, 90, 130, 90};
int ang = 0;

void setup() { 
  servo.attach(servoPin);
  Serial.begin(9600);
}

void loop() 
{ 
  ang++;
  if(ang >= sizeof(angles)/2) {
    ang=0;
  }
    
  servo.write(angles[ang]);
  Serial.print("Angle: ");
  Serial.println(angles[ang]);
  delay(120); //wait to rotate servo
  
  Serial.print("Distance: ");
  double avarage = 0; 
  int ping_num = 5;
  for(int i=0; i<ping_num; i++){
    unsigned long us = sonar.ping();
    avarage += us/ping_num;
    Serial.print(us);
    Serial.print(", ");
  }
  Serial.println(avarage);
} 
