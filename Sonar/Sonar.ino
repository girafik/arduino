#include <NewPing.h>
#include <Servo.h> 
/*
US sensor on top of servo 
scans distance for different angles
*/
int sonar_triger = 2;
int sonar_echo = 1;
int sonar_max = 200;

int servo_pin = 9;

Servo servo;
NewPing sonar(sonar_triger, sonar_echo, sonar_max);


int angles[] = {50, 90, 130, 90};
int ang = 0;

void setup() { 
  servo.attach(servo_pin);
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
    unsigned int us = sonar.ping();
    avarage += us/ping_num;
    Serial.print(sonar.convert_cm(us));
    Serial.print(", ");
  }
  Serial.println(sonar.convert_cm(avarage));                         

} 
