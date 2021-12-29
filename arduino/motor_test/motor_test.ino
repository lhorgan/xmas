#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int DR7C = 0;
bool OPENED_BOX = false;

void setup() {
  Serial.begin(9600); // open the serial port at 9600 bps: 
  
  servo1.attach(9); //attaches the servo on pin 9
  servo2.attach(10);
  servo3.attach(11);
  servo4.attach(12);

  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  servo4.write(0);

//  servo1.write(0);
//  delay(1000);
//  servo2.write(0);
//  delay(1000);
//  servo3.write(0);
//  delay(1000);
//  servo4.write(0);
//  delay(1000);

  pinMode(8, OUTPUT); // Tell RPI if the box has been picked up
  pinMode(A0, INPUT); // Reading from the photoresistor
  pinMode(7, INPUT);
  digitalWrite(8, LOW);
}

void loop() {
  Serial.print(analogRead(A0));
  Serial.print("\t");
  Serial.print(digitalRead(7));
  Serial.println();
  delay(1000);
  if(analogRead(A0) > 100) {
    digitalWrite(8, HIGH);
  }
  else {
    digitalWrite(8, LOW);
  }

  if(digitalRead(7)) {
    DR7C++;
    if(DR7C >= 3 && !OPENED_BOX) {
      OPENED_BOX = true;
      servo1.write(65); //rotate counterclockwise at slow speed
      delay(1000);
      servo2.write(65);
      delay(1000);
      servo3.write(65);
      delay(1000);
      servo4.write(65);
      delay(1000);
    }
  }
}
