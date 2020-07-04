#define triggerPin  11  // pin trigger sensor ultrasonik
#define echoPin     12  // pin echo sensor ultrasonik

#define DATA  8   // pin SER SN74HC595
#define LATCH 9   // pin RCLK SN74HC595
#define CLOCK 10  // pin SRCLK SN74HC595

const uint16_t JEDA = 10;
const uint8_t RATA_RATA = 5;

unsigned long durasi = 0;
unsigned long cm = 0;

byte data[9] = {255, 127, 63, 31, 15, 7, 3, 1, 0};

void setup() {
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);

  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  cm = 0;
  for (uint8_t i = 1; i <= RATA_RATA; i++) {
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    durasi = pulseIn(echoPin, HIGH);
    cm +=  durasi / 29 / 2;
  }

  cm = cm / RATA_RATA;

  Serial.print("Objek terdeteksi :\t");
  Serial.print(cm); Serial.println(" cm");
  Serial.println();

  if (cm > 20) {
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, MSBFIRST, 0);
    digitalWrite(LATCH, HIGH);
  } else {
    int indeks = (cm / 2) - 1;
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, MSBFIRST, data[indeks]);
    digitalWrite(LATCH, HIGH);
  }
  delay(JEDA);
}
