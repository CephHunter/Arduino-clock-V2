#define segment_1 12
#define segment_2 13
#define segment_4 A0
#define segment_6 A1
#define segment_7 A2
#define segment_9 A3
#define segment_10 A4
#define dubbelPuntLED 10
#define alarmLED 11
#define digitBit_1 2
#define digitBit_2 A5

#define BtnSetClock 3
#define BtnSetAlarm 4
#define BtnUp 5
#define BtnDown 6
#define BtnSnooze 7

#define alarmSound 9
//#define speakerON 

uint32_t totalMilliTime;
uint32_t totalSecTime;
uint32_t totalMinTime;
uint32_t totalHourTime;
uint32_t offsetMilliTime;
uint32_t offsetSecTime;
uint32_t offsetMinTime;
uint32_t offsetHourTime;
uint32_t alarmMillis;
uint32_t alarmSeconds;
uint32_t alarmMinutes;
uint32_t alarmHours;
uint8_t secTime;
uint8_t minTime;
uint8_t hourTime;
// uint8_t alarmSoundSelected = 1;
boolean BtnSetClockON = false;
uint32_t BtnSetClockTimeClicked;
boolean BtnSetAlarmON = false;
uint32_t BtnSetAlarmTimeClicked;
boolean BtnUpON = false;
boolean BtnDownON = false;
boolean BtnSnoozeON = false;
boolean alarmIsON = false;
boolean canChangeAlarmIsON = true;
uint8_t digitPersistence = 1;
uint32_t timeSnoozeClicked;
//uint32_t timeSongStarted;
//uint32_t timeUntillNextNote;
//uint32_t timeUntillSpeakerOff;
//uint32_t timeUntillSpeakerON;
//uint8_t songLine;
boolean alarmforNextDay = false;


// char* Notes[] = {"00", "F2", "G2", "A2", "B2", "C3", "D3", "E3", "F3", "G3", "A3", "B3", "C4", "D4", "E4", "F4", "G4", "A4", "B4", "C5", "D5", "E5", "F5", "G5", "A5", "B5", "C6", "D6", "E6", "F6", "G6", "A6"};
// float noteFreq[] = {0, 87.31, 98, 110, 123.47, 130.81, 146.83, 164.83, 174.61, 196, 220, 246.94, 261.63, 293.66, 329.63, 349.23, 392, 440, 493.88, 523.25, 587.33, 659.25, 698.46, 783.99, 880, 987.77, 1046.50, 1174.66, 1318.51, 1396.91, 1567.98, 1760};

// char* song1_notes[] = {"E5", "A4", "A4", "E5", "A4", "A4", "B4", "A4", "B4", "G4", "B4", "D5", "E5", "A4", "A4", "E5", "A4", "A4", "D5", "E5", "F5", "G5", "F5", "G5", "E5", "A4", "A4", "E5", "A4", "A4", "B4", "A4", "B4", "G4", "B4", "D5", "D5", "E5", "F5", "G5", "D5", "B4", "B4", "A4", "G4", "A4", "E5", "A5", "A5", "G5", "A5", "B5", "G5", "E5", "D5", "B4", "D5", "E5", "A5", "A5", "G5", "A5", "B5", "G5", "E5", "G5", "E5", "A5", "A5", "G5", "A5", "B5", "G5", "E5", "D5", "B4", "D5", "D5", "E5", "F5", "G5", "D5", "B4", "B4", "A4", "G4", "A4", "00"};
// float song1_noteLenght[] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 / 3, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 8, 8, 8 / 3, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 / 3, 0.3};

// char* song2_notes[] = {"A4", "F4", "A4", "A4", "A4", "G4", "B4", "B4", "B4", "B4", "C5", "C5", "C5", "B4", "C5", "D5", "E5", "F5", "F4", "A4", "A4", "A4", "G4", "B4", "B4", "B4", "C5", "C5", "B4", "C5", "D5", "A4", "D5", "A4", "A4", "A4", "B4", "B4", "B4", "C5", "C5", "C5", "B4", "C5", "D5", "E5", "F5", "A4", "A4", "A4", "B4", "B4", "B4", "C5", "C5", "C5", "B4", "C5", "D5", "A4", "D5", "00"};
// float song2_noteLenght[] = {8, 8, 8, 8, 8, 8, 8, 8, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 4, 8, 8, 4, 8, 8, 4, 16, 16, 8, 8, 8, 8, 8, 4, 8, 8, 4, 8, 8, 4, 16, 16, 8, 8, 8, 8, 8, 8, 0.3};

