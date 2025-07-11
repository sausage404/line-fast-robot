#include <SPACE01.h>

#define NUM_SENSORS 8  //จำนวนเซนเซอร์
uint8_t F_PIN[NUM_SENSORS] = { 0, 1, 2, 3, 4, 5, 6, 7 };
int F[NUM_SENSORS];
int REF[NUM_SENSORS];
int LastError;
///////////////////////////////////////////////////////////////////////////
int MinValue[NUM_SENSORS] = {41,45,45,48,48,40,44,216};
int MaxValue[NUM_SENSORS] = {864,938,935,934,935,877,875,979};
///////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(115200);
  pinMode(PH1, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(PH2, OUTPUT);
  pinMode(EN2, OUTPUT);
  // RobotSetup();  // Setup บอร์ดหุ่นยนต์
  OK();  // รอจนกว่าจะกดปุ่ม OK
  //AutoRef();
  MotorStop();
  delay(500);
  // Motor(20, 20);delay(500);
  // SerialF();
  // ShowCalibrate();

  // TrackTime(40, 0.11, 1, 12000);

  // TrackTime(70, 0.12, 1.12, 20000);

  // TrackTime(71.5, 0.12, 1.13, 4200);
   TrackTime(50, 0.11, 0.45, 35000);


  // TrackTime(10.5, 0.14, 0.8, 35000);

  // เส้นโค้ง
  // TrackTime(50, 0.012, 0.12, 35000);
 // TrackTime(40, 0.049, 0.41, 25000);


  // TrackTime(51.5, 0.07, 0.4, 35000);

  // TrackCross(50 , 0.04 , 0.9, 'l');
  // TrackTime(100, 0.02, 0.2, 300);

  // TrackCross(50 , 0.04 , 0.9, 'l');
  // TrackTime(100, 0.02, 0.2, 400);

  // TrackCross(40 , 0.04 , 0.9, 'r');
  // TrackCross(50 , 0.04 , 0.9, 'p');
  // Motor(50, 50); delay(75);


  MotorStop();
}

void loop() {
  MotorStop();
}
