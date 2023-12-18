#include  <Servo.h>
Servo myServo;

int const butPin = 7;
int const sensPin = 8;
int angle1 = 45;
int angle2 = 135;

void setup() {
  pinMode(butPin, INPUT);
  pinMode(sensPin, INPUT);

  myServo.attach(9);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(butPin) == HIGH) {
    wave();
  }

  if (digitalRead(sensPin) == HIGH) {
    wave();
  }

  // if (digitalRead(butPin) == HIGH){
  //   Serial.println("1");
  // } else {
  //   Serial.println("0");
  // }



  if (digitalRead(sensPin) == HIGH){
    Serial.println("MOTION DETECTED");
  } else {
    Serial.println("NO MOTION");
  }
}

// wave for 2 seconds when wave is called
void wave(){
  int time = 0;

  while (time < 10000){
    Serial.print("time: ");
    Serial.println(time);
    myServo.write(angle1);
    // Serial.print("angle: ");
    // Serial.println(angle1);
    delay(1000);
    
    myServo.write(angle2);
    // Serial.print("angle: ");
    // Serial.println(angle2);
    delay(1000);

    time+=2000;
  }

}