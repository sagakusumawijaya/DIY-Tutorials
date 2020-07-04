const int DATA = 8;
const int LATCH = 9;
const int CLOCK = 10;

const uint16_t JEDA = 50;

void setup() {
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);

  Serial.begin(9600);
}
void loop() {
  byte data = 0;
  for (int8_t i = 0; i <= 8; i++) {
    Serial.print(data);
    Serial.print('\t');
    Serial.println(data, BIN);
    
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, MSBFIRST, data);
    digitalWrite(LATCH, HIGH);
    
    delay(JEDA);
    data = (data << 1) | 1;
  }
  
  Serial.println("\n\n");

  for (int8_t i = 8; i >= 0; i--) {
    Serial.print(data);
    Serial.print('\t');
    Serial.println(data, BIN);
    
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, MSBFIRST, data);
    digitalWrite(LATCH, HIGH);

    delay(JEDA);
    data = (data >> 1);
  }

  Serial.println("\n\n===================\n\n");
}
