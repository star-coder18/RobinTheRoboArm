#include <SoftwareSerial.h>  //this is for serial communication
#include <Servo.h>

Servo grip;           //6 -> 10 а.к.а grip in out
Servo wrist;          //5 -> 6 въртене грип
Servo lowerwrist;     //4 -> 11 пин kitka
Servo elbow;          //3 -> 9 lakut
Servo shoulderLeft;   //2 -> 3 по платка 
Servo shoulderRight;  //1-> 5 по платка

SoftwareSerial Bluetooth(2, 4);  //rx tx //7 2

int gripPos, wristPos, lowerwristPos, elbowPos, shoulderLeftPos, shoulderRightPos;                          // current position
int gripPrevPos, wristPrevPos, lowerwristPrevPos, elbowPrevPos, shoulderLeftPrevPos, shoulderRightPrevPos;  // prev position

// Control and feedback pins
int gripPin = 10;
int wristPin = 6;
int lowerwristPin = 11;
int elbowPin = 9;
int shoulderLeftPin = 3;
int shoulderLRightPin = 5;
String dataIn = "";

//old pins on arduino
// int gripPin = 3;
// int wristPin = 5;
// int lowerwristPin = 6;
// int elbowPin = 9;
// int shoulderLeftPin = 10;
// int shoulderLRightPin = 11;



void setup() {
  grip.attach(gripPin);
  wrist.attach(wristPin);
  lowerwrist.attach(lowerwristPin);
  elbow.attach(elbowPin);
  shoulderLeft.attach(shoulderLeftPin);
  shoulderRight.attach(shoulderLRightPin);
  // Setup Serial Monitor
  Serial.begin(9600);
  Bluetooth.begin(9600);

//Inirial pos of Robin
  gripPrevPos = 90;
  wristPrevPos = 150;
  lowerwristPrevPos = 35;
  elbowPrevPos = 90;
  shoulderLeftPrevPos = 85;
  shoulderRightPrevPos = 80;

  // Home the servo motor
  grip.write(90);
  wrist.write(90);
  lowerwrist.write(lowerwristPrevPos);  //this is straight
  elbow.write(elbowPrevPos);
  shoulderLeft.write(shoulderLeftPrevPos);
  shoulderRight.write(shoulderRightPrevPos);

  Serial.println("Finished!");
}

void loop() {
  if (Bluetooth.available() > 0) {
    dataIn = Bluetooth.readString();
    Serial.println(dataIn);}

    if (dataIn.startsWith("s1")) {
      String dataInS = dataIn.substring(2, dataIn.length());  //from "s1120" to "120"
      shoulderRightPos = dataInS.toInt();
    }

    shoulderRight.write(shoulderRightPos);
    delay(50);
    
    if (dataIn.startsWith("s2")) {
      String dataInS = dataIn.substring(2, dataIn.length());  //from "s1120" to "120"
      shoulderLeftPos = dataInS.toInt();
    }

    shoulderLeft.write(shoulderLeftPos);
    delay(50);

    if (dataIn.startsWith("s3")) { //?
      String dataInS = dataIn.substring(2, dataIn.length());  //from "s1120" to "120"
      elbowPos = dataInS.toInt();
    }

    elbow.write(elbowPos);
    delay(50);

     if (dataIn.startsWith("s4")) {
      String dataInS = dataIn.substring(2, dataIn.length());  //from "s1120" to "120"
      lowerwristPos = dataInS.toInt();
    }

    lowerwrist.write(lowerwristPos);
    delay(50);

     if (dataIn.startsWith("s5")) {
      String dataInS = dataIn.substring(2, dataIn.length());  //from "s1120" to "120"
      wristPos = dataInS.toInt();
    }

    wrist.write(wristPos);
    delay(50);

    if (dataIn.startsWith("s6")) {
      String dataInS = dataIn.substring(2, dataIn.length());  //from "s1120" to "120"
      gripPos = dataInS.toInt();
    }

    grip.write(gripPos);
    delay(50);
    // if(gripPrevPos > gripPos)
    // {
    //      for ( int j = gripPrevPos; j >= gripPos; j--) {   // Run servo down
    //       grip.write(j);
    //       delay(20);    // defines the speed at which the servo rotates
    //     }
    // }


    // if (servo1PPos < servo1Pos) {
    //     for ( int j = servo1PPos; j <= servo1Pos; j++) {   // Run servo up
    //       servo01.write(j);
    //       delay(20);
    //     }
    //   }
    //tuk
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
//}
//}
