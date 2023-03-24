#include <stdio.h>
#include <LiquidCrystal.h>

const byte potPin = A0;
const byte ESCPin = 9;

unsigned int potVal; // stores the voltage read from the potentiometer
byte ESCVal;  // stores the duty cycle to be output on the ESCPin

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

const byte chinchin[] = {
  0b01110,
  0b01010,
  0b01010,
  0b01010,
  0b01010,
  0b11111,
  0b10101,
  0b11111,
};
void setup() {
pinMode(ESCPin, OUTPUT);

lcd.begin(16,2); // initialize lcd screen with dimensions
lcd.createChar(0, chinchin);
  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin);
  //ESCVal = map(potVal, 0, 1023, 0, 255);
  ESCVal = (1023-potVal) >> 2;
  analogWrite(ESCPin, ESCVal);
  Serial.println(ESCVal);

  int percentage = ESCVal * 100 / 255;
  lcd.setCursor(0,0); // Sets the cursor to col 0 and row 0 (as start point) 
  lcd.print("Motor speed: ERC "); 
  lcd.setCursor(0,1);

  char perc[3];
  sprintf(perc, "%3d", percentage);


  /*if ( percentage == 69){
    perc[0] = 0;
    for (int i = 0; i < 3; i++)
      lcd.write(perc[i]);
  } else {
    lcd.print(perc);
  }
  */
  
  lcd.print(perc);
  lcd.print("%");
 

}


/*  ****Pin Connections****

VSS -> GND
VDD -> +5V
V0 -> POTENTIOMETER
RS -> 7
RW -> GND
EN -> 6
D4 -> 5
D5 -> 4
D6 -> 3
D7 -> 2
A -> +5V
K -> GND


*/