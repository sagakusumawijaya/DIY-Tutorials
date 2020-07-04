void setup() {
  for(uint8_t i = 2; i<=9; i++)
    pinMode(i, OUTPUT);
  
}

void loop() {
  for(uint8_t i = 9; i>=2; i--){
    digitalWrite(i, HIGH);
    delay(50);
  }

  for(uint8_t i = 2; i<=9; i++){
    digitalWrite(i, LOW);
    delay(50);
  }
}
