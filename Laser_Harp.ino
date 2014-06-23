/*******************************************
 Laser Harp
 by Bithead942
 
 The circuit:
 * digital in 1 connected to MIDI jack pin 5
 * MIDI jack pin 2 connected to ground
 * MIDI jack pin 4 connected to +5V through 220-ohm resistor
 Attach a MIDI cable to the jack, then to a MIDI synth, and play music.
 
 Sharp IR Range Finders (GP2D12)
 Analog Pin 1 - Low Note
 Analog Pin 2
 Analog Pin 3
 Analog Pin 4
 Analog Pin 5 - High Note
 
 DIP Switch
 Digital Pin 1
 Digital Pin 2
 Digital Pin 3
 Digital Pin 4

******************************************/
 
const int sensorNote1 = 1;
const int sensorNote2 = 2;
const int sensorNote3 = 3;
const int sensorNote4 = 4;
const int sensorNote5 = 5;

const int DIPPin1 = 3;
const int DIPPin2 = 4;
const int DIPPin3 = 5;
const int DIPPin4 = 6;

const int sensorMin = 90;
const int sensorMax = 400;

int valueNote1 = 0;
int valueNote2 = 0;
int valueNote3 = 0;
int valueNote4 = 0;
int valueNote5 = 0;

int valueDIP1 = 0;
int valueDIP2 = 0;
int valueDIP3 = 0;
int valueDIP4 = 0;

void setup() {
  //  Set MIDI baud rate:
  Serial.begin(31250);
  pinMode(sensorNote1, INPUT);
  pinMode(sensorNote2, INPUT);
  pinMode(sensorNote3, INPUT);
  pinMode(sensorNote4, INPUT);
  pinMode(sensorNote5, INPUT);
  
  pinMode(DIPPin1, INPUT);
  pinMode(DIPPin2, INPUT);
  pinMode(DIPPin3, INPUT);
  pinMode(DIPPin4, INPUT);

}

void loop() {
  valueDIP1 = digitalRead(DIPPin1);
  valueDIP2 = digitalRead(DIPPin2);
  valueDIP3 = digitalRead(DIPPin3);
  valueDIP4 = digitalRead(DIPPin4);
  
  if (valueDIP1 == HIGH && valueDIP2 == LOW && valueDIP3 == LOW && valueDIP4 == LOW) {
     Mode1();
  }
  if (valueDIP1 == LOW && valueDIP2 == HIGH && valueDIP3 == LOW && valueDIP4 == LOW) {
     Mode2();
  }  
  if (valueDIP1 == LOW && valueDIP2 == LOW && valueDIP3 == HIGH && valueDIP4 == LOW) {
     Mode3();
  }  
  if (valueDIP1 == LOW && valueDIP2 == LOW && valueDIP3 == LOW && valueDIP4 == HIGH) {
     Mode4();
  }  
    
}

