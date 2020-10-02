#define PIN_PUSHBUTTON 2

bool kondisiPBSekarang = LOW;
bool kondisiPBTerakhir = LOW;

uint16_t counter = 0;
unsigned long timer = 0;

const uint16_t INTERVAL = 200;

void setup() {
  pinMode(PIN_PUSHBUTTON, INPUT);

  Serial.begin(9600);
  Serial.println("MULAI");

  kondisiPBTerakhir = digitalRead(PIN_PUSHBUTTON);
  timer = millis();
}

void loop() {
  kondisiPBSekarang = digitalRead(PIN_PUSHBUTTON);
  if (kondisiPBTerakhir == LOW && kondisiPBSekarang == HIGH) {
    if (millis() - timer > INTERVAL) {
      Serial.print("PRESSED ke-");
      Serial.println(counter++);
      timer = millis();
    }
  }
  kondisiPBTerakhir = kondisiPBSekarang;
}
