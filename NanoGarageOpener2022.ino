#include <SoftwareSerial.h>
SoftwareSerial BT_Serial(6,8); // RX, TX

int incomingByte = 0;   // for incoming serial data

void setup() {
        Serial.begin(9600);
        BT_Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        pinMode(LED_BUILTIN, OUTPUT);
        
        // joel's uses PIN10
        pinMode(11,OUTPUT);
}

void loop() {

        // send data only when you receive data:
        if (BT_Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = BT_Serial.read();

                if (incomingByte == 121){
                  //digitalWrite(9, HIGH);
                  digitalWrite(11, HIGH);
                  Serial.println("in if statement...");
                  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
                  delay(1000);                       // wait for a second
                  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
                 }
                if (incomingByte == 110){
                  digitalWrite(11,LOW);
                }
                Serial.print("I received: ");
                Serial.println(incomingByte, DEC);
        }
}