/****************************************************
C Major - 3 notes per beam
****************************************************/
void Mode1() {
  // Turn Note On
/*
 C 1 = 18
 E 1 = 1C
 G 1 = 1F
*/
  valueNote1 = readNote(sensorNote1);
  if (valueNote1 <= 30 && valueNote1 > 10) {
     noteOn(0x90, 0x18, 0x45);
  }
  if (valueNote1 <= 60 && valueNote1 > 30) {
     noteOn(0x90, 0x1C, 0x45);
  }
  if (valueNote1 <= 90 && valueNote1 > 60) {
     noteOn(0x90, 0x1F, 0x45);
  }

/*
 C 2 = 24
 E 2 = 28
 G 2 = 2B
*/
  valueNote2 = readNote(sensorNote2);
  if (valueNote2 <= 30 && valueNote2 > 10) {
     noteOn(0x90, 0x24, 0x45);
  }
  if (valueNote2 <= 60 && valueNote2 > 30) {
     noteOn(0x90, 0x28, 0x45);
  }
  if (valueNote2 <= 90 && valueNote2 > 60) {
     noteOn(0x90, 0x2B, 0x45);
  }

/*
 C 3 = 30
 E 3 = 34
 G 3 = 37
*/
  valueNote3 = readNote(sensorNote3);
  if (valueNote3 <= 30 && valueNote3 > 10) {
     noteOn(0x90, 0x30, 0x45);
  }
  if (valueNote3 <= 60 && valueNote3 > 30) {
     noteOn(0x90, 0x34, 0x45);
  }
  if (valueNote3 <= 90 && valueNote3 > 60) {
     noteOn(0x90, 0x37, 0x45);
  }

/*
 C 4 = 3C
 E 4 = 40
 G 4 = 43
*/
  valueNote4 = readNote(sensorNote4);
  if (valueNote4 <= 30 && valueNote4 > 10) {
     noteOn(0x90, 0x3C, 0x45);
  }
  if (valueNote4 <= 60 && valueNote4 > 30) {
     noteOn(0x90, 0x40, 0x45);
  }
  if (valueNote4 < 90 && valueNote4 > 60) {
     noteOn(0x90, 0x43, 0x45);
  }

/*
 C 5 = 48
 E 5 = 4C
 G 5 = 4F
*/

  valueNote5 = readNote(sensorNote5);
  if (valueNote5 <= 30 && valueNote5 > 10) {
     noteOn(0x90, 0x48, 0x45);
  }
  if (valueNote5 <= 60 && valueNote5 > 30) {
     noteOn(0x90, 0x4C, 0x45);
  }
  if (valueNote5 < 90 && valueNote5 > 60) {
     noteOn(0x90, 0x4F, 0x45);
  }
  SixteenthNote();
  
  // Turn note off
     
  if (valueNote1 <= 30 && valueNote1 > 10) {
     noteOff(0x90, 0x18);
  }
  if (valueNote1 <= 60 && valueNote1 > 30) {
     noteOff(0x90, 0x1C);
  }
  if (valueNote1 <= 90 && valueNote1 > 60) {
     noteOff(0x90, 0x1F);
  }

  if (valueNote2 <= 30 && valueNote2 > 10) {
     noteOff(0x90, 0x24);
  }
  if (valueNote2 <= 60 && valueNote2 > 30) {
     noteOff(0x90, 0x28);
  }
  if (valueNote2 < 90 && valueNote1 > 60) {
     noteOff(0x90, 0x2B);
  }

  if (valueNote3 <= 30 && valueNote3 > 10) {
     noteOff(0x90, 0x30);
  }
  if (valueNote3 <= 60 && valueNote3 > 30) {
     noteOff(0x90, 0x34);
  }
  if (valueNote3 <= 90 && valueNote3 > 60) {
     noteOff(0x90, 0x37);
  }

  if (valueNote4 <= 30 && valueNote4 > 10) {
     noteOff(0x90, 0x3C);
  }
  if (valueNote4 <= 60 && valueNote4 > 30) {
     noteOff(0x90, 0x40);
  }
  if (valueNote4 <= 90 && valueNote4 > 60) {
     noteOff(0x90, 0x43);
  }

  if (valueNote5 <= 30 && valueNote5 > 10) {
     noteOff(0x90, 0x48);
  }
  if (valueNote5 <= 60 && valueNote5 > 30) {
     noteOff(0x90, 0x4C);
  }
  if (valueNote5 <= 90 && valueNote5 > 60) {
     noteOff(0x90, 0x4F);
  }
     
  SixteenthNote();
  
}

