/*
arduino 5v -> sensor vcc [pin 1]
arduino gnd -> sensor gnd[pin 4]
arduino pin 13-> sensor echo[pin 3]
arduino pin 12 -> sensor trig[pin 2]
*/ 

const int echo = 13;
const int trig = 12;

int duration = 0;
int distance = 0;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  Serial.begin(9600);
}


 

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig, HIGH);

  duration=(pulseIn(echo, HIGH));
  distance = (duration/2) / 28.5;
  Serial.println(distance);

}
