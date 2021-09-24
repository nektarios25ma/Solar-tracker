
//n attempt to calculate the yaw angle right from servo write
#include <Servo.h> // include Servo library 




// 180 horizontal MAX
Servo horizontal; // horizontal servo
int servoh = 90;   // 90;     // stand horizontal servo

int servohLimitHigh = 180;
int servohLimitLow = 1;

// 180 degrees MAX
Servo vertical;   // vertical servo 
int servov = 90;    //   110;     // stand vertical servo

int servovLimitHigh = 165;
int servovLimitLow = 25;

float yaw;
float ANGLEY;
// LDR pin connections
//  name  = analogpin;
int ldrlt =A0; //LDR top left - BOTTOM LEFT    <--- BDG
int ldrrt =A1; //LDR top right - BOTTOM RIGHT 
int ldrld =A2; //LDR down left - TOP LEFT
int ldrrd =A3; //ldr down right - TOP RIGHT

void setup()
{
  Serial.begin(9600);
    horizontal.attach(5); 
  vertical.attach(6);
  horizontal.write(180);
  vertical.write(70);
   horizontal.write(servoh);
   delay(10000);
  
// servo connections
// name.attacht(pin);
//  horizontal.attach(5); 
//  vertical.attach(6);
  horizontal.write(40);
  vertical.write(90);
 //  horizontal.write(servoh);
  delay(5000);
  
}

void loop() 
{
 
  
  int lt = analogRead(ldrlt); // top left
  int rt = analogRead(ldrrt); // top right
  int ld = analogRead(ldrld); // down left
  int rd = analogRead(ldrrd); // down rigt
  
  // int dtime = analogRead(4)/20; // read potentiometers  
  // int tol = analogRead(5)/4;
  int dtime = 16;
  int tol = 35;
  
  int avt = (lt + rt) / 2; // average value top
  int avd = (ld + rd) / 2; // average value down
  int avl = (lt + ld) / 2; // average value left
  int avr = (rt + rd) / 2; // average value right

  int dvert = avt - avd; // check the diffirence of up and down
  int dhoriz = avl - avr;// check the diffirence og left and rigt
  
  
// Serial.print(lt);
// Serial.print(" ");
// Serial.print(rt);
// Serial.print(" ");
//  Serial.print(ld);
//  Serial.print(" ");
// Serial.println(rd);
 yaw=map(servoh,1,180,-90,90);
ANGLEY=map(servov,1,180,158,-22);
 // Serial.print("angleX : ");
  Serial.print("SUNAzimuth : ");
  Serial.print(180-yaw);
 // Serial.print(mpu6050.getAngleX());
 // Serial.print("\tangleY : ");
Serial.print("  SUNAltitude : ");
 Serial.println(ANGLEY);
 // Serial.print("\tangleZ : ");
 // Serial.println(ANGLEZ);
 // Serial.print("   ");
 // Serial.print(avt);
 // Serial.print("   ");
 // Serial.print(avd);
 // Serial.println(" ");
 // Serial.print(avt);
 // Serial.print("   ");
  //Serial.print(avd);
  //Serial.println(" ");
  
    
  if (-1*tol > dvert || dvert > tol) // check if the diffirence is in the tolerance else change vertical angle
  {
  if (avt > avd)
  {
  servov= --servov;
    if (servov < servovLimitLow)
  {
    servov = servovLimitLow;
  }  
  }
  else if (avt < avd)
  {
    servov = ++servov;
     if (servov > servovLimitHigh) 
     { 
      servov = servovLimitHigh;
     }
    delay(dtime);
  }
  vertical.write(servov);
 // horizontal.write(servoh);
  }
  
  if (-1*tol > dhoriz || dhoriz > tol) // check if the diffirence is in the tolerance else change horizontal angle
  {
  if (avr > avl)
  {
   servoh = ++servoh;
     if (servoh > servohLimitHigh)
     {
     servoh = servohLimitHigh;
     }
  }
  else if (avr < avl)
  {
     servoh = --servoh;
    if (servoh < servohLimitLow)
    {
    servoh = servohLimitLow;
    }
   delay(dtime); 
  }
  else if (avl = avr)
  {
    // nothing
  }
  horizontal.write(servoh);
  }
   delay(dtime);

}
