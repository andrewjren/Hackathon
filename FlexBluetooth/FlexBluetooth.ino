#include <SoftwareSerial.h>;
SoftwareSerial Bluetooth(0, 1); 

int sensor = A0;
int sensorvalue = 0;
int button = 7;
int timesbent = 0;

void setup() {
  Bluetooth.begin(9600);
  Serial.begin(9600);
  delay(100); 
  pinMode(button, INPUT);
}

void loop() {
  sensorvalue = analogRead(sensor);
  byte flex = map(sensorvalue, 60, 240, 0, 100);
//  if (Bluetooth.available()) {
    Serial.println(flex);  
    if (digitalRead(button) == HIGH) {
      Serial.println("Button Pressed");
      if (timesBent(flex) > 0) {
        Bluetooth.write('a');
        Serial.write('a');
        timesbent = 0;
//      }
    }
  }
}


int timesBent( int flex ) {
  boolean bent = 0;
  int t = 0;
  while ( t < 10) {
    if (flex < 90) {
      bent = 0; }
      
    else {
      if (bent == 0) {
        bent = 1;
        timesbent++; }
    }
    delay(200);
    t++;
  }
  return timesbent;
}
  
  
