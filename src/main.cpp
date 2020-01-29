#include <M5Stack.h>
const unsigned int GRAY = M5.Lcd.color565(157,148,148);
const unsigned int GREENTYPE = M5.Lcd.color565(7,235,235);
//*******
void index();
void passA(int a);
void passB(int b);
void passC(int c);

void menu();
void password();
void inputPass();
void eror();
void CheckPass(int c);
//*******
int stateindex=0;
int onindex=0;
int statePWA=0;
int statePWB=0;
int statePWC=0;
int on=0,onA=0,onB=0,onC=0,onstate=0;
//*******
void index(){
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.fillCircle(270,190,120,GREENTYPE);
  M5.Lcd.fillCircle(140,180,20,GREENTYPE);
  M5.Lcd.fillCircle(210,75,20,GREENTYPE);
  M5.Lcd.fillCircle(250,130,10,GRAY);
  M5.Lcd.fillCircle(210,180,10,GRAY);
  M5.Lcd.setCursor(40,210);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(2);
  M5.Lcd.print("START");
  on=0;
  onA=0;
  onB=0;
  onC=0;
  onstate=0;
  stateindex=0;
  
}
void password(){
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.fillCircle(200,250,100,GREENTYPE);
  M5.Lcd.fillCircle(120,175,20,GREENTYPE);
  M5.Lcd.fillCircle(260,175,20,GREENTYPE);
  M5.Lcd.fillCircle(250,180,10,GRAY);
  M5.Lcd.fillCircle(210,180,10,GRAY);
  M5.Lcd.setCursor(45,210);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(2);
  M5.Lcd.print("BACK");
  M5.Lcd.setCursor(45,20);
  M5.Lcd.print("PASSWORD");
  M5.Lcd.drawRect(45,40,220,50,WHITE);
}
void menu(){
     M5.Lcd.fillScreen(YELLOW);
     Serial.print("menu complete");
  }
void error(){
     M5.Lcd.fillScreen(PINK);
  }
void inputPass(){
  if (stateindex!=0){
      if (M5.BtnB.wasPressed())
      { 
        onstate=1;
        onB++;
        if (onB==1){
          passB(onB);
        }
        else if (onB==2&&onC==1)
        { 
          onstate=2;
            //Serial.print(onstate);
          passB(onB);
          onB=0;
        }
        else
        {
          passA(2);
        }
        
      }
      if (M5.BtnC.wasPressed()&&onB==1)
      { 
        onC++;
        on=1;
        onstate=1;
        if (onC==1)
        {
          passC(onC);
        }
        else if (onC==2)
        {
          onC=0;
         passA(2);
        }
      }
      if (M5.BtnA.wasPressed()&&onstate==2)
      {
        onA=4;
        passA(onA);
      }
      if (M5.BtnC.wasPressed())
      {
        passA(2);
      }
  } 

}

void CheckPass(int c)
{

  switch (c)
  {
  case 1 : M5.Lcd.setTextColor(WHITE);
           M5.Lcd.setCursor(80,53);
           M5.Lcd.setTextSize(3);
           M5.Lcd.print("*");
          // Serial.println(on);
           
           M5.update();
           break;
  case 2 :  M5.Lcd.setTextColor(WHITE);
            M5.Lcd.setCursor(120,53);
            M5.Lcd.setTextSize(3);
            M5.Lcd.print("*");
            //Serial.println(on);
            
             M5.update();
            break;
  case 3 :  M5.Lcd.setTextColor(WHITE);
            M5.Lcd.setCursor(170,53);
            M5.Lcd.setTextSize(3);
            M5.Lcd.print("*");
            //Serial.println(on);
            
            M5.update();
            break;
  case 4 :  M5.Lcd.setTextColor(WHITE);
            M5.Lcd.setCursor(210,53);
            M5.Lcd.setTextSize(3);
            M5.Lcd.print("*");
            //Serial.println(on);
            passA(3);
            M5.update();
            break;
  }
}
void passA(int a){
  switch (a)
  {
  case 1 : password();break;
  case 2 : index();break;
  case 3 : menu();break;
  case 4 : //Serial.println("Button A Pressed 2");
          CheckPass(4);
          break;
  }
}

void passB(int b)
{
  switch (b)
  {
  case 1: //Serial.println("Button B Pressed");
          CheckPass(1);
          break;
  case 2: //Serial.println("Button B Pressed 2");
          CheckPass(3);
          break;
  }
}
void passC(int c)
{
  switch (c)
  {
  case 1: //Serial.println("Button C Pressed");
          CheckPass(2);
          break;
  }
}
void setup() {
  M5.begin();
 index();
}

void loop() {
      if (M5.BtnA.wasPressed()&&on==0){
        stateindex++;
        if (stateindex==1){
          Serial.println("passwprd");
          passA(stateindex);
        }
        else if(stateindex==2){
           Serial.println("index");
           passA(stateindex);
           stateindex=0;
        }
      }
      inputPass();
      M5.update();
}