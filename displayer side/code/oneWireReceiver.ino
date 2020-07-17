#define delaytime (1000000 / baudrate)    //delay

int data1 = 0;
int data0 = 0;
void receiver_init() {
  DDRD = DDRD & rxPinDDRDIR;
  pinMode(ch1DataPin, INPUT_PULLUP);
}

bool readData(byte pin, bool invert) {                //return true if new data recvd   //blocking!!!
  bool StartBit[4];
  if (!fastRead(pin, invert)) {                //if the pin starts out low
    while (!fastRead(pin, invert)) {           //wait for pin to pull high
    }
    digitalWrite(13, HIGH);
    digitalWrite(13, LOW);
    delayMicroseconds(delaytime / 8);     //sample in the middle of the signal
    for (int i = 0; i < 4; i++) {
      StartBit[i] = fastRead(pin, invert);
      delayMicroseconds(delaytime / 4);
    }
    delayMicroseconds(delaytime / 8);     //reset sample so its within sync again

    //if start sequence failed, will not continue to run
    if (StartBit[0] == 1 && StartBit[1] == 0 && StartBit[2] == 1 && StartBit[3] == 0) {                  //check for valid start bit
      delayMicroseconds(delaytime / 2);     //set to sample in the middle of regular bits
      for (int i = 15; i > -1; i--) {
        bitWrite(data1, i, fastRead(pin, invert));
        delayMicroseconds(delaytime);
      }
      for (int i = 15; i > -1; i--) {
        bitWrite(data0, i, fastRead(pin, invert));
        delayMicroseconds(delaytime);
      }
      delayMicroseconds(delaytime);                   //ignore last bit
      return true;
    }
    else {
    }
  }
  return false;
}

bool fastRead(byte pinSel, bool invert) {
  bool pinData;
  byte rxdata = rxPort;
  rxdata = rxdata & pinSel;                     //bit mask
  if (rxdata == pinSel) {
    pinData = HIGH ^ invert;
  }
  else
  {
    pinData = LOW ^ invert;
  }
  return pinData;
}
