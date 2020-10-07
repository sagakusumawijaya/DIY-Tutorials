#include <SoftwareSerial.h>

#define PIN_RX_UNO  8 // Pin TX Bluetooth HC-05
#define PIN_TX_UNO  9 // Pin RX Bluetooth HC-05
#define PIN_LED 13

SoftwareSerial BT_SERIAL(PIN_RX_UNO, PIN_TX_UNO);

String teks = "";
const unsigned long baudRateBT = 9600;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, HIGH);

  Serial.begin(9600);
  Serial.println("MULAI");

  BT_SERIAL.begin(baudRateBT);
  Serial.print("BTserial started at "); Serial.println(baudRateBT);
  Serial.println(" ");
}

void loop() {
  if (BT_SERIAL.available() > 0) {
    teks = BT_SERIAL.readStringUntil("$");
    if (teks.equals("1$")) {
      digitalWrite(PIN_LED, LOW);
      Serial.println("LED ON");
      teks = "";
    } else if (teks.equals("0$")) {
      digitalWrite(PIN_LED, HIGH);
      Serial.println("LED OFF");
      teks = "";
    }
  }
}
