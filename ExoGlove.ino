#include <Servo.h>

//TODO:
  //Dead Zone so the servos are not constantly updating
  //replacement of potentiometers for force sensors? whatever we are using
  //error detection for each component for easy debugging

//Servo Variables
Servo fingerOne;
Servo fingerTwo;
float fingerOnePosition = 0;
float fingerTwoPosition = 0;
int error = -1;


//Potentiometer Variables
int potentiometerOne = 0;
int potentiometerTwo = 0;
int deadZone = 2;


void setup() {
  Serial.begin(57600);
  //inputs
    // Potentiometers: Pin 19 (A0) and 20 (A1)
  //Outputs
    // Transistors: Pin 11 (D8) and 12 (D9)
    // Servos: Pin 21 (A2) and 22 (A3)
  fingerOne.attach(13);
  fingerTwo.attach(12);
}

void loop() {
  //read potentiometer
  potentiometerOne = analogRead(A1);
  potentiometerTwo = analogRead(A2);
  
  //open transistors


  fingerOnePosition = potentiometerOne / 680.0 * 180.0;
  fingerTwoPosition = potentiometerTwo / 680.0 * 180.0;
  
  Serial.print(fingerOnePosition);
  Serial.print(", ");
  Serial.println(fingerTwoPosition);
  
  //write to servos
  fingerOne.write((int)fingerOnePosition);
  fingerTwo.write((int)fingerTwoPosition);

  //close transistors
  
}