void setup() {
  pinMode(segment_1, OUTPUT);
  pinMode(segment_2, OUTPUT);
  pinMode(segment_4, OUTPUT);
  pinMode(segment_6, OUTPUT);
  pinMode(segment_7, OUTPUT);
  pinMode(segment_9, OUTPUT);
  pinMode(segment_10, OUTPUT);
  pinMode(digitBit_1, OUTPUT);
  pinMode(digitBit_2, OUTPUT);
  pinMode(BtnSetClock, INPUT);
  pinMode(BtnSetAlarm, INPUT);
  pinMode(BtnUp, INPUT);
  pinMode(BtnDown, INPUT);
  pinMode(BtnSnooze, INPUT);
  pinMode(dubbelPuntLED, OUTPUT);
  pinMode(alarmLED, OUTPUT);
  pinMode(alarmSound, OUTPUT);
  // pinMode(speakerON, OUTPUT);

  //Serial.begin(9600);

}

void loop() {
  calcTime();
  Serial.println(String(hourTime) + " : " + String(minTime) + " : " + String(secTime) + " : " + String(totalMilliTime));
  dispMinutes(minTime);
  dispHour(hourTime);

  if ((totalMilliTime / 500) % 2 == 0) {
    analogWrite(dubbelPuntLED, 20);
  } else {
    analogWrite(dubbelPuntLED, 0);
  }
  if (alarmIsON == true) {
    analogWrite(alarmLED, 20);
  } else {
    analogWrite(alarmLED, 0);
  }


  if (digitalRead(BtnSetClock) == HIGH and BtnSetClockON == false) {
    Serial.println("BtnSetClockClicked");
    BtnSetClockON = true;
    BtnSetClockTimeClicked = totalMilliTime;
  }
  if (digitalRead(BtnSetClock) == LOW and BtnSetClockON == true) {
    BtnSetClockON = false;
  }
  if (digitalRead(BtnSetClock) == HIGH and BtnSetClockON == true and (totalMilliTime - BtnSetClockTimeClicked) > 1000) {
    // digitalWrite(speakerON, LOW);
    selectTime();
  }

  if (digitalRead(BtnSetAlarm) == HIGH and BtnSetAlarmON == false) {
    Serial.println("BtnSetAlarmClicked");
    BtnSetAlarmON = true;
    BtnSetAlarmTimeClicked = totalMilliTime;
  }
  if (digitalRead(BtnSetAlarm) == LOW and BtnSetAlarmON == true) {
    BtnSetAlarmON = false;
    canChangeAlarmIsON = true;
    if ((totalMilliTime - BtnSetAlarmTimeClicked) < 1000) {
      // digitalWrite(speakerON, LOW);
      showAlarm();
    }
  }
  if (digitalRead(BtnSetAlarm) == HIGH and BtnSetAlarmON == true and (totalMilliTime - BtnSetAlarmTimeClicked) > 1000 and canChangeAlarmIsON == true) {
    canChangeAlarmIsON = false;
    if (alarmIsON == false) {
      alarmIsON = true;
      if ((minTime * 60000 + hourTime * 3600000) >= alarmMillis) {
        alarmforNextDay = true;
      }
    } else {
      alarmIsON = false;
      alarmforNextDay = false;
      // timeSongStarted = 0;
      // songLine = 0;
      // digitalWrite(speakerON, LOW);
      analogWrite(alarmSound, 0);
    }
  }

  if (((totalMilliTime + offsetMilliTime )/ 1000) % 86400 == 0) {
    alarmforNextDay = false;
  }
  if (digitalRead(BtnSnooze) == HIGH) {
    timeSnoozeClicked = totalMilliTime;
    // timeSongStarted = 0;
    // songLine = 0;
    // digitalWrite(speakerON, LOW);
    analogWrite(alarmSound, 0);
  }
  if (alarmIsON == true and alarmforNextDay == false and (totalMilliTime - timeSnoozeClicked) > 10000 and (minTime * 60000 + hourTime * 3600000) >= alarmMillis) {
    playAlarm();
  }
}

void calcTime() {
  totalMilliTime = millis();
  //  totalSecTime = totalMilliTime / 1000;
  //  totalMinTime = totalSecTime / 60;
  //  totalHourTime = totalMinTime / 60;
  secTime = ((totalMilliTime + offsetMilliTime) / 1000) % 60;
  minTime = ((totalMilliTime + offsetMilliTime) / 60000) % 60;
  hourTime = ((totalMilliTime + offsetMilliTime) / 3600000) % 24;
}

