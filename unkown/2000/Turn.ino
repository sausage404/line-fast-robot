void TurnLeft() { // เลี้ยวซ้าย
  //Motor(50, 50); delay(10);
  Motor(-60, 60); delay(30);
  while (1) {
    Motor(-45, 45);
    ReadCalibrate();
    if (F[0] >= 350) {
      Motor(45, -45); delay(5);
      MotorStop();
      break;
    }
  }
}

void TurnRight() { // เลี้ยวขวา
 // Motor(50, 50); delay(10);
  Motor(60, -60); delay(30);
  while (1) {
    Motor(45, -45);
    ReadCalibrate();
    if (F[7] >= 350) {
      Motor(-45, 45); delay(5);
      MotorStop();
      break;
    }
  }
}
