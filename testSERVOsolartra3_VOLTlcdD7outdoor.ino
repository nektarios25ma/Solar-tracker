//n attempt to calculate the yaw angle right from servo write
#include <Servo.h> // include Servo library 
#include <U8g2lib.h>
#include <U8x8lib.h>
float azim =0;
char Azimuth [5];
char Altitude [5];
char Voltage [5];
const char DEGREE_SYMBOL[] = { 0xB0, '\0' };
U8G2_ST7920_128X64_1_HW_SPI u8g2(U8G2_R0, /* CS=*/ 10, /* reset=*/ 8);

// number of analog samples to take per reading
//#define NUM_SAMPLES 100
unsigned long start_time1; // Δημιούργησε μια μεταβλητή τύπου unsigned long integer με όνομα start_time
unsigned long start_time2; // Δημιούργησε μια μεταβλητή τύπου unsigned long integer με όνομα start_time

float voltage ;            // calculated voltage

// 180 horizontal MAX
Servo horizontal; // horizontal servo
int servoh = 90;   // 90;     // stand horizontal servo

int servohLimitHigh = 180;
int servohLimitLow = 1;

// 180 degrees MAX
Servo vertical;   // vertical servo 
int servov = 90;    //   110;     // stand vertical servo

int servovLimitHigh = 153;
int servovLimitLow = 39;

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
  // horizontal.write(servoh);
   delay(6000);
  
// servo connections
// name.attacht(pin);
//  horizontal.attach(5); 
//  vertical.attach(6);
 // horizontal.write(40);
 // vertical.write(90);
 //  horizontal.write(servoh);
 // delay(5000);
  u8g2.begin();
  u8g2.enableUTF8Print();             //u8g2.enableUTF8Print();
  u8g2.setFont(u8g2_font_helvB10_tf); //u8g2.setFont(u8g2_font_helvB10_tf); 
  u8g2.setColorIndex(1);
     
}

