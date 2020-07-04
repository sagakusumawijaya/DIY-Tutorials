
const int DATA = 8;  
const int LATCH = 9;
const int CLOCK = 10;

void setup() {
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);

  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, MSBFIRST, B01010101);
  digitalWrite(LATCH, HIGH);
}
void loop(){
  
}
