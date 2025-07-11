void BeginRobot() {
  pinMode(13, INPUT_PULLUP);
  for (int i = 2; i < 8; i++) {
    pinMode(i, OUTPUT);
  }

  Bz(80);
  delay(50);
  Bz(80);
}

void Go() {
  while (analogRead(A6) < 512) {
    MotorStop();
  }
  Bz(100);
}

void Bz(int time) {
  digitalWrite(8, 1);
  delay(time);
  digitalWrite(8, 0);
  delay(10);
}