void loop() { 
  start_time1=millis();
   while (millis() - start_time1 <780) 
  {
 
  int lt = (analogRead(ldrlt)); // top left
  int rt = (analogRead(ldrrt)+82); // top right
  int ld = (analogRead(ldrld)+30); // down left
  int rd = (analogRead(ldrrd)+43); // down rigt
  
 // int lt = analogRead(ldrlt); // top left
 // int rt = analogRead(ldrrt); // top right
 // int ld = analogRead(ldrld); // down left
 // int rd = analogRead(ldrrd); // down rigt
  
  // int dtime = analogRead(4)/20; // read potentiometers  
  // int tol = analogRead(5)/4;
  int dtime = 219;   //16
  int tol = 15;//35 TO SUN LIGHT
  
  int avt = (lt + rt) / 2; // average value top
  int avd = (ld + rd) / 2; // average value down
  int avl = (lt + ld) / 2; // average value left
  int avr = (rt + rd) / 2; // average value right

  int dvert = avt - avd; // check the diffirence of up and down
  int dhoriz = avl - avr;// check the diffirence og left and rigt
  
    
  

  
      
  start_time2=millis();
   while (millis() - start_time2 < 500) 
  {  
  if (-1*tol > dvert || dvert > tol) // check if the diffirence is in the tolerance else change vertical angle
  {
  if (avt > avd)
  {
  servov= --servov;
    if (servov < servovLimitLow)
  {
    servov = servovLimitLow;
  }
  delay(dtime);  
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
     delay(dtime);
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
//delay(1);
//delay(956);
    }
    // Serial.print(lt);
// Serial.print(" ");
// Serial.print(rt);
// Serial.print(" ");
//  Serial.print(ld);
//  Serial.print(" ");
// Serial.println(rd);
 yaw=map(servoh,1,180,-80,100);   //yaw=map(servoh,1,180,-75,105);
 azim =180-yaw;
ANGLEY=(map(servov,1,180,158,-22))-4;
 
  voltage= analogRead(A5);
       
    // calculate the voltage
    // use 5.0 for a 5.0V ADC reference voltage
    // 5.015V is the calibrated reference voltage
    voltage = ((voltage * 5.015) / 1024.0);
    // send voltage for display on Serial Monitor
    // voltage multiplied by 11 when using voltage divider that
    // divides by 11. 11.132 is the calibrated voltage divide
   
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
  u8g2.firstPage();
  do {   
    draw();
  } while( u8g2.nextPage() );
}
 yaw=map(servoh,1,180,-80,100);   //yaw=map(servoh,1,180,-75,105);
 azim =180-yaw;
ANGLEY=(map(servov,1,180,158,-22))-4;
 // Serial.print("angleX : ");
 // Serial.print("SUNAzimuth : ");//--------------------------
  Serial.print(180-yaw);
 // Serial.print(mpu6050.getAngleX());
 // Serial.print("\tangleY : ");
//Serial.print("  SUNAltitude : ");//-----------------------------
Serial.print(",");
 Serial.print(ANGLEY);
 Serial.print(",");
  voltage= analogRead(A5);
       
    // calculate the voltage
    // use 5.0 for a 5.0V ADC reference voltage
    // 5.015V is the calibrated reference voltage
    voltage = ((voltage * 5.015) / 1024.0);
    // send voltage for display on Serial Monitor
    // voltage multiplied by 11 when using voltage divider that
    // divides by 11. 11.132 is the calibrated voltage divide
    // value
   
    Serial.println(voltage * 95.50);//σε deciVOLT
}

void draw() 
{
  u8g2.setFont(u8g2_font_helvB10_tf); 
   readAzimuth();
    u8g2.drawStr( 64, 13, Azimuth);   //u8g2.drawStr( 35, 28, Azimuth);
  u8g2.drawUTF8(102, 13, DEGREE_SYMBOL);
  readAltitude();
  readVoltage();
  u8g2.drawFrame(0,0,128,34);         
  u8g2.drawFrame(0,35,128,29);           
u8g2.drawStr( 4, 13, "Azimuth:");  //u8g2.drawStr( 15, 13, "Azimuth:"); 
  u8g2.drawStr( 64, 13, Azimuth);   //u8g2.drawStr( 35, 28, Azimuth);
  u8g2.drawUTF8(102, 13, DEGREE_SYMBOL);
u8g2.drawStr(8,30, "Altitude:");         
u8g2.drawStr( 69, 30, Altitude);
u8g2.drawUTF8(102, 30, DEGREE_SYMBOL); 
u8g2.drawStr( 64, 13, Azimuth);   //u8g2.drawStr( 35, 28, Azimuth);
  u8g2.drawUTF8(102, 13, DEGREE_SYMBOL);
   u8g2.setFont(u8g2_font_helvB08_tf); 
   u8g2.drawStr(1,49, "Voltage:");u8g2.drawStr(74,49, Voltage);u8g2.drawStr(105,49, "V");
  // u8g2.setFont(u8g2_font_helvB10_tf);  
  // u8g2.drawStr(0,62, "Nektarios Kourakis");
  u8g2.drawStr(4,62, "Nektarios Kourakis");
 u8g2.setFont(u8g2_font_helvB10_tf);
   u8g2.drawStr( 64, 13, Azimuth);   //u8g2.drawStr( 35, 28, Azimuth);
  u8g2.drawUTF8(102, 13, DEGREE_SYMBOL); 
//  u8g2.drawStr(30,46, "Altitude:");         
//  u8g2.drawStr( 37, 61, Altitude);
 //  u8g2.drawUTF8(75, 61, DEGREE_SYMBOL);
 // u8g2.drawStr(75,61, "%");   
}
void readAzimuth()
{
// float azim =180-yaw;
  dtostrf(azim, 3, 1, Azimuth);
}

void readAltitude()
{
//  float h == dht.readHumidity() ;
  dtostrf(ANGLEY, 3, 1, Altitude);
}
void readVoltage()
{
 // float t = dht.readTemperature();
  dtostrf((voltage * 9.55), 3, 1, Voltage);
}
