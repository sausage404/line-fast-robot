void TurnLeft() { // เลี้ยวซ้าย
Motor(70, 70); delay(90);
Motor(150, -150); delay(50);
  while (1) {
    Motor(150, -150);
    ReadCalibrate();
    if (F[1] >= 400) {
      Motor(-150,150); delay(5);
      MotorStop();
      break;
    }
  }
}
void TurnRight() { // เลี้ยวขวา
Motor(70, 70); delay(90);
Motor(-150, 150); delay(50);
  while (1) {
    Motor(-150,150);
    ReadCalibrate();
    if (F[6] >= 400) {
      Motor(150,-150); delay(5);
      MotorStop();
      break;
    }
  }
}
