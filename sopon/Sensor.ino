#include <Adafruit_MCP3008.h>
Adafruit_MCP3008 adc;

void ReadSensor() {  //ค่าดิบ
  for (int _sensor = 0; _sensor < NUM_SENSORS; _sensor++) {
    adc.begin(13, 11, 12, 10);
    F[_sensor] = adc.readADC(_sensor);
  }
}

void ReadCalibrate() {  //ค่าที่ Calibrate แล้ว
  ReadSensor();
  for (int i = 0; i < NUM_SENSORS; i++) {
    unsigned int calmin, calmax;
    long x = 0;
    calmin = MinValue[i];
    calmax = MaxValue[i];
    x = map(F[i], calmin, calmax,1000,0);       //สลับค่าสนาม เส้นดำ   0,1000       เส้นขาว  1000,0
    if (x < 0) x = 0;
    if (x > 1000) x = 1000;
    F[i] = x;
  }
}

void CalibrateSensor(int pauseTime, int samples) {
  for (int i = 0; i < NUM_SENSORS; i++) {
    MinValue[i] = 1023;
    MaxValue[i] = 0;
  }
  for (int startSamp = 0; startSamp <= samples; startSamp++) {
    ReadSensor();
    for (int i = 0; i < NUM_SENSORS; i++) {
      MinValue[i] = (F[i] <= MinValue[i] ? F[i] : MinValue[i]);
      MaxValue[i] = (F[i] >= MaxValue[i] ? F[i] : MaxValue[i]);
    }
    delay(pauseTime);
  }
}

void ShowCalibrate() {  // Calibrate ค่าแสง
  Serial.println("Press OK to Start Calibrate Sensor");
  Go();
  Serial.println("Calibrating...");
  Bz(50);
  CalibrateSensor(25, 250);
  Bz(50);
  Serial.println("Finish");
  Serial.println("  ");
  Bz(100);
  Serial.print("int MinValue[NUM_SENSORS] = {");
  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(MinValue[i]);
    if (i < NUM_SENSORS - 1) Serial.print(",");
    else Serial.println("};");
  }

  Serial.print("int MaxValue[NUM_SENSORS] = {");
  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(MaxValue[i]);
    if (i < NUM_SENSORS - 1) Serial.print(",");
    else Serial.println("};");
  }
  while (1)
    ;
}

void SerialF() {
  while (1) {
    ReadSensor();
    for (int _serialF = 0; _serialF < NUM_SENSORS; _serialF++) {
      Serial.print(F[_serialF]);
      Serial.print("\t");
    }
    Serial.println("");
  }
}

void AutoRef() {
  for (int i = 0; i < NUM_SENSORS; i++) {
    REF[i] = (MinValue[i] + MaxValue[i]) / 2;
  }
}
