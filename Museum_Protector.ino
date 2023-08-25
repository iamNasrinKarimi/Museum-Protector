#include <Keypad.h>  
#include <EEPROM.h>
#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD  

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 
byte mask = 1;
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);
////////////////////////////////////////value///////////////////////////////////
int flag=0;
int sec=0;
int change=0;
int a=EEPROM[33],b=EEPROM[34],c=EEPROM[35],d=EEPROM[36];
int key1=0,key2=0,key3=0,key4=0;
int keyflag=0;
int secchange=0;
int flagkar=0;
int kar=0;
int flag8=0;
int LDR_Error=300;//baraye setup LDR
int sharp_Error=300;//baraye setup SHARP
void lcdclear(void);
///////////////////////////setup///////////////////////////////////
void setup()
{
 // EEPROM.write(33, 255);
//  EEPROM.write(34, 255);
 // EEPROM.write(35, 255);
 // EEPROM.write(36, 255);
  lcd.init();
  lcd.backlight();
  pinMode(12,OUTPUT);
  Serial.begin(9600);
  if( EEPROM[33]==255 && EEPROM[34]==255 && EEPROM[35]==255 && EEPROM[36]==255){
    flag=1;
    lcd.setCursor(0, 0); 
    lcd.print("create your password:"); 
  }
  else{
    flag=2;
    lcd.setCursor(0, 2); 
    lcd.print("enter password:");
    lcd.setCursor(0, 0); 
    lcd.print("(^__^)  hi!  (*__*)");
    lcd.setCursor(0, 1); 
    lcd.print("<");
    lcd.setCursor(5, 1); 
    lcd.print(">");
      
    //lcd.setCursor(5, 2); 
    //lcd.print("press A ");
    //lcd.setCursor(0, 3); 
    //lcd.print("to change password ");
     
  }
  Serial.println(a);
  Serial.println(b);
  Serial.println(c);
  Serial.println(d);
}
///////////////////////////////////////////////////////////////////////
void loop()
{
  char key = keypad.getKey();
  ////////////////////////////////////////////
  if(sec==1){
            if(kar==0){
              lcd.setCursor(0, 0); 
            lcd.print("A: change password"); 
            lcd.setCursor(0, 1); 
            lcd.print("B: Laser ON"); 
            lcd.setCursor(0, 2); 
            lcd.print("C: Sharp ON");
            lcd.setCursor(0, 3); 
            lcd.print("D: all secured!");
              
              } 
            if(flagkar==0){
                if (key != NO_KEY){ 
                  if(key == 'A'){
                    kar=1;
                    flagkar=1;
                    lcdclear();   
                    }
                  if(key == 'B'){
                    kar=2;
                    flagkar=1;
                    lcdclear();  
                    }
                  if(key == 'C'){
                    kar=3;
                    flagkar=1;
                    lcdclear();  
                    }
                  if(key == 'D'){
                    kar=4;
                    flagkar=1; 
                    lcdclear(); 
                    } 
                }
            }
            if(kar==1){
               change=1;
               sec=0;
               keyflag=0;
               lcd.setCursor(0, 0); 
                lcd.print("enter new password:");   
            }
            else if(kar==2){
               lcd.setCursor(0, 0); 
                lcd.print("Laser is ON");
                lcd.setCursor(3, 1); 
                lcd.print("press * to OFF");
                Serial.print("ldr 1:");
                Serial.println(analogRead(A1));
                Serial.print("ldr 2:");
                Serial.println(analogRead(A2));
                Serial.print("ldr 3:");
                Serial.println(analogRead(A3));
                Serial.print("ldr 4:");
                Serial.println(analogRead(A4));
                if(analogRead(A1)< LDR_Error || analogRead(A2)< LDR_Error ||analogRead(A3)< LDR_Error || analogRead(A4)< LDR_Error){
                    digitalWrite(12, 1);//bazer
                    digitalWrite(10, 1);//led
                    digitalWrite(11, 1);//led
                    digitalWrite(13, 1);//led
                }
                else{
                    digitalWrite(12, 0);//bazer
                    digitalWrite(10, 0);//led
                    digitalWrite(11, 0);//led
                    digitalWrite(13, 0);//led
                }
                if(flag8==0){ 
                  if (key != NO_KEY){
                    if(key == '*'){
                       lcd.setCursor(0, 3); 
                       lcd.print("enter the pasword:");
                       flag8=1;
                       keyflag=0;
                      } 
                  }
               }
               else{
                  if(keyflag<=3){
              if (key != NO_KEY){
                if(key == '1'){
                if(keyflag==0)
                  key1= 1;
                else if(keyflag==1)
                  key2= 1;
                else if(keyflag==2)
                  key3= 1;
                else if(keyflag==3)
                  key4= 1;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == 'B'){
                if(keyflag==0)
                  key1= 11;
                else if(keyflag==1)
                  key2= 11;
                else if(keyflag==2)
                  key3= 11;
                else if(keyflag==3)
                  key4= 11;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*");  
                }
                if(key == 'C'){
                if(keyflag==0)
                  key1= 12;
                else if(keyflag==1)
                  key2= 12;
                else if(keyflag==2)
                  key3= 12;
                else if(keyflag==3)
                  key4= 12;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == 'D'){
                if(keyflag==0)
                  key1= 13;
                else if(keyflag==1)
                  key2= 13;
                else if(keyflag==2)
                  key3= 13;
                else if(keyflag==3)
                  key4= 13;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '#'){
                if(keyflag==0)
                  key1= 14;
                else if(keyflag==1)
                  key2= 14;
                else if(keyflag==2)
                  key3= 14;
                else if(keyflag==3)
                  key4= 14;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '*'){
                if(keyflag==0)
                  key1= 15;
                else if(keyflag==1)
                  key2= 15;
                else if(keyflag==2)
                  key3= 15;
                else if(keyflag==3)
                  key4= 15;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == 'A'){
                if(keyflag==0)
                  key1= 15;
                else if(keyflag==1)
                  key2= 15;
                else if(keyflag==2)
                  key3= 15;
                else if(keyflag==3)
                  key4= 15;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '2'){
                //key = 0x02;
                if(keyflag==0)
                  key1= 2;
                else if(keyflag==1)
                  key2= 2;
                else if(keyflag==2)
                  key3= 2;
                else if(keyflag==3)
                  key4= 2;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '3'){
                //key = 0x03;
                if(keyflag==0)
                  key1= 3;
                else if(keyflag==1)
                  key2= 3;
                else if(keyflag==2)
                  key3= 3;
                else if(keyflag==3)
                  key4= 3;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '4'){
                //key = 0x04;
                if(keyflag==0)
                  key1= 4;
                else if(keyflag==1)
                  key2= 4;
                else if(keyflag==2)
                  key3= 4;
                else if(keyflag==3)
                  key4= 4;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '5'){
                //key = 0x05;
                if(keyflag==0)
                  key1= 5;
                else if(keyflag==1)
                  key2= 5;
                else if(keyflag==2)
                  key3= 5;
                else if(keyflag==3)
                  key4= 5;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '6'){
                //key = 0x06;
                if(keyflag==0)
                  key1= 6;
                else if(keyflag==1)
                  key2= 6;
                else if(keyflag==2)
                  key3= 6;
                else if(keyflag==3)
                  key4= 6;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '7'){
                //key = 0x07;
                if(keyflag==0)
                  key1= 7;
                else if(keyflag==1)
                  key2= 7;
                else if(keyflag==2)
                  key3= 7;
                else if(keyflag==3)
                  key4= 7;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '8'){
                //key = 0x08;
                if(keyflag==0)
                  key1= 8;
                else if(keyflag==1)
                  key2= 8;
                else if(keyflag==2)
                  key3= 8;
                else if(keyflag==3)
                  key4= 8;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '9'){
                //key = 0x09;
                if(keyflag==0)
                  key1= 9;
                else if(keyflag==1)
                  key2= 9;
                else if(keyflag==2)
                  key3= 9;
                else if(keyflag==3)
                  key4= 9;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '0'){
                //key = 0x09;
                if(keyflag==0)
                  key1= 0;
                else if(keyflag==1)
                  key2= 0;
                else if(keyflag==2)
                  key3= 0;
                else if(keyflag==3)
                  key4= 0;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
              }
            }

            else{
              if((EEPROM[36]==key1) && (EEPROM[35]==key2) &&(EEPROM[34]==key3) && (EEPROM[33]==key4)){  
                    lcdclear();
                    lcd.setCursor(0, 0); 
                    lcd.print("****OFF****");
                    delay(2000); 
                    Serial.println("doroste");
                    keyflag=0;
                    sec=1;
                    kar=0;
                    flagkar=0;
                    flag8=0;
                  }
                  else{
                    lcdclear();
                    lcd.setCursor(0, 0); 
                    lcd.print("**wrong password**"); 
                    lcd.setCursor(0, 2); 
                    lcd.print("u can try again"); 
                    lcd.setCursor(4, 3); 
                    lcd.print("in 10sec");
                    delay(10000);
                    lcdclear();
                    lcd.setCursor(0, 0); 
                    lcd.print("enter password:");  
                    keyflag=0;
                    flag8=0;
                  }
            }


            
           }
              
            }
           else if(kar==3){
               lcd.setCursor(0, 0); 
                lcd.print("Sharp is ON");
                lcd.setCursor(3, 1); 
                lcd.print("press * to OFF");
                Serial.print("sharp_value:");
                Serial.println(analogRead(A6));
                if(analogRead(A6)< sharp_Error){
                    digitalWrite(12, 1);//bazer
                    digitalWrite(10, 1);//led
                    digitalWrite(11, 1);//led
                    digitalWrite(13, 1);//led
                }
                else{
                    digitalWrite(12, 0);//bazer
                    digitalWrite(10, 0);//led
                    digitalWrite(11, 0);//led
                    digitalWrite(13, 0);//led
                }
                if(flag8==0){ 
                  if (key != NO_KEY){
                    if(key == '*'){
                       lcd.setCursor(0, 3); 
                       lcd.print("enter the pasword:");
                       flag8=1;
                       keyflag=0;
                      } 
                  }
               }
               else{
                  if(keyflag<=3){
              if (key != NO_KEY){
                if(key == '1'){
                if(keyflag==0)
                  key1= 1;
                else if(keyflag==1)
                  key2= 1;
                else if(keyflag==2)
                  key3= 1;
                else if(keyflag==3)
                  key4= 1;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == 'B'){
                if(keyflag==0)
                  key1= 11;
                else if(keyflag==1)
                  key2= 11;
                else if(keyflag==2)
                  key3= 11;
                else if(keyflag==3)
                  key4= 11;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*");  
                }
                if(key == 'C'){
                if(keyflag==0)
                  key1= 12;
                else if(keyflag==1)
                  key2= 12;
                else if(keyflag==2)
                  key3= 12;
                else if(keyflag==3)
                  key4= 12;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == 'D'){
                if(keyflag==0)
                  key1= 13;
                else if(keyflag==1)
                  key2= 13;
                else if(keyflag==2)
                  key3= 13;
                else if(keyflag==3)
                  key4= 13;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '#'){
                if(keyflag==0)
                  key1= 14;
                else if(keyflag==1)
                  key2= 14;
                else if(keyflag==2)
                  key3= 14;
                else if(keyflag==3)
                  key4= 14;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '*'){
                if(keyflag==0)
                  key1= 15;
                else if(keyflag==1)
                  key2= 15;
                else if(keyflag==2)
                  key3= 15;
                else if(keyflag==3)
                  key4= 15;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == 'A'){
                if(keyflag==0)
                  key1= 15;
                else if(keyflag==1)
                  key2= 15;
                else if(keyflag==2)
                  key3= 15;
                else if(keyflag==3)
                  key4= 15;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '2'){
                //key = 0x02;
                if(keyflag==0)
                  key1= 2;
                else if(keyflag==1)
                  key2= 2;
                else if(keyflag==2)
                  key3= 2;
                else if(keyflag==3)
                  key4= 2;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '3'){
                //key = 0x03;
                if(keyflag==0)
                  key1= 3;
                else if(keyflag==1)
                  key2= 3;
                else if(keyflag==2)
                  key3= 3;
                else if(keyflag==3)
                  key4= 3;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '4'){
                //key = 0x04;
                if(keyflag==0)
                  key1= 4;
                else if(keyflag==1)
                  key2= 4;
                else if(keyflag==2)
                  key3= 4;
                else if(keyflag==3)
                  key4= 4;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '5'){
                //key = 0x05;
                if(keyflag==0)
                  key1= 5;
                else if(keyflag==1)
                  key2= 5;
                else if(keyflag==2)
                  key3= 5;
                else if(keyflag==3)
                  key4= 5;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '6'){
                //key = 0x06;
                if(keyflag==0)
                  key1= 6;
                else if(keyflag==1)
                  key2= 6;
                else if(keyflag==2)
                  key3= 6;
                else if(keyflag==3)
                  key4= 6;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '7'){
                //key = 0x07;
                if(keyflag==0)
                  key1= 7;
                else if(keyflag==1)
                  key2= 7;
                else if(keyflag==2)
                  key3= 7;
                else if(keyflag==3)
                  key4= 7;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '8'){
                //key = 0x08;
                if(keyflag==0)
                  key1= 8;
                else if(keyflag==1)
                  key2= 8;
                else if(keyflag==2)
                  key3= 8;
                else if(keyflag==3)
                  key4= 8;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '9'){
                //key = 0x09;
                if(keyflag==0)
                  key1= 9;
                else if(keyflag==1)
                  key2= 9;
                else if(keyflag==2)
                  key3= 9;
                else if(keyflag==3)
                  key4= 9;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '0'){
                //key = 0x09;
                if(keyflag==0)
                  key1= 0;
                else if(keyflag==1)
                  key2= 0;
                else if(keyflag==2)
                  key3= 0;
                else if(keyflag==3)
                  key4= 0;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
              }
            }

            else{
              if((EEPROM[36]==key1) && (EEPROM[35]==key2) &&(EEPROM[34]==key3) && (EEPROM[33]==key4)){  
                    lcdclear();
                    lcd.setCursor(0, 0); 
                    lcd.print("****OFF****");
                    delay(2000); 
                    Serial.println("doroste");
                    keyflag=0;
                    sec=1;
                    kar=0;
                    flagkar=0;
                    flag8=0;
                  }
                  else{
                    lcdclear();
                    lcd.setCursor(0, 0); 
                    lcd.print("**wrong password**"); 
                    lcd.setCursor(0, 2); 
                    lcd.print("u can try again"); 
                    lcd.setCursor(4, 3); 
                    lcd.print("in 10sec");
                    delay(10000);
                    lcdclear();
                    lcd.setCursor(0, 0); 
                    lcd.print("enter password:");  
                    keyflag=0;
                    flag8=0;
                  }
            }


            
           }
              
            }
            else if(kar==4){
                       
               lcd.setCursor(0, 0); 
                lcd.print("Laser & sharp ON");
                lcd.setCursor(3, 1); 
                lcd.print("press * to OFF");
                Serial.print("ldr 1:");
                Serial.println(analogRead(A1));
                Serial.print("ldr 2:");
                Serial.println(analogRead(A2));
                Serial.print("ldr 3:");
                Serial.println(analogRead(A3));
                Serial.print("ldr 4:");
                Serial.println(analogRead(A4));
                if(analogRead(A1)< LDR_Error || analogRead(A2)< LDR_Error ||analogRead(A3)< LDR_Error || analogRead(A4)< LDR_Error || analogRead(A6)< sharp_Error){
                    digitalWrite(12, 1);//bazer
                    digitalWrite(10, 1);//led
                    digitalWrite(11, 1);//led
                    digitalWrite(13, 1);//led
                }
                else{
                    digitalWrite(12, 0);//bazer
                    digitalWrite(10, 0);//led
                    digitalWrite(11, 0);//led
                    digitalWrite(13, 0);//led
                }
                if(flag8==0){ 
                  if (key != NO_KEY){
                    if(key == '*'){
                       lcd.setCursor(0, 3); 
                       lcd.print("enter the pasword:");
                       flag8=1;
                       keyflag=0;
                      } 
                  }
               }
               else{
                  if(keyflag<=3){
              if (key != NO_KEY){
                if(key == '1'){
                if(keyflag==0)
                  key1= 1;
                else if(keyflag==1)
                  key2= 1;
                else if(keyflag==2)
                  key3= 1;
                else if(keyflag==3)
                  key4= 1;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == 'B'){
                if(keyflag==0)
                  key1= 11;
                else if(keyflag==1)
                  key2= 11;
                else if(keyflag==2)
                  key3= 11;
                else if(keyflag==3)
                  key4= 11;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*");  
                }
                if(key == 'C'){
                if(keyflag==0)
                  key1= 12;
                else if(keyflag==1)
                  key2= 12;
                else if(keyflag==2)
                  key3= 12;
                else if(keyflag==3)
                  key4= 12;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == 'D'){
                if(keyflag==0)
                  key1= 13;
                else if(keyflag==1)
                  key2= 13;
                else if(keyflag==2)
                  key3= 13;
                else if(keyflag==3)
                  key4= 13;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '#'){
                if(keyflag==0)
                  key1= 14;
                else if(keyflag==1)
                  key2= 14;
                else if(keyflag==2)
                  key3= 14;
                else if(keyflag==3)
                  key4= 14;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '*'){
                if(keyflag==0)
                  key1= 15;
                else if(keyflag==1)
                  key2= 15;
                else if(keyflag==2)
                  key3= 15;
                else if(keyflag==3)
                  key4= 15;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == 'A'){
                if(keyflag==0)
                  key1= 15;
                else if(keyflag==1)
                  key2= 15;
                else if(keyflag==2)
                  key3= 15;
                else if(keyflag==3)
                  key4= 15;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '2'){
                //key = 0x02;
                if(keyflag==0)
                  key1= 2;
                else if(keyflag==1)
                  key2= 2;
                else if(keyflag==2)
                  key3= 2;
                else if(keyflag==3)
                  key4= 2;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '3'){
                //key = 0x03;
                if(keyflag==0)
                  key1= 3;
                else if(keyflag==1)
                  key2= 3;
                else if(keyflag==2)
                  key3= 3;
                else if(keyflag==3)
                  key4= 3;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '4'){
                //key = 0x04;
                if(keyflag==0)
                  key1= 4;
                else if(keyflag==1)
                  key2= 4;
                else if(keyflag==2)
                  key3= 4;
                else if(keyflag==3)
                  key4= 4;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '5'){
                //key = 0x05;
                if(keyflag==0)
                  key1= 5;
                else if(keyflag==1)
                  key2= 5;
                else if(keyflag==2)
                  key3= 5;
                else if(keyflag==3)
                  key4= 5;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '6'){
                //key = 0x06;
                if(keyflag==0)
                  key1= 6;
                else if(keyflag==1)
                  key2= 6;
                else if(keyflag==2)
                  key3= 6;
                else if(keyflag==3)
                  key4= 6;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '7'){
                //key = 0x07;
                if(keyflag==0)
                  key1= 7;
                else if(keyflag==1)
                  key2= 7;
                else if(keyflag==2)
                  key3= 7;
                else if(keyflag==3)
                  key4= 7;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '8'){
                //key = 0x08;
                if(keyflag==0)
                  key1= 8;
                else if(keyflag==1)
                  key2= 8;
                else if(keyflag==2)
                  key3= 8;
                else if(keyflag==3)
                  key4= 8;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '9'){
                //key = 0x09;
                if(keyflag==0)
                  key1= 9;
                else if(keyflag==1)
                  key2= 9;
                else if(keyflag==2)
                  key3= 9;
                else if(keyflag==3)
                  key4= 9;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
                if(key == '0'){
                //key = 0x09;
                if(keyflag==0)
                  key1= 0;
                else if(keyflag==1)
                  key2= 0;
                else if(keyflag==2)
                  key3= 0;
                else if(keyflag==3)
                  key4= 0;
                  keyflag +=1;
                lcd.setCursor(keyflag, 2); 
                lcd.print("*"); 
                }
              }
            }

            else{
              if((EEPROM[36]==key1) && (EEPROM[35]==key2) &&(EEPROM[34]==key3) && (EEPROM[33]==key4)){  
                    lcdclear();
                    lcd.setCursor(0, 0); 
                    lcd.print("****OFF****");
                    delay(2000); 
                    Serial.println("doroste");
                    keyflag=0;
                    sec=1;
                    kar=0;
                    flagkar=0;
                    flag8=0;
                  }
                  else{
                    lcdclear();
                    lcd.setCursor(0, 0); 
                    lcd.print("**wrong password**"); 
                    lcd.setCursor(0, 2); 
                    lcd.print("u can try again"); 
                    lcd.setCursor(4, 3); 
                    lcd.print("in 10sec");
                    delay(10000);
                    lcdclear();
                    lcd.setCursor(0, 0); 
                    lcd.print("enter password:");  
                    keyflag=0;
                    flag8=0;
                  }
            }


             
              
            }
            

   
            }   
  }
  
/*
  Serial.println(analogRead(A0));
         if(analogRead(A0)<=300){
          //digitalWrite(12,1);
         }
         else{
          //digitalWrite(12,0);
          }*/
   ////////////////////////////////////////////////////////////// 
  else{  
        if(change==0){
            if(keyflag<=3){
              if (key != NO_KEY){
                if(key == '1'){
                if(keyflag==0)
                  key1= 1;
                else if(keyflag==1)
                  key2= 1;
                else if(keyflag==2)
                  key3= 1;
                else if(keyflag==3)
                  key4= 1;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*"); 
                }
                if(key == 'B'){
                if(keyflag==0)
                  key1= 11;
                else if(keyflag==1)
                  key2= 11;
                else if(keyflag==2)
                  key3= 11;
                else if(keyflag==3)
                  key4= 11;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*");  
                }
                if(key == 'C'){
                if(keyflag==0)
                  key1= 12;
                else if(keyflag==1)
                  key2= 12;
                else if(keyflag==2)
                  key3= 12;
                else if(keyflag==3)
                  key4= 12;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*"); 
                }
                if(key == 'D'){
                if(keyflag==0)
                  key1= 13;
                else if(keyflag==1)
                  key2= 13;
                else if(keyflag==2)
                  key3= 13;
                else if(keyflag==3)
                  key4= 13;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*"); 
                }
                if(key == '#'){
                if(keyflag==0)
                  key1= 14;
                else if(keyflag==1)
                  key2= 14;
                else if(keyflag==2)
                  key3= 14;
                else if(keyflag==3)
                  key4= 14;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*"); 
                }
                if(key == '*'){
                if(keyflag==0)
                  key1= 15;
                else if(keyflag==1)
                  key2= 15;
                else if(keyflag==2)
                  key3= 15;
                else if(keyflag==3)
                  key4= 15;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*"); 
                }
                if(key == 'A'){
                if(keyflag==0)
                  key1= 15;
                else if(keyflag==1)
                  key2= 15;
                else if(keyflag==2)
                  key3= 15;
                else if(keyflag==3)
                  key4= 15;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*"); 
                }
                if(key == '2'){
                //key = 0x02;
                if(keyflag==0)
                  key1= 2;
                else if(keyflag==1)
                  key2= 2;
                else if(keyflag==2)
                  key3= 2;
                else if(keyflag==3)
                  key4= 2;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*"); 
                }
                if(key == '3'){
                //key = 0x03;
                if(keyflag==0)
                  key1= 3;
                else if(keyflag==1)
                  key2= 3;
                else if(keyflag==2)
                  key3= 3;
                else if(keyflag==3)
                  key4= 3;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*"); 
                }
                if(key == '4'){
                //key = 0x04;
                if(keyflag==0)
                  key1= 4;
                else if(keyflag==1)
                  key2= 4;
                else if(keyflag==2)
                  key3= 4;
                else if(keyflag==3)
                  key4= 4;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*"); 
                }
                if(key == '5'){
                //key = 0x05;
                if(keyflag==0)
                  key1= 5;
                else if(keyflag==1)
                  key2= 5;
                else if(keyflag==2)
                  key3= 5;
                else if(keyflag==3)
                  key4= 5;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*"); 
                }
                if(key == '6'){
                //key = 0x06;
                if(keyflag==0)
                  key1= 6;
                else if(keyflag==1)
                  key2= 6;
                else if(keyflag==2)
                  key3= 6;
                else if(keyflag==3)
                  key4= 6;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*"); 
                }
                if(key == '7'){
                //key = 0x07;
                if(keyflag==0)
                  key1= 7;
                else if(keyflag==1)
                  key2= 7;
                else if(keyflag==2)
                  key3= 7;
                else if(keyflag==3)
                  key4= 7;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*"); 
                }
                if(key == '8'){
                //key = 0x08;
                if(keyflag==0)
                  key1= 8;
                else if(keyflag==1)
                  key2= 8;
                else if(keyflag==2)
                  key3= 8;
                else if(keyflag==3)
                  key4= 8;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*"); 
                }
                if(key == '9'){
                //key = 0x09;
                if(keyflag==0)
                  key1= 9;
                else if(keyflag==1)
                  key2= 9;
                else if(keyflag==2)
                  key3= 9;
                else if(keyflag==3)
                  key4= 9;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*"); 
                }
                if(key == '0'){
                //key = 0x09;
                if(keyflag==0)
                  key1= 0;
                else if(keyflag==1)
                  key2= 0;
                else if(keyflag==2)
                  key3= 0;
                else if(keyflag==3)
                  key4= 0;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*"); 
                }
              }
            }
         
            else{
                if(flag==1){
                    EEPROM[36]=key1;
                    delay(40);
                    EEPROM[35]=key2;
                    delay(40);
                    EEPROM[34]=key3;
                    delay(40);
                    EEPROM[33]=key4;
                    delay(40);
                    lcdclear();
                    lcd.setCursor(0, 0); 
                    lcd.print("new password created!"); 
                    keyflag=0;   
                }
                if(flag==2){
                  if((EEPROM[36]==key1) && (EEPROM[35]==key2) &&(EEPROM[34]==key3) && (EEPROM[33]==key4)){  
                    lcdclear();
                    lcd.setCursor(0, 0); 
                    lcd.print("****unlocked!****"); 
                    Serial.println("doroste");
                    keyflag=0;
                    sec=1;
                    secchange=1;
                  }
                  else{
                    lcdclear();
                    lcd.setCursor(0, 0); 
                    lcd.print("**wrong password**"); 
                    lcd.setCursor(0, 2); 
                    lcd.print("u can try again"); 
                    lcd.setCursor(4, 3); 
                    lcd.print("in 10sec");
                    delay(10000);
                    lcdclear();
                    lcd.setCursor(0, 0); 
                    lcd.print("enter password:");  
                    keyflag=0;
                  }
                }
            }
        }
        else{
           if(keyflag<=3){
              
                if (key != NO_KEY){
                if(key == '1'){
                if(keyflag==0)
                  key1= 1;
                else if(keyflag==1)
                  key2= 1;
                else if(keyflag==2)
                  key3= 1;
                else if(keyflag==3)
                  key4= 1;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*");
                }
               if(key == 'B'){
                if(keyflag==0)
                  key1= 11;
                else if(keyflag==1)
                  key2= 11;
                else if(keyflag==2)
                  key3= 11;
                else if(keyflag==3)
                  key4= 11;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*");
                }
                if(key == 'C'){
                if(keyflag==0)
                  key1= 12;
                else if(keyflag==1)
                  key2= 12;
                else if(keyflag==2)
                  key3= 12;
                else if(keyflag==3)
                  key4= 12;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*");
                }
                if(key == 'D'){
                if(keyflag==0)
                  key1= 13;
                else if(keyflag==1)
                  key2= 13;
                else if(keyflag==2)
                  key3= 13;
                else if(keyflag==3)
                  key4= 13;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*");
                }
                if(key == '#'){
                if(keyflag==0)
                  key1= 14;
                else if(keyflag==1)
                  key2= 14;
                else if(keyflag==2)
                  key3= 14;
                else if(keyflag==3)
                  key4= 14;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*");
                }
                if(key == '*'){
                if(keyflag==0)
                  key1= 15;
                else if(keyflag==1)
                  key2= 15;
                else if(keyflag==2)
                  key3= 15;
                else if(keyflag==3)
                  key4= 15;
                  keyflag +=1;
               lcd.setCursor(keyflag, 1); 
                lcd.print("*");
                }
                if(key == '2'){
                //key = 0x02;
                if(keyflag==0)
                  key1= 2;
                else if(keyflag==1)
                  key2= 2;
                else if(keyflag==2)
                  key3= 2;
                else if(keyflag==3)
                  key4= 2;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*");
                }
                if(key == '3'){
                //key = 0x03;
                if(keyflag==0)
                  key1= 3;
                else if(keyflag==1)
                  key2= 3;
                else if(keyflag==2)
                  key3= 3;
                else if(keyflag==3)
                  key4= 3;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*");
                }
                if(key == '4'){
                //key = 0x04;
                if(keyflag==0)
                  key1= 4;
                else if(keyflag==1)
                  key2= 4;
                else if(keyflag==2)
                  key3= 4;
                else if(keyflag==3)
                  key4= 4;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*");
                }
                if(key == '5'){
                //key = 0x05;
                if(keyflag==0)
                  key1= 5;
                else if(keyflag==1)
                  key2= 5;
                else if(keyflag==2)
                  key3= 5;
                else if(keyflag==3)
                  key4= 5;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*");
                }
                if(key == '6'){
                //key = 0x06;
                if(keyflag==0)
                  key1= 6;
                else if(keyflag==1)
                  key2= 6;
                else if(keyflag==2)
                  key3= 6;
                else if(keyflag==3)
                  key4= 6;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*");
                }
                if(key == '7'){
                //key = 0x07;
                if(keyflag==0)
                  key1= 7;
                else if(keyflag==1)
                  key2= 7;
                else if(keyflag==2)
                  key3= 7;
                else if(keyflag==3)
                  key4= 7;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*");
                }
                if(key == '8'){
                //key = 0x08;
                if(keyflag==0)
                  key1= 8;
                else if(keyflag==1)
                  key2= 8;
                else if(keyflag==2)
                  key3= 8;
                else if(keyflag==3)
                  key4= 8;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*");
                }
                if(key == '9'){
                //key = 0x09;
                if(keyflag==0)
                  key1= 9;
                else if(keyflag==1)
                  key2= 9;
                else if(keyflag==2)
                  key3= 9;
                else if(keyflag==3)
                  key4= 9;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*");
                }
                if(key == '0'){
                //key = 0x09;
                if(keyflag==0)
                  key1= 0;
                else if(keyflag==1)
                  key2= 0;
                else if(keyflag==2)
                  key3= 0;
                else if(keyflag==3)
                  key4= 0;
                  keyflag +=1;
                lcd.setCursor(keyflag, 1); 
                lcd.print("*");
                }
              }
           }
             else{
                    EEPROM[36]=key1;
                    delay(40);
                    EEPROM[35]=key2;
                    delay(40);
                    EEPROM[34]=key3;
                    delay(40);
                    EEPROM[33]=key4;
                    delay(40);
                    change=0;
                    keyflag=0;
                    lcdclear();
                    lcd.setCursor(0, 1); 
                    lcd.print("new password created");
                    delay(2000);
                    lcdclear();
                    sec=1;
                    kar=0;
                    flagkar=0;                
                        
                }   
        }
  } 
    
    
    
}


void lcdclear(void){
  lcd.setCursor(0, 0); 
  lcd.print("                    "); 
  lcd.setCursor(0, 1); 
  lcd.print("                    "); 
  lcd.setCursor(0, 2); 
  lcd.print("                    ");
  lcd.setCursor(0, 3); 
  lcd.print("                    ");
