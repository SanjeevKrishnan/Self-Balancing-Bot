#include <MPU9250.h>
#define kp 4
#define kd 8
#define m 4
#define c 5

#define ki 0.0
MPU9250 IMU;

//float kp=30;
int vr=0;
int vl=0;
double t,sum=0;
float value;
double error=0;
double preverror=0;
double derivative=0;
double sumerror=0;
unsigned long sampletime=0;
unsigned long time1;


const int mr=3;
const int ml=4;
const int pwmr=5;
const int pwml=6;


int16_t gyro[3] = {0, 0, 0};
int16_t acc[3] = {0, 0, 0};
float gyroBias[3]  = {0, 0, 0};
float accelBias[3] = {0, 0, 0};
int dt;
unsigned long Time;

double x = 0.0, y = 0.0;
double cosine , sine;
double offset;
double angle = 0.00;
double angle2=0.00;
double currentAngle=0.00;

void setup(){
  pinMode(mr, OUTPUT);
 pinMode(ml, OUTPUT);
 pinMode(pwmr, OUTPUT);
 pinMode(pwml, OUTPUT);
   //IMU.calibrateMPU9250(gyroBias,accelBias);
  Serial.begin(115200);
 for(int i=0;i<10000;i++)
 {
   IMU.readGyroData(gyro);
   sum+=gyro[1]; 
 }
 gyroBias[1]=sum/10000;
 analogWrite(vr,0);
 analogWrite(vl,0);
 delay(1000);
}
double errorAng;
double tilt=0.0;

void loop(){
gyroreading();
errorAng=angle-tilt;  
//if(vr>60)
//{
//  sumerror=0;  
//}
//if (angle <5.00)
//{
  //if(angle<0)
  if(errorAng<0)
   {
    errorcalc(-errorAng*0.7);
     backward();
   }
  else if(errorAng>0)
   {errorcalc(errorAng*0.7);
  forward();}
  //Serial.print("backward");
//}

///if(angle<15.00 && angle>10.00)
//{
//  errorcalc(angle*0.7);
//  forward();
//  Serial.println("forward");
//  
//}
if(angle>0.15&&angle<0.25)
{
  vr=vl=100;
  forward();
}
}


void forward()
{
  gyroreading();
  digitalWrite(mr,HIGH);
  digitalWrite(ml,LOW);
  analogWrite(pwml,vl);
  analogWrite(pwmr,vr);
  gyroreading();
  
}

void backward()
{
  gyroreading();
  digitalWrite(mr,LOW);
  digitalWrite(ml,HIGH);
  analogWrite(pwml,vl);
  analogWrite(pwmr,vr);
  gyroreading();
}

void stopmotor()
{
  analogWrite(pwmr,0);
  analogWrite(pwml, 0);
}

void errorcalc(double angle1)
{
  gyroreading();
  sampletime=millis()-time1;
  sumerror+=angle1;
  derivative=angle1-preverror;
  vr=(angle1*kp+kd*derivative);
  vl=(angle1*kp+kd*derivative);
  preverror= angle1;
  time1=millis();
  gyroreading();
  
}
void gyroreading()
{
  IMU.readGyroData(gyro);
  //IMU.readAccelData(acc);
  
  dt = micros() - Time;
  angle+=(gyro[0]-gyroBias[0])*dt/131.0/1000000.0;
 // kp=m*angle+c;
  angle2=atan2(acc[1]-accelBias[1],acc[2]-accelBias[2])*180/3.14;
  //currentAngle=0.9934*(angle)+0.0066*(angle2);
  Time = micros();
//  Serial.println(angle2);
 Serial.print("angle");
  Serial.println(angle);
  Serial.print("pwm");
  Serial.println(vr);
Serial.println(angle2);


//Serial.println(offset);
}