/****************************************************
C Major - 1 note per beam
****************************************************/
void Mode2() {
/*
 C 3 = 30
 D 3 = 32
 E 3 = 34
 F 3 = 35
 G 3 = 37
*/
  valueNote1 = readNote(sensorNote1);
  if (valueNote1 < 90 && valueNote1 > 60) {
     noteOn(0x90, 0x24, 0x45);
  }

  valueNote2 = readNote(sensorNote2);
  if (valueNote2 < 90 && valueNote2 > 60) {
     noteOn(0x90, 0x2B, 0x45);
  }

  valueNote3 = readNote(sensorNote3);
  if (valueNote3 < 90 && valueNote3 > 60) {
     noteOn(0x90, 0x30, 0x45);
  }

  valueNote4 = readNote(sensorNote4);
  if (valueNote4 < 90 && valueNote4 > 60) {
     noteOn(0x90, 0x32, 0x45);
  }

  valueNote5 = readNote(sensorNote5);
  if (valueNote5 < 90 && valueNote5 > 60) {
     noteOn(0x90, 0x34, 0x45);
  }

  SixteenthNote();

  if (valueNote1 <= 90 && valueNote1 >= 60) {
     noteOff(0x90, 0x24);
  }

  if (valueNote2 <= 90 && valueNote2 >= 60) {
     noteOff(0x90, 0x2B);
  }

  if (valueNote3 <= 90 && valueNote3 >= 60) {
     noteOff(0x90, 0x30);
  }

  if (valueNote4 <= 90 && valueNote4 >= 60) {
     noteOff(0x90, 0x32);
  }

  if (valueNote5 <= 90 && valueNote5 >= 60) {
     noteOff(0x90, 0x34);
  }
     
  SixteenthNote();
  
}

/****************************************************
Axel F
****************************************************/
void Mode3() {
  valueNote1 = readNote(sensorNote1);
  if (valueNote1 < 90 && valueNote1 > 50) {
     noteOn(0x90, 0x35, 0x45);
     QuarterNote();
     noteOff(0x90, 0x35);
     noteOn(0x90, 0x38, 0x45);
     EighthNote();
     SixteenthNote();
     noteOff(0x90, 0x38);
     noteOn(0x90, 0x35, 0x45);
     EighthNote();
     noteOff(0x90, 0x35);
     noteOn(0x90, 0x35, 0x45);
     SixteenthNote();
     noteOff(0x90, 0x35);
     noteOn(0x90, 0x3A, 0x45);
     EighthNote();
     noteOff(0x90, 0x3A);
     noteOn(0x90, 0x35, 0x45);
     EighthNote();
     noteOff(0x90, 0x35);
     noteOn(0x90, 0x33, 0x45);
     EighthNote();
     noteOff(0x90, 0x33);
   }

  valueNote2 = readNote(sensorNote2);
  if (valueNote2 < 90 && valueNote2 > 60) {
     noteOn(0x90, 0x35, 0x45);
     QuarterNote();
     noteOff(0x90, 0x35);
     noteOn(0x90, 0x3C, 0x45);
     EighthNote();
     SixteenthNote();
     noteOff(0x90, 0x3C);
     noteOn(0x90, 0x35, 0x45);
     EighthNote();
     noteOff(0x90, 0x35);
     noteOn(0x90, 0x35, 0x45);
     SixteenthNote();
     noteOff(0x90, 0x35);
     noteOn(0x90, 0x3D, 0x45);
     EighthNote();
     noteOff(0x90, 0x3D);
     noteOn(0x90, 0x3C, 0x45);
     EighthNote();
     noteOff(0x90, 0x3C);
     noteOn(0x90, 0x38, 0x45);
     EighthNote();
     noteOff(0x90, 0x38);
  }

  valueNote3 = readNote(sensorNote3);
  if (valueNote3 < 90 && valueNote3 > 60) {
     noteOn(0x90, 0x35, 0x45);
     EighthNote();
     noteOff(0x90, 0x35);
     noteOn(0x90, 0x3C, 0x45);
     EighthNote();
     noteOff(0x90, 0x3C);
     noteOn(0x90, 0x41, 0x45);
     EighthNote();
     noteOff(0x90, 0x41);
     noteOn(0x90, 0x35, 0x45);
     SixteenthNote();
     noteOff(0x90, 0x35);
     noteOn(0x90, 0x33, 0x45);
     EighthNote();
     noteOff(0x90, 0x33);
     noteOn(0x90, 0x33, 0x45);
     SixteenthNote();
     noteOff(0x90, 0x33);
     noteOn(0x90, 0x30, 0x45);
     EighthNote();
     noteOff(0x90, 0x30);
     noteOn(0x90, 0x37, 0x45);
     EighthNote();
     noteOff(0x90, 0x37);
     noteOn(0x90, 0x35, 0x45);
     EighthNote();
     QuarterNote();
     QuarterNote();
     noteOff(0x90, 0x35);
  }



}

