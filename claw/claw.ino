#include <Servo.h>

Servo myservo;

const int trigPin = 9;
const int echoPin = 10;
const int motor = 11;
long duration;
int distance;
int rel = 0;
int rd_start = 1;
int activate_distance = 25; 

void setup()
{
    myservo.attach(motor);
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    Serial.begin(9600); // Starts the serial communication
    myservo.write(80);
}

void loop()
{
    digitalWrite(trigPin, LOW);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);

    distance = duration * 0.034 / 2;

    delay(1000);

    if(rd_start == 1)
    {
      Serial.println("it sfhasfi sehoahfseoi fhaoisjef oiashfj ");
      if(distance <= activate_distance && rel == 0) 
      {
        myservo.write(180);
        delay(1000);
        rd_start = 0;
      }
    }
    if(rd_start == 1)
    {
      if(distance <= activate_distance && rel == 1) 
      {
        myservo.write(80);
        delay(1000);
        rd_start = 0;
      }  
    }
    if(rd_start == 0)
    {
      if(distance > activate_distance && rel == 1)
      {
        Serial.println("switch u back bad boy");
        rd_start = 1;
        rel = 0;
      } 
    }
    if(rd_start == 0)
    {
      if(distance > activate_distance && rel == 0)
      {
        Serial.println(rel);
        rd_start = 1;
        rel = 1;
        Serial.println(rel);
      } 
    }

    
    Serial.print("Distance: ");
    Serial.println(distance);
    Serial.print("rd_start: ");
    Serial.println(rd_start);
    Serial.print("rel: ");
    Serial.println(rel);
}