void dispMinutes(uint32_t minutes) {
  selectDigit(1);
  dispDigit(minutes % 10);
  delay(digitPersistence);
  dispNothing();
  selectDigit(2);
  dispDigit((minutes / 10) % 10);
  delay(digitPersistence);
  dispNothing();
}

void dispHour(uint32_t hour) {
  selectDigit(3);
  dispDigit(hour % 10);
  delay(digitPersistence);
  dispNothing();
  selectDigit(4);
  dispDigit((hour / 10) % 10);
  delay(digitPersistence);
  dispNothing();
}


void dispNothing() {
  digitalWrite(segment_1, LOW);
  digitalWrite(segment_2, LOW);
  digitalWrite(segment_4, LOW);
  digitalWrite(segment_6, LOW);
  digitalWrite(segment_7, LOW);
  digitalWrite(segment_9, LOW);
  digitalWrite(segment_10, LOW);
}

void dispDigit(int digit) {
  if (digit == 0) {
    //    Serial.println("0");
    digitalWrite(segment_1, HIGH);
    digitalWrite(segment_2, HIGH);
    digitalWrite(segment_4, HIGH);
    digitalWrite(segment_6, HIGH);
    digitalWrite(segment_7, HIGH);
    digitalWrite(segment_9, HIGH);
    digitalWrite(segment_10, LOW);
  }

  if (digit == 1) {
    //    Serial.println("1");
    digitalWrite(segment_1, LOW);
    digitalWrite(segment_2, LOW);
    digitalWrite(segment_4, HIGH);
    digitalWrite(segment_6, HIGH);
    digitalWrite(segment_7, LOW);
    digitalWrite(segment_9, LOW);
    digitalWrite(segment_10, LOW);
  }

  if (digit == 2) {
    //    Serial.println("2");
    digitalWrite(segment_1, HIGH);
    digitalWrite(segment_2, HIGH);
    digitalWrite(segment_4, LOW);
    digitalWrite(segment_6, HIGH);
    digitalWrite(segment_7, HIGH);
    digitalWrite(segment_9, LOW);
    digitalWrite(segment_10, HIGH);
  }

  if (digit == 3) {
    //    Serial.println("3");
    digitalWrite(segment_1, LOW);
    digitalWrite(segment_2, HIGH);
    digitalWrite(segment_4, HIGH);
    digitalWrite(segment_6, HIGH);
    digitalWrite(segment_7, HIGH);
    digitalWrite(segment_9, LOW);
    digitalWrite(segment_10, HIGH);
  }

  if (digit == 4) {
    //    Serial.println("4");
    digitalWrite(segment_1, LOW);
    digitalWrite(segment_2, LOW);
    digitalWrite(segment_4, HIGH);
    digitalWrite(segment_6, HIGH);
    digitalWrite(segment_7, LOW);
    digitalWrite(segment_9, HIGH);
    digitalWrite(segment_10, HIGH);
  }

  if (digit == 5) {
    //    Serial.println("5");
    digitalWrite(segment_1, LOW);
    digitalWrite(segment_2, HIGH);
    digitalWrite(segment_4, HIGH);
    digitalWrite(segment_6, LOW);
    digitalWrite(segment_7, HIGH);
    digitalWrite(segment_9, HIGH);
    digitalWrite(segment_10, HIGH);
  }

  if (digit == 6) {
    //   Serial.println("6");
    digitalWrite(segment_1, HIGH);
    digitalWrite(segment_2, HIGH);
    digitalWrite(segment_4, HIGH);
    digitalWrite(segment_6, LOW);
    digitalWrite(segment_7, HIGH);
    digitalWrite(segment_9, HIGH);
    digitalWrite(segment_10, HIGH);
  }

  if (digit == 7) {
    //    Serial.println("7");
    digitalWrite(segment_1, LOW);
    digitalWrite(segment_2, LOW);
    digitalWrite(segment_4, HIGH);
    digitalWrite(segment_6, HIGH);
    digitalWrite(segment_7, HIGH);
    digitalWrite(segment_9, LOW);
    digitalWrite(segment_10, LOW);
  }

  if (digit == 8) {
    //    Serial.println("8");
    digitalWrite(segment_1, HIGH);
    digitalWrite(segment_2, HIGH);
    digitalWrite(segment_4, HIGH);
    digitalWrite(segment_6, HIGH);
    digitalWrite(segment_7, HIGH);
    digitalWrite(segment_9, HIGH);
    digitalWrite(segment_10, HIGH);
  }

  if (digit == 9) {
    //    Serial.println("9");
    digitalWrite(segment_1, LOW);
    digitalWrite(segment_2, HIGH);
    digitalWrite(segment_4, HIGH);
    digitalWrite(segment_6, HIGH);
    digitalWrite(segment_7, HIGH);
    digitalWrite(segment_9, HIGH);
    digitalWrite(segment_10, HIGH);
  }

}

