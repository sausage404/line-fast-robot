#include <SPACE01.h>

#define NUM_SENSORS 8  //จำนวนเซนเซอร์
uint8_t F_PIN[NUM_SENSORS] = { 0, 1, 2, 3, 4, 5, 6, 7 };
int F[NUM_SENSORS];
int REF[NUM_SENSORS];
int LastError;
///////////////////////////////////////////////////////////////////////////
int MinValue[NUM_SENSORS] = {39,40,44,47,39,43,41,38};
int MaxValue[NUM_SENSORS] = {797,904,941,951,866,933,896,856};
///////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(115200);
  pinMode(PH1, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(PH2, OUTPUT);
  pinMode(EN2, OUTPUT);
  //RobotSetup();  // Setup บอร์ดหุ่นยนต์
  OK();  // รอจนกว่าจะกดปุ่ม OK
  //AutoRef();
  MotorStop();
  delay(500);
  //SerialF();
  //ShowCalibrate();
  // Motor(20,20);delay(500);
  // TrackTime(50, 0.028, 0.31, 35000);
  // TrackTime(30, 0.04, 0.4, 6000);

  // TrackTime(35, 0.1, 0.9, 22000);
  // TrackTime(35, 0.09, 0.03, 2000);
  // TrackTime(35, 0.1, 0.9, 10000);

  //  TrackTime(100, 0.04, 0.2, 400); //ออกตัว
  //TrackTime(85, 0.09109, 0.55, 20500); จบ 18.74วิ 83เปอ
  //TrackTime(80, 0.25, 0.8, 9800);  // จบ 18.15วิ 81เปอ
   //TrackTime(80, 0.11, 0.42, 10500);  // จบ 18.15วิ 81เปอ
  //TrackTime(85, 0.1088, 0.59, 20500);// จุดตัด
  //TrackTime(85, 0.0905, 0.556, 20500);// จบ ล่าสุด 09/0
  //TrackTime(90, 0.15718, 0.5507, 20500);
  //TrackTime(100, 0.14, 0.55, 20500);
  //TrackTime(80, 0.096702, 0.55, 20500); //ยังไม่จบครูธง
  //TrackTime(80, 0.096703, 0.5501, 20500); //จบ 19.64วิ
  //TrackTime(80, 0.0959482149, 0.45945, 20500);
  TrackTime(71, 0.095939016, 0.45947, 23500); //วิ่งจบพลัง70 วิ่งสนามโรงเรียน 22.42วิ ล้อเขียว
  //TrackTime(75, 0.095, 0.4, 20500); //พลัง 75 ล้อเขียว
  //TrackTime(90, 0.157, 0.55, 20500);
  // TrackTime(35, 0.07, 0.2, 1000);

//TrackTime(85, 0.1015, 0.4295, 25000);
//TrackTime(60, 0.07, 0.55, 24000);
  /*
TrackCross(50 , 0.04 , 0.9, 'l');
TrackTime(100, 0.02, 0.2, 300);

TrackCross(50 , 0.04 , 0.9, 'l');
TrackTime(100, 0.02, 0.2, 400);

TrackCross(40 , 0.04 , 0.9, 'r');
TrackCross(50 , 0.04 , 0.9, 'p');
Motor(50, 50); delay(75);
*/


  MotorStop();
}

void loop() {
  MotorStop();
}
