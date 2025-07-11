#define PWMA 5
#define AIN1 2
#define AIN2 3

#define PWMB 6
#define BIN1 4
#define BIN2 7


void Motor1(int speedmotor1) {
  bool dir1 = (speedmotor1 >= 0 ? true : false);
  speedmotor1 = abs(speedmotor1);
  if (speedmotor1 > 255) {
    speedmotor1 = 255;
  }
  digitalWrite(AIN1, !dir1);
  digitalWrite(AIN2, dir1);
  analogWrite(PWMA, speedmotor1);
}

void Motor2(int speedmotor2) {
  bool dir2 = (speedmotor2 >= 0 ? true : false);
  speedmotor2 = abs(speedmotor2);
  if (speedmotor2 > 255) {
    speedmotor2 = 255;
  }
  digitalWrite(BIN1, !dir2);
  digitalWrite(BIN2, dir2);
  analogWrite(PWMB, speedmotor2);
}

void Motor(int leftsp, int rightsp) {
  Motor1(leftsp);
  Motor2(rightsp);
}

void MotorStop() {
  Motor(0, 0);
}

void STOP() {
  while (analogRead(A6) < 512) {
    MotorShot();
  }
  Bz(100);
}

void MotorShot() {
  digitalWrite(AIN1, 1);
  digitalWrite(AIN2, 1);
  analogWrite(PWMA, 255);
  digitalWrite(BIN1, 1);
  digitalWrite(BIN2, 1);
  analogWrite(PWMB, 255);
}