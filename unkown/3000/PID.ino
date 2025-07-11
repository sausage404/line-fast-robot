int readPosition(int Track, int noise) {  //อ่านค่า Position
  unsigned char i, online = 0;
  unsigned long avg = 0;
  unsigned int sum = 0;
  static int last_value = 0;
  ReadCalibrate();
  for (i = 0; i < NUM_SENSORS; i++) {
    int values = F[i];
    if (values > Track) {
      online = 1;
    }
    if (values > noise) {
      avg += (long)(values) * (i * 1000);
      sum += values;
    }
  }
  if (!online) {
    if (last_value < (NUM_SENSORS - 1) * 1000 / 2) {
      return 0;
    } else {
      return (NUM_SENSORS - 1) * 1000;
    }
  }
  last_value = avg / sum;
  return last_value;
}

void PID(int Speed, float Kp, float Kd) {  // คำสั่ง PID
  int Pos = readPosition(250, 50);
  int Error = Pos - 3500;
  int PID_Value = (Kp * Error) + (Kd * (Error - LastError));
  LastError = Error;
  int LeftPower = Speed + PID_Value;
  int RightPower = Speed - PID_Value;
  if (LeftPower > 100) LeftPower = 100;
  if (LeftPower < 0) LeftPower = -45; // -73.5
  if (RightPower > 100) RightPower = 100; // -73.5
  if (RightPower < 0) RightPower = -45;
  Motor(LeftPower, RightPower);
}

void TrackCross(int Speed, float Kp, float Kd, char select) {  // PID เช็คแยก
  while (1) {
    PID(Speed, Kp, Kd);
    ReadCalibrate();
    if (F[0] < 350 && F[7] < 350) {
      PID(Speed, Kp, Kd);
      ReadCalibrate();
    } else if (F[0] > 350 && F[1] > 350 && F[6] > 350 && F[7] > 350) {
      break;
    } /*else if (F[4] > 500 && F[5] > 500 && F[6] > 500 && F[7] > 500) {
    break;
  } else if (F[2] > 500 && F[3] < 500 && F[4] < 500 && F[5] > 500) {
    break;
  } else if (F[2] > 500 && F[3] > 500 && F[4] < 500 && F[5] > 500) {
    break;
  } else if (F[2] > 500 && F[3] < 500 && F[4] > 500 && F[5] > 500) {
    break;
  }*/
  }

  if (select == 's') {
    MotorStop();
  } else if (select == 'p') {
    Motor(Speed, Speed);
    delay(30);
  } else if (select == 'l') {
    ReadCalibrate();
    TurnLeft();
  } else if (select == 'r') {
    ReadCalibrate();
    TurnRight();
  }
}

void TrackTime(int Speed, float Kp, float Kd, int TotalTime) {  // Trackเส้นตามเวลาที่กำหนด
  unsigned long StartTime = millis();
  unsigned long EndTime = StartTime + TotalTime;
  while (millis() <= EndTime) {
    PID(Speed, Kp, Kd);
  }
}
