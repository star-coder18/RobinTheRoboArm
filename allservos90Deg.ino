#include <SoftwareSerial.h> //this is for serial communication
#include <Servo.h>

Servo grip; //6
Servo wrist; //5
Servo lowerwrist; //4
Servo elbow; //3
Servo shoulderLeft; //2 
Servo shoulderRight; //1

SoftwareSerial Bluetooth(2, 4); //rx tx

int gripPos, wristPos, lowerwristPos, elbowPos, shoulderLeftPos, shoulderRightPos; // current position
int gripPrevPos, wristPrevPos, lowerwristPrevPos, elbowPrevPos, shoulderLeftPrevPos, shoulderRightPrevPos; // prev position

// Control and feedback pins
int gripPin = 3;
int wristPin = 5;
int lowerwristPin = 6;
int elbowPin = 9;
int shoulderLeftPin = 10; //5
int shoulderLRightPin = 11; //6


void setup() 
{ 
  // Setup Serial Monitor
  Serial.begin(9600);
  Bluetooth.begin(9600); // Default baud rate of the Bluetooth module
  // Bluetooth.setTimeout(1);
    
  // Home the servo motor
  grip.write(180);
  wrist.write(180);
  lowerwrist.write(180); //? doesnt work
  elbow.write(180);
  shoulderLeft.write(180);
  shoulderRight.write(180);
  // delay(20);
  // Attach myservo object to control pin
  grip.attach(gripPin); 
  wrist.attach(wristPin); 
  lowerwrist.attach(lowerwristPin); 
  elbow.attach(elbowPin); 
  shoulderLeft.attach(shoulderLeftPin); 
  shoulderRight.attach(shoulderLRightPin); 


  Serial.println("Finished!");

}  

void loop()
{
   if(Bluetooth.available()){
    Serial.println(Bluetooth.readString()); // send from serial to bluetooth
  }
  if(Serial.available()){
    Bluetooth.println(Serial.readString()); // send from bluetooth to serial
  }
  // if (Bluetooth.available() > 0) {
  //   dataIn = Bluetooth.readString();  // Read the data as string
  // if(Serial.available()>0)
  // {
  //   int degree=Serial.parseInt();
    
  //   if (degree>0) {
  //     myservo.write(degree);
  //      myservo2.write(185-degree);
  //     Serial.println(degree);
  //   }
  // }
    // feedbackValue = analogRead(feedbackPin);
    // Serial.println(feedbackValue);
}
