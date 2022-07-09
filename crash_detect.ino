/*
1. set the aurduino in the bread board
2. senosr vcc -> aurdino 5v
3. sensor gnd -> aurduino gnd
4. sensor trig -> aurdino 9
5. sensor echo -> aurdino 10
6. buzzer long leg -> aurduino 11
7. buzzer short leg -> aurduino gnd 
8. light long leg > aurduino 13
9. led short leg -> aurduino gnd
*/

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 13;
const int ledPin_yellow = 6;
const int ledPin_green = 3;

// defines variables
long duration;
int distance;
int safetyDistance;


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
pinMode(ledPin_yellow, OUTPUT);
pinMode(ledPin_green, OUTPUT);
Serial.begin(9600); // Starts the serial communication

}


void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(10);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

safetyDistance = distance;


if (safetyDistance>=1 && safetyDistance <= 5){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
}

else if (safetyDistance>=5 && safetyDistance <= 10)
{
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin_yellow, HIGH);
 }

 else if (safetyDistance>=10 && safetyDistance <= 15)
{
  digitalWrite(ledPin_green, HIGH);
 }

else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
  digitalWrite(ledPin_yellow,LOW);
  digitalWrite(ledPin_green, LOW);
}

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}
