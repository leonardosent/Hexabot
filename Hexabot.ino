#include <Servo.h>

////////////////////////////////////
// Defining The Servos And Sensers//
////////////////////////////////////

Servo servo1;
Servo servo2;
Servo servo3;
char sensor1;
char sensor2;
char sensor3;

// Setup the servos
void setup(){
    Serial.begin(9600); 
    servo1.attach(3);
    servo2.attach(5);
    servo3.attach(6);
}

// Run the loop
void loop(){
    sensor1 = readRange(0);
    sensor2 = readRange(1);
    sensor3 = readRange(2);
    printRange("Sensor1: ", sensor1);
    printRange("Sensor2: ", sensor2);
    printRange("Sensor3: ", sensor3);
  
    if ((sensor1 > 1) && (sensor1 < 10)) {
      Foward();
    }

    if ((sensor2 > 1) && (sensor2 < 10)) {
      BackRight();
    }

    if ((sensor3 > 1) && (sensor3 < 10)) {
      BackLeft();
    }
}

// Reads sensor value
float readRange(byte pin) {
    int tmp = analogRead(pin);
    
    if (tmp < 3) {
        return -1;
    }
    
    return (6787.0 / ((float)tmp - 3.0)) - 4.0;
}

// Moves robot forward
void Foward() {
    servo1.write(94);
    servo2.write(0);
    servo3.write(180);
}

// Move robot back left
void BackLeft() {
    servo1.write(180);
    servo2.write(94);
    servo3.write(0);
  }

// Move robot back right
void BackRight() {
    servo1.write(0);
    servo2.write(180);
    servo3.write(94);
}

// Prints sensor value
void printRange(String sensorName, char sensor) {

    char a = sensor / 10;
    char b = sensor % 10;
    int val = a * 10 + b;
 
    if (val < 10 && val > 0) {
        Serial.print(sensorName);
        Serial.print(a, DEC);
        Serial.print(b, DEC);
        Serial.println("cm");
    }
}
