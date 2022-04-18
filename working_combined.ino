#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11);// RX, TX
unsigned char incomingByte;
String value;
String EPC;

#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
}

void loop() {

      Serial.begin(115200);
  mySerial.begin(115200);
  delay(200);
    byte message[] = {0xBB,0x00,0x27,0x00,0x03,0x22,0x27,0x10,0x83,0x7E};
  mySerial.write(message, sizeof(message));
  
  // put your main code here, to run repeatedly:
  while (mySerial.available() > 0) {
  
    incomingByte = mySerial.read();
    value += String(incomingByte,HEX);
    value += " ";
  }
  if(value.length() > 1){

    if (value.startsWith("bb 1")) // can not read
    {
      Serial.print("NO");
      Serial.println();
      }
if (value.startsWith("bb 2")) // can read
    {
      Serial.print("yes");
      Serial.println();
      
      //Serial.print(value.substring(52,54));
      //Serial.println();
      //EPC = value.substring(63,64);
      //EPC.toInt();
      



              if (value.substring(52,54).equals("95")){

        Serial.print("1111111111");
        digitalWrite(4,HIGH);
        delay(3000);
        digitalWrite(4,LOW);
        Serial.println();
        }
              if (value.substring(52,54).equals("a5")){

        Serial.print("222222222222");
        digitalWrite(5,HIGH);
        delay(3000);
        digitalWrite(5,LOW);
        Serial.println();
        }
              if (value.substring(52,54).equals("b5")){

        Serial.print("33333333333");
                digitalWrite(6,HIGH);
        delay(3000);
        digitalWrite(6,LOW);
        Serial.println();
        }
              if (value.substring(52,54).equals("c5")){

        Serial.print("44444444444444");
                digitalWrite(7,HIGH);

        delay(3000);
        digitalWrite(7,LOW);
        Serial.println();
        }

      }// end can read
     
    //Serial.print(value);
    //Serial.println();
    value = "";
  }
  delay(60);
  Serial.begin(9600);
  //-------------------------

Serial.begin(9600);
   // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  //Serial.print("Distance: ");
  //Serial.begin(115200);
  Serial.print(distance);
  //Serial.begin(9600);
  
  //Serial.println(" cm");
if(distance<50)
{
  //Serial.begin(9600);
  
  //Serial.write(0xAA);
  //Serial.write(0x55);
  //Serial.write(0x01);
  //Serial.write(distance);
  //Serial.write(0x00);
  //Serial.write(0x00);
  //Serial.write(0x00);
  //Serial.write(0x55);
  //Serial.write(0xAA); 

    if(distance<25)

    {
      digitalWrite(9,HIGH);
      delay(3500);
      digitalWrite(9,LOW);
    }
      else{
        digitalWrite(8,HIGH);
      delay(3500);
      digitalWrite(8,LOW);
        }
      
  
  }
Serial.begin(115200);

}
