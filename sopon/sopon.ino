#define NUM_SENSORS 8  //จำนวนเซนเซอร์
uint8_t F_PIN[NUM_SENSORS] = { 0, 1, 2, 3, 4, 5, 6, 7 };
int F[NUM_SENSORS];
int REF[NUM_SENSORS];
int LastError;

///////////////////////////////////////////////////////////////////////////
int MinValue[NUM_SENSORS] = {84,45,45,39,33,47,49,50};
int MaxValue[NUM_SENSORS] = {909,762,702,838,585,753,810,794};
///////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(9600);
  BeginRobot();
  Go();
  delay(500);
  // ShowCalibrate();

  // TrackTime(100, 0.05, 0.35, 350);

  // TrackTime(65, 0.148, 0.42, 20000);
  // TrackTime(60, 0.147, 0.4, 20000);
  // TrackTime(55, 0.146, 0.4, 20000);
  TrackTime(40, 0.15, 0.41, 35000); //23
  // TrackTime(50, 0.15, 0.4, 35000); //23

  // TrackTime(50, 0.145, 0.4, 12000); //22
  // TrackTime(65, 0.155, 0.6, 20500);

  // TrackTime(50, 0.145, 0.4, 12000);
  // TrackTime(65, 0.155, 0.6, 20500);

  MotorShot();
}

void loop() {
  STOP();
}

//TrackTime(65 , 0.047 , 1, 30000);
//TrackCross(65 , 0.047 , 1, 'p');
//TrackCross(65 , 0.047 , 1, 'l');
//TrackCross(65 , 0.047 , 1, 'r');
//TrackCross(65 , 0.047 , 1, 's');