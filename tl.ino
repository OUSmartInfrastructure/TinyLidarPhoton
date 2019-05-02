#include <Wire.h>
#define samples 1000 //number of samples for each loop
unsigned long oldTime = 0;
unsigned long timeNow = 0;
unsigned long duration = 0;
uint16_t i,j;

void setMC(){
      Wire.beginTransmission(0x10);
      Wire.write('MC'); //send MC command for continuous mode
      Wire.endTransmission();
      delay(1000);
}

void setup() {

    Serial.begin(115200); //setup the serial port
    Wire.setSpeed(100000); //set to 100KHz
    Wire.begin();

    setMC();
} //setup

void loop(){
    Serial.println("[LOOP]");
    for (j = 0; j < samples; j++){
      Wire.beginTransmission(0x10);  // take single measurement
      Wire.write('D');
      Wire.endTransmission();

  	  Wire.requestFrom(0x10, 2);    // request 2 bytes from tinyLiDAR

      i = Wire.read();        // receive MSB byte
      i = i<<8 | Wire.read(); // receive LSB byte and put them together

      Serial.print(j);
      Serial.print(":");
      Serial.print(millis());
      Serial.print(":");
      Serial.println(i);
      delay(30);//required
    }
    Serial.println("[FOR END]");

    timeNow = millis(); //read the current time in milliseconds
    Serial.print("[TIMENOW]");
    Serial.print(timeNow);
    Serial.print("<>[OLDTIME]");
    Serial.println(oldTime);
    duration = timeNow - oldTime;
    Serial.print("<>[DURATION]");
    Serial.println(duration);
    oldTime = timeNow;
    Serial.print(F("Effective Response Rate is ") );

    float freq = samples/(duration*.001);
    Serial.print(freq);
    Serial.println(F("Hz "));
}