/****************************************************
The Final Countdown
****************************************************/
void Mode4() {

  valueNote1 = ConvertToPercent(analogRead(sensorNote1));
  if (valueNote1 <= 90 && valueNote1 >= 60) {
     noteOn(0x90, 0x2D, 0x45);
     QuarterNote();
     noteOff(0x90, 0x2D);
     
     EighthNote();

     chord3On(0x90, 0x36, 0x39, 0x45, 0x45);
     SixteenthNote();
     chord3Off(0x90, 0x36, 0x39, 0x45);

     noteOn(0x90, 0x3B, 0x45);
     SixteenthNote();
     noteOff(0x90, 0x3B);
     
     chord3On(0x90, 0x36, 0x39, 0x45, 0x45);
     QuarterNote();
     chord3Off(0x90, 0x36, 0x39, 0x45);
     
     chord3On(0x90, 0x2D, 0x31, 0x36, 0x45);
     QuarterNote();
     chord3Off(0x90, 0x2D, 0x31, 0x36);
  }

  valueNote2 = ConvertToPercent(analogRead(sensorNote2));
  if (valueNote2 <= 90 && valueNote2 >= 60) {
     noteOn(0x90, 0x2A, 0x45);
     QuarterNote();
     noteOff(0x90, 0x2A);
     
     EighthNote();
     
     chord3On(0x90, 0x36, 0x39, 0x3E, 0x45);
     SixteenthNote();
     chord3Off(0x90, 0x36, 0x39, 0x3E);
     
     noteOn(0x90, 0x3D, 0x45);
     SixteenthNote();
     noteOff(0x90, 0x3D);
     
     chord3On(0x90, 0x36, 0x39, 0x3E, 0x45);
     EighthNote();
     chord3Off(0x90, 0x36, 0x39, 0x3E);
     
     noteOn(0x90, 0x3D, 0x45);
     SixteenthNote();
     noteOff(0x90, 0x3D);
     
     chord3On(0x90, 0x32, 0x36, 0x3B, 0x45);
     EighthNote();
     chord3Off(0x90, 0x32, 0x36, 0x3B);
     
     EighthNote();
  }

  valueNote3 = ConvertToPercent(analogRead(sensorNote3));
  if (valueNote3 <= 90 && valueNote3 >= 60) {
     noteOn(0x90, 0x32, 0x45);
     QuarterNote();
     noteOff(0x90, 0x32);
     
     EighthNote();
     
     chord3On(0x90, 0x36, 0x3B, 0x3E, 0x45);
     SixteenthNote();
     chord3Off(0x90, 0x36, 0x3B, 0x3E);
     
     noteOn(0x90, 0x3D, 0x45);
     SixteenthNote();
     noteOff(0x90, 0x3D);
     
     chord3On(0x90, 0x36, 0x3B, 0x3E, 0x45);
     QuarterNote();
     chord3Off(0x90, 0x36, 0x3B, 0x3E);
     
     chord3On(0x90, 0x2F, 0x32, 0x36, 0x45);
     QuarterNote();
     chord3Off(0x90, 0x2F, 0x32, 0x36);
     
     SixteenthNote();
  }

  valueNote4 = ConvertToPercent(analogRead(sensorNote4));
  if (valueNote4 <= 90 && valueNote4 >= 60) {
     noteOn(0x90, 0x2B, 0x45);
     QuarterNote();
     noteOff(0x90, 0x2B);
     
     EighthNote();
     
     chord3On(0x90, 0x34, 0x38, 0x3B, 0x45);
     SixteenthNote();
     chord3Off(0x90, 0x34, 0x38, 0x3B);
     
     noteOn(0x90, 0x39, 0x45);
     SixteenthNote();
     noteOff(0x90, 0x39);
     
     chord3On(0x90, 0x35, 0x38, 0x3B, 0x45);
     EighthNote();
     chord3Off(0x90, 0x35, 0x38, 0x3B);
     
     noteOn(0x90, 0x39, 0x45);
     EighthNote();
     noteOff(0x90, 0x39);

     noteOn(0x90, 0x34, 0x45);
     noteOn(0x90, 0x38, 0x45);
     EighthNote();
     noteOff(0x90, 0x34);
     noteOff(0x90, 0x38);

     noteOn(0x90, 0x39, 0x45);
     EighthNote();
     noteOff(0x90, 0x39);
 }

  valueNote5 = ConvertToPercent(analogRead(sensorNote5));
  if (valueNote5 <= 90 && valueNote5 >= 60) {
     noteOn(0x90, 0x12, 0x45);
     noteOn(0x90, 0x1E, 0x45);
     SixteenthNote();
     noteOff(0x90, 0x12);
     noteOff(0x90, 0x1E);
  }
}

