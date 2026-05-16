#include <splash.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EEPROM.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

const int button1Pin = 9;
const int button2Pin = 8; 
const int button3Pin = 7; 

const int sound = 6;

int button1State = 0;
int button2State = 0;
int button3State = 0;

//settings and vars
bool soundEnabled=true;

bool paused=false;
int asiStatus = 0;
int sheepStatus = 0;
int location = 0;
int wool = 0;
int money = 0;

#define ACTIVATED LOW

void setup() {
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);

  digitalWrite(button1Pin, HIGH);
  digitalWrite(button2Pin, HIGH);
  digitalWrite(button3Pin, HIGH);
  // or just 
  // pinMode(button1Pin, INPUT_PULLUP)
  // etc
  
  pinMode(sound, OUTPUT);

  pinMode(13,OUTPUT);

  randomSeed(analogRead(0));

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  // splash
  display.setTextColor(WHITE);
  //display.println(F("jakobdesign presents")); 
  display.print(F(" asiya with"));
  //change below to fit my purposes muahahahhaha
  display.drawBitmap(15, 24, splash1 , 48, 26, WHITE);
  display.display();
  
  //splash tone -- also subject to alteration

  tone(sound,500,200);
  delay(200);
  tone(sound,1000,200);
  delay(400);
  tone(sound,700,200);
  delay(200);
  tone(sound,1100,200);

  delay(2200);
  // end splash

  
  display.clearDisplay();

}

void loop() {
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  button3State = digitalRead(button3Pin);
  display.clearDisplay();
  display.setCursor(0,0);
  if(button1State==ACTIVATED){
    display.drawBitmap(10, 26, dinoWalk0 , 48, 24, WHITE);
    tone(sound,500,200);
    delay(60);
  }
  if(button2State==ACTIVATED){
   display.drawBitmap(10, 26, dinoWalk1 , 48, 24, WHITE);
   tone(sound,1000,200);
   delay(60);
  }
  if(button3State==ACTIVATED){
    display.drawBitmap(10, 26, dinoWalk2 , 48, 24, WHITE);
    tone(sound,700,200);
    delay(60);
  }
}
