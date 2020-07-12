#define txpin 3
#define baudrate 50000

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  transmitter_init();
  //Serial.println(0b110000000001001, BIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  transmitUnBuffered(0xAAFF, 0xAAFF);
  digitalWrite(13, HIGH);
  delayMicroseconds(1);
  digitalWrite(13, LOW);
}
