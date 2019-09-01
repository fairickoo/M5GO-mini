#include <M5Stack.h>
const unsigned int GRAY = M5.Lcd.color565(157,148,148);
const unsigned int GREENTYPE = M5.Lcd.color565(7,235,235);
//*******
void index();
void passA(int n);
void passC(int n);
void menu();
void password();
void inputPass(int m);
void eror();
//*******
int stateindex=0;
int onindex=0;
int statePWA=0;
int statePWB=0;
int statePWC=0;
int on=0;
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
  }
void error(){
     M5.Lcd.fillScreen(PINK);
  }
void inputPass(int m){
      if(m==1&&M5.BtnB.wasPressed()){
          on=1;
          statePWB=1;
          M5.Lcd.setTextColor(WHITE);
          M5.Lcd.setCursor(80,53);
          M5.Lcd.setTextSize(3);
          M5.Lcd.print("*");
          Serial.println("CH1");
        }
         if(statePWB==1&&M5.BtnC.wasPressed()){
            M5.Lcd.setTextColor(WHITE);
            M5.Lcd.setCursor(120,53);
            M5.Lcd.setTextSize(3);
            M5.Lcd.print("*");
            Serial.println("CH2");
            statePWA=1;
         }
      
         if(statePWA==1&&M5.BtnA.wasPressed()){
              M5.Lcd.setTextColor(WHITE);
              M5.Lcd.setCursor(170,53);
              M5.Lcd.setTextSize(3);
              M5.Lcd.print("*");
              Serial.println("CH3");
              statePWC=1;
          }
        
      if(statePWC==1&&M5.BtnC.wasPressed()){
              M5.Lcd.setTextColor(WHITE);
              M5.Lcd.setCursor(210,53);
              M5.Lcd.setTextSize(3);
              M5.Lcd.print("*");
              Serial.println("CH4");
              passA(3);
          }
      
        
}
void passA(int n){
  switch (n)
  {
  case 1 : password();break;
  case 2 : index();break;
  case 3 : menu();break;
  case 4 : error(); break;
  }
}
void setup() {
  M5.begin();
 index();
}

void loop() {
      if (M5.BtnA.wasPressed()&&on==0){
        stateindex++;
        Serial.print(stateindex);
        passA(stateindex);
        if(stateindex==2){
           stateindex=0;
        }
      }
        inputPass( stateindex);
      M5.update();
}