// void dispSong() {
  // selectDigit(1);
  // digitalWrite(segment_1, LOW);
  // digitalWrite(segment_2, HIGH);
  // digitalWrite(segment_4, HIGH);
  // digitalWrite(segment_6, HIGH);
  // digitalWrite(segment_7, HIGH);
  // digitalWrite(segment_9, HIGH);
  // digitalWrite(segment_10, HIGH);
  // delay(digitPersistence);

  // selectDigit(2);
  // digitalWrite(segment_1, HIGH);
  // digitalWrite(segment_2, LOW);
  // digitalWrite(segment_4, HIGH);
  // digitalWrite(segment_6, LOW);
  // digitalWrite(segment_7, LOW);
  // digitalWrite(segment_9, LOW);
  // digitalWrite(segment_10, HIGH);
  // delay(digitPersistence);

  // selectDigit(3);
  // digitalWrite(segment_1, HIGH);
  // digitalWrite(segment_2, HIGH);
  // digitalWrite(segment_4, HIGH);
  // digitalWrite(segment_6, HIGH);
  // digitalWrite(segment_7, HIGH);
  // digitalWrite(segment_9, HIGH);
  // digitalWrite(segment_10, LOW);
  // delay(digitPersistence);

  // selectDigit(4);
  // digitalWrite(segment_1, LOW);
  // digitalWrite(segment_2, HIGH);
  // digitalWrite(segment_4, HIGH);
  // digitalWrite(segment_6, LOW);
  // digitalWrite(segment_7, HIGH);
  // digitalWrite(segment_9, HIGH);
  // digitalWrite(segment_10, HIGH);
  // delay(digitPersistence);
// }

void selectDigit(int digit) {
  if (digit == 1) {
    //    Serial.println("digit 1");
    digitalWrite(digitBit_1, LOW);
    digitalWrite(digitBit_2, LOW);
  }

  if (digit == 2) {
    //    Serial.println("digit 2");
    digitalWrite(digitBit_1, HIGH);
    digitalWrite(digitBit_2, LOW);
  }

  if (digit == 3) {
    //    Serial.println("digit 3");
    digitalWrite(digitBit_1, LOW);
    digitalWrite(digitBit_2, HIGH);
  }

  if (digit == 4) {
    //    Serial.println("digit 4");
    digitalWrite(digitBit_1, HIGH);
    digitalWrite(digitBit_2, HIGH);
  }
}

