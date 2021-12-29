#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int SERVO_1_PIN = 9;
int SERVO_2_PIN = 10;
int SERVO_3_PIN = 11;
int SERVO_4_PIN = 12;

int PHOTO_RESISTOR_PIN = 4;

int BOX_PICKED_UP_PIN = 5;

void setup() {
    pinMode(BOX_PICKED_UP_PIN, OUTPUT);
    pinMode(OPEN_BOX_PIN, INPUT);
    pinMode(PHOTO_RESISTOR_PIN, INPUT);

    servo1.attach(SERVO_1_PIN);
    servo2.attach(SERVO_2_PIN);
    servo3.attach(SERVO_3_PIN);
    servo4.attach(SERVO_4_PIN);

    servo1.write(0);
    delay(1000);
    servo2.write(0);
    delay(1000);
    servo3.write(0);
    delay(1000);
    servo4.write(0);
    delay(1000);

    digitalWrite(BOX_PICKED_UP_PIN, LOW);
}

void loop() {
    if(analogRead(PHOTO_RESISTOR_PIN) > 500) {
        digitalWrite(BOX_PICKED_UP_PIN, HIGH);
    }
    else {
        digitalWrite(BOX_PICKED_UP_PIN, LOW);
    }

    if(digitalRead(OPEN_BOX_PIN)) {
        serial.println("OPENING THE BOX");
    }
}

void openBox() {
    servo1.write(90);
    delay(1000);
    servo2.write(90);
    delay(1000);
    servo3.write(90);
    delay(1000);
    servo4.write(90);
    delay(1000);
}