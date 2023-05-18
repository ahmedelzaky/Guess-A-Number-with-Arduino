/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <LiquidCrystal.h>
#include <Keypad.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte ROWS = 4;  // four rows
const byte COLS = 3;  // four columns
// define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  { '1', '2', '3' },
  { '4', '5', '6' },
  { '7', '8', '9' },
  { '*', '0', '#' }
};
byte rowPins[ROWS] = { 13, 10, 9, 8 };  // connect to the row pinouts of the keypad
byte colPins[COLS] = { A1, A2, A3 };
// initialize an instance of class NewKeypad
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

#define G_led 7
#define R_led 6

int ranNum;
String pad;
char keypressed;
const byte numRows = 4;
const byte numCols = 4;

int i = 0;
int fails = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(G_led, OUTPUT);
  pinMode(R_led, OUTPUT);
  lcd.print("Guess A Number");
  randomSeed(analogRead(A0));
  ranNum = random(0, 100);
}

void loop() {
  read_Keypad();
  check_Fails();
  game_Check();
}
void read_Keypad() {
  keypressed = customKeypad.getKey();
  if (keypressed) {
    if (keypressed != '#' || keypressed != '*') {
      String num = String(keypressed);
      pad += num;
      i++;
    }
  }
}

void game_Check() {
  if (keypressed == '#' || keypressed == '*' || i == 2) {
    Serial.println(ranNum);
    if (pad.toInt() == ranNum) {
      lcd.clear();
      lcd.print("Winner ^_^");
      digitalWrite(G_led, HIGH);
      delay(3000);
      digitalWrite(G_led, LOW);
      game_Reset();
    } else if (pad.toInt() > ranNum) {
      lcd.clear();
      lcd.print("The number is ");
      lcd.setCursor(0, 1);
      lcd.print("Less Than: ");
      lcd.print(pad.toInt());
      pad = "";
      fails++;
      digitalWrite(R_led, HIGH);
      delay(2000);
      digitalWrite(R_led, LOW);
      lcd.clear();
      lcd.print("Guess A Number");
    } else if (pad.toInt() < ranNum) {
      lcd.clear();
      lcd.print("The Number is ");
      lcd.setCursor(0, 1);
      lcd.print("Greater Than: ");
      lcd.print(pad.toInt());
      pad = "";
      fails++;
      digitalWrite(R_led, HIGH);
      delay(200);
      digitalWrite(R_led, LOW);
      lcd.clear();
      lcd.print("Guess A Number");
    }
    i = 0;
  }
}

void check_Fails() {
  if (fails == 10) {
    lcd.clear();
    lcd.print("GAME OVER");
    lcd.setCursor(0, 1);
    lcd.print("^_____^");
    digitalWrite(R_led, HIGH);
    delay(3000);
    digitalWrite(R_led, LOW);

    game_Reset();
  }
}

void game_Reset() {
  lcd.clear();
  lcd.print("Guess A Number");
  ranNum = random(0, 99);
  pad = "";
  fails = 0;
  i == 0;
}