void selectTime() {
  uint32_t timeLastActive = BtnSetClockTimeClicked + 1000;
  uint16_t unactiveTime;
  boolean changeMinutes = true;
  boolean changeHour = false;
  analogWrite(dubbelPuntLED, 0);


  while (unactiveTime < 5000) {
    Serial.println("Change time mode");
    offsetSecTime = offsetMilliTime / 1000;
    offsetMinTime = offsetSecTime / 60;
    offsetHourTime = offsetMinTime / 60;
    calcTime();
    Serial.println(String(hourTime) + " : " + String(minTime) + " : " + String(secTime) + " : " + String(totalMilliTime));
    unactiveTime = totalMilliTime - timeLastActive;

    if ((unactiveTime / 500) % 2 == 0) {
      if (changeMinutes == true) {
        dispMinutes(minTime);
      }
      if (changeHour == true) {
        dispHour(hourTime);
      }
    } else {
      dispNothing();
      delay(2 * digitPersistence);
    }
    if (changeMinutes == true) {
      dispHour(hourTime);
    }
    if (changeHour == true) {
      dispMinutes(minTime);
    }

    if (digitalRead(BtnUp) == HIGH and BtnUpON == false) {
      BtnUpON = true;
      timeLastActive = millis();

      if (changeMinutes == true) {
        if (minTime == 59) {
          offsetMilliTime -= 3540000;
        } else {
          offsetMilliTime += 60000;
        }


        /*
          if (offsetMilliTime % 3600000 == 0) {
          offsetMilliTime -= 3600000;
          }
        */
      }
      if (changeHour == true) {
        if (hourTime == 23) {
          offsetMilliTime -= 82800000;
        } else {
          offsetMilliTime += 3600000;
        }

        /*
          if ((offsetMilliTime / 3600000) % 24 == 0) {
          offsetMilliTime -= 86400000;
          }
        */
      }
    }
    if (digitalRead(BtnUp) == LOW and BtnUpON == true) {
      BtnUpON = false;
    }

    if (digitalRead(BtnDown) == HIGH and BtnDownON == false) {
      BtnDownON = true;
      timeLastActive = millis();

      if (changeMinutes == true) {
        if (minTime == 0) {
          offsetMilliTime += 3540000;
        } else {
          offsetMilliTime -= 60000;
        }


        /*
          if ((offsetMilliTime + 60000) % 3600000 == 0) {
          offsetMilliTime += 3600000;
          }
        */
      }
      if (changeHour == true) {
        if (hourTime == 0) {
          offsetMilliTime += 82800000;
        } else {
          offsetMilliTime -= 3600000;
        }


        /*
          if (((offsetMilliTime + 3600000) / 3600000) % 24 == 0) {
          offsetMilliTime += 86400000;
          }
        */
      }
    }
    if (digitalRead(BtnDown) == LOW and BtnDownON == true) {
      BtnDownON = false;
    }

    if (digitalRead(BtnSetClock) == HIGH and BtnSetClockON == false) {
      timeLastActive = millis();
      BtnSetClockON = true;
      if (changeMinutes == true) {
        changeMinutes = false;
        changeHour = true;
      } else {
        BtnSetClockON = false;
        break;
      }
    }
    if (digitalRead(BtnSetClock) == LOW and BtnSetClockON == true) {
      BtnSetClockON = false;
    }
  }
}

void selectAlarm() {
  uint32_t timeLastActive = millis();
  uint16_t unactiveTime;
  boolean changeMinutes = true;
  boolean changeHour = false;
  // boolean changeAlarmSound = false;
  boolean canExit = false;

  while (unactiveTime < 5000) {
    Serial.println("Change alarm time mode");
    alarmSeconds = alarmMillis / 1000;
    alarmMinutes = alarmSeconds / 60;
    alarmHours = alarmMinutes / 60;
    Serial.println(String(alarmHours) + " : " + String(alarmMinutes) + " : " + String(alarmSeconds) + " : " + String(alarmMillis));
    unactiveTime = millis() - timeLastActive;

    if ((unactiveTime / 500) % 2 == 0) {
      if (changeMinutes == true) {
        dispMinutes(alarmMinutes % 60);
      }
      if (changeHour == true) {
        dispHour(alarmHours % 24);
      }
      // if (changeAlarmSound == true) {
        // dispMinutes(alarmSoundSelected);
        // dispNothing();
        // delay(2 * digitPersistence);
      // }
    } else {
      // if (changeAlarmSound == true) {
        // dispSong();
      // } else {
        dispNothing();
        delay(2 * digitPersistence);
      // }
    }
    if (changeMinutes == true) {
      dispHour(alarmHours % 24);
    }
    if (changeHour == true) {
      dispMinutes(alarmMinutes % 60);
    }

    if (digitalRead(BtnUp) == HIGH and BtnUpON == false) {
      BtnUpON = true;
      timeLastActive = millis();

      if (changeMinutes == true) {
        alarmMillis += 60000;
        if (alarmMillis % 3600000 == 0) {
          alarmMillis -= 3600000;
        }
      }
      if (changeHour == true) {
        alarmMillis += 3600000;
        if ((alarmMillis / 3600000) % 24 == 0) {
          alarmMillis -= 86400000;
        }
      }
      // if (changeAlarmSound == true) {
        // alarmSoundSelected++;
        // if (alarmSoundSelected > 2) {
          // alarmSoundSelected = 1;
        // }
      // }
    }
    if (digitalRead(BtnUp) == LOW and BtnUpON == true) {
      BtnUpON = false;
    }

    if (digitalRead(BtnDown) == HIGH and BtnDownON == false) {
      BtnDownON = true;
      timeLastActive = millis();

      if (changeMinutes == true) {
        alarmMillis -= 60000;
        if ((alarmMillis + 60000) % 3600000 == 0) {
          alarmMillis += 3600000;
        }
      }
      if (changeHour == true) {
        alarmMillis -= 3600000;
        if (((alarmMillis + 3600000) / 3600000) % 24 == 0) {
          alarmMillis += 86400000;
        }
      }
      // if (changeAlarmSound == true) {
        // alarmSoundSelected--;
        // if (alarmSoundSelected < 1) {
          // alarmSoundSelected = 2;
        // }
      // }
    }
    if (digitalRead(BtnDown) == LOW and BtnDownON == true) {
      BtnDownON = false;
    }

    if (digitalRead(BtnSetAlarm) == HIGH and BtnSetAlarmON == false) {
      timeLastActive = millis();
      BtnSetAlarmON = true;
      if (changeMinutes == true) {
        changeMinutes = false;
        changeHour = true;
      } else if (changeHour == true) {
        changeHour = false;
        // changeAlarmSound = true;
      // } else {
        alarmIsON = true;
        canExit = true;
        if ((minTime * 60000 + hourTime * 3600000) >= alarmMillis) {
          alarmforNextDay = true;
        }
      }
    }
    if (digitalRead(BtnSetAlarm) == LOW and BtnSetAlarmON == true) {
      BtnSetAlarmON = false;
      if (canExit == true) {
        break;
      }
    }
  }
}

