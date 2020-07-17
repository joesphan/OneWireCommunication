/////////////////////////////////////////////////////////////////////////////////
// reads from Pin A2 and A3 of the attiny13 and dumps the data onto the oneWire Protocol
//
//
//////////////////////////////////////////////////////////////////////////////////
#define txDDR DDRB
#define txPort PORTB
#define txHIGH B00000001
#define txLOW B11111110
#define vsensepin A2
#define isensepin A3
#define baudrate 500

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  analogReference(INTERNAL);
  transmitter_init();

}

void loop() {
  // put your main code here, to run repeatedly:
  int vsense = analogRead(vsensepin);
  int isense = analogRead(isensepin);
  transmitBuffered(vsense, isense);
  //transmitBuffered(0xAAFF, 0xAAFF);
  /*
  digitalWrite(13, HIGH);
  delayMicroseconds(1);
  digitalWrite(13, LOW);
  */
}
