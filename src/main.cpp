#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>
#include <Keypad.h>

DFRobotDFPlayerMini dfp;

const byte ROWS = 6;
const byte COLS = 6;
/* Alokasi Tombol
 * 1 : A1 = Language Select
 * 7 : A2 = Lamp
 * c : A3 = Brain
 * i : A4 = Volume
 * o : A5 = Sing
 * u : A6 = Power
 * 2 : PA1
 * 8 : PB1
 * d : PC1
 * j : PD1
 * 3 : PA2
 * 9 : PB2
 * e : PC2
 * k : PD2
 * 4 : PA3
 * 0 : PB3
 * f : PC3
 * l : PD3
 * 5 : PA4
 * a : PB4
 * g : PC4
 * m : PD4
 * 
 * b : PB5
 * h : PC5
 * n : PD5
 * v : SEL1
 * p : SEL2
 * w : SEL3
 * q : SEL4
 * x : SEL5
 * r : SEL6
 * y : SEL7
 * s : SEL8
 * z : SEL9
 * t : SEL10
 * 
 */
char keys[ROWS][COLS] = {
  {'1','2','3','4','5','6'},
  {'7','8','9','0','a','b'},
  {'c','d','e','f','g','h'},
  {'i','j','k','l','m','n'},
  {'o','p','q','r','s','t'},
  {'u','v','w','x','y','z'},
};
byte rowPins[ROWS] = {PA0, PA1, PA2, PA3, PA4, PA5};
byte colPins[COLS] = {PA6, PA7, PB0, PB1, PB10, PB11};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  // Serial1.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  delay(20);
  dfp.begin(Serial, true, false);
  dfp.volume(25);
  delay(100);
  dfp.disableLoop();
  delay(20);
  dfp.play(6);
}

void loop() {
  // static long lastmil = millis();
  // if(millis() - lastmil > 1000){
  //   Serial1.print('.');
  //   lastmil = millis();
  // }

  char key = keypad.getKey();
  switch (key)
  {
  case '1':
    dfp.play(1);
    break;

  case '7':
    dfp.play(2);
    break;

  case 'c':
    dfp.play(3);
    break;

  case 'i':
    dfp.play(4);
    break;

  case 'o':
    dfp.play(15);
    break;
  
  default:
   
    break;
  }
  // if(key){
  //   //Serial1.println(key);
  //   digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  // }
}