void showAlarm() {
  uint32_t timeLastActive = millis();
  uint16_t unactiveTime;
  analogWrite(dubbelPuntLED, 10);

  while (unactiveTime < 5000) {
    unactiveTime = millis() - timeLastActive;
    dispMinutes(alarmMinutes % 60);
    dispHour(alarmHours % 24);
    if (digitalRead(BtnSetAlarm) == HIGH and BtnSetAlarmON == false) {
      BtnSetAlarmON = true;
    }

    if (digitalRead(BtnSetAlarm) == HIGH and BtnSetAlarmON == true and (millis() - timeLastActive) > 1000) {
      alarmforNextDay = false;
      selectAlarm();
      break;
    }

    if (digitalRead(BtnSetAlarm) == LOW and BtnSetAlarmON == true) {
      BtnSetAlarmON = false;
      break;
    }
  }
}

// maximum frequency is 1670 Hz
void playAlarm() {
  // if (millis() >= timeUntillNextNote) {
    // if (alarmSoundSelected == 1) {
      // char* currentNote = song1_notes[songLine];
      // float currentFreq = getFrequency(currentNote);
      // Serial.print("song1: ");
      // Serial.println(currentNote);
      // analogWrite(alarmSound, round(-3.366 * pow(10, -10) * pow(currentFreq, 3) + 1.344 * pow(10, -5) * pow(currentFreq, 2) + 0.1313 * currentFreq - 0.304));
      // timeUntillNextNote = millis() + 1000 / song1_noteLenght[songLine] * 1.3;
      // timeUntillSpeakerOff = millis() + 1000 / song1_noteLenght[songLine] * 1.29;
      // timeUntillSpeakerON = millis() + 1000 / song1_noteLenght[songLine] * 0.3;
      // if (songLine < sizeof(song1_notes) / 2 - 1) {
        // songLine++;
      // } else {
        // songLine = 0;
      // }
    // }
    // if (alarmSoundSelected == 2) {
      // char* currentNote = song2_notes[songLine];
      // float currentFreq = getFrequency(currentNote);
      // Serial.print("song2: ");
      // Serial.println(currentNote);
      // analogWrite(alarmSound, round(-3.366 * pow(10, -10) * pow(currentFreq, 3) + 1.344 * pow(10, -5) * pow(currentFreq, 2) + 0.1313 * currentFreq - 0.304));
      // timeUntillNextNote = millis() + 1000 / song2_noteLenght[songLine] * 1.3;
      // timeUntillSpeakerOff = millis() + 1000 / song2_noteLenght[songLine] * 1.29;
      // timeUntillSpeakerON = millis() + 1000 / song2_noteLenght[songLine] * 0.3;
      // if (songLine < sizeof(song2_notes) / 2 - 1) {
        // songLine++;
      // } else {
        // songLine = 0;
      // }
    // }
  // }
  // if (millis() >= timeUntillSpeakerON) {
    // digitalWrite(speakerON, HIGH);
  // }
  // if (millis() >= timeUntillSpeakerOff) {
    // digitalWrite(speakerON, LOW);
  // }
  
  tone(alarmSound, 1000);
}

// float getFrequency(char* note) {
  // for (int x = 0; x < sizeof(Notes) / 2; x++) {
    // if (strcmp(note, Notes[x]) == 0) {
      // return noteFreq[x];
    // }
  // }
  // return 0;
// }





