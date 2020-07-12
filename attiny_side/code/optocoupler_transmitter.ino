
#define datarate (1000000 / baudrate)     //delay

void transmitter_init() {
  pinMode(txpin, OUTPUT);
  digitalWrite(txpin, LOW);
}

void transmitBuffered(int data1, int data0) {
  bool dataout[32];
  //load the buffer
  //B1
  for (int i = 15; i > -1; i--) {
    dataout[i + 16] = bitRead(data1, i);
  }
  //B0
  for (int i = 15; i > -1; i--) {
    dataout[i] = bitRead(data0, i);
  }

  digitalWrite(txpin, HIGH);  //first bit is discarded
  delayMicroseconds(datarate);
  //Serial.println("START");
  for (int i = 31; i >= 0 ; i--) {
    digitalWrite(txpin, dataout[i]);
    delayMicroseconds(datarate);
    //Serial.println(dataout[i]);
  }
  //Serial.println("DONE");
  digitalWrite(txpin, LOW);
  delayMicroseconds(datarate);
}

void transmitUnBuffered(int data1, int data0) {
  bool dataout[32];
  //load the buffer
  digitalWrite(txpin, HIGH);  //first bit is discarded
  delayMicroseconds(datarate);
  //B1
  for (int i = 15; i > -1; i--) {
    digitalWrite(txpin, bitRead(data1, i));
    delayMicroseconds(datarate);
  }
  //B0
  for (int i = 15; i > -1; i--) {
    digitalWrite(txpin, bitRead(data0, i));
    delayMicroseconds(datarate);
  }
  digitalWrite(txpin, LOW);
  delayMicroseconds(datarate);
}