int readNote(int sensor) {
int tempVal1 = 0;
int tempVal2 = 0;
int tempVal3 = 0;

  tempVal1 = constrain(analogRead(sensor), sensorMin, sensorMax);
  tempVal2 = constrain(analogRead(sensor), sensorMin, sensorMax);
  tempVal3 = constrain(analogRead(sensor), sensorMin, sensorMax);
  return ConvertToPercent((tempVal1 + tempVal2 + tempVal3)/ 3); 
}


void QuarterNote() {
  delay(600); 
}

void EighthNote() {
  delay(300); 
}

void SixteenthNote() {
  delay(150);
}


//  plays a MIDI note.  Doesn't check to see that
//  cmd is greater than 127, or that data values are  less than 127:
void noteOn(int cmd, int pitch, int velocity) {
  Serial.print(cmd, BYTE);
  Serial.print(pitch, BYTE);
  Serial.print(velocity, BYTE);
}

void noteOff(int cmd, int pitch) {
  Serial.print(cmd, BYTE);
  Serial.print(pitch, BYTE);
  Serial.print(0x00, BYTE);
}

void chord3On(int cmd, int note1, int note2, int note3, int velocity) {
  Serial.print(cmd, BYTE);
  Serial.print(note1, BYTE);
  Serial.print(velocity, BYTE);
  Serial.print(note2, BYTE);
  Serial.print(velocity, BYTE);
  Serial.print(note3, BYTE);
  Serial.print(velocity, BYTE);
}

void chord3Off(int cmd, int note1, int note2, int note3) {
  Serial.print(cmd, BYTE);
  Serial.print(note1, BYTE);
  Serial.print(0x00, BYTE);
  Serial.print(note2, BYTE);
  Serial.print(0x00, BYTE);
  Serial.print(note3, BYTE);
  Serial.print(0x00, BYTE);
}

int ConvertToPercent(int RangeValue) {
int iPercent = 0;

  if (RangeValue <= 91) {
    iPercent = 10;
  }
  if (RangeValue <= 104 && RangeValue > 92) {
    iPercent = 20;
  }
  if (RangeValue <= 119 && RangeValue > 105) {
    iPercent = 30;
  }
  if (RangeValue <= 139 && RangeValue > 120) {
    iPercent = 40;
  }
  if (RangeValue <= 159 && RangeValue > 140) {
    iPercent = 50;
  }
  if (RangeValue <= 179 && RangeValue > 160) {
    iPercent = 60;
  }
  if (RangeValue <= 239 && RangeValue > 180) {
    iPercent = 70;
  }
  if (RangeValue <= 299 && RangeValue > 240) {
    iPercent = 80;
  }
  if (RangeValue <= 359 && RangeValue > 300) {
    iPercent = 90;
  }
  if (RangeValue  > 360) {
    iPercent = 100;
  }

  return iPercent;
}
