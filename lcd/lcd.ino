#include<LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
lcd.begin(16, 2);
lcd.print("Hahahay"); //menampilkan teks
}

void loop() {
  //set the cursor to column 0, line 1
  //line 1 is th second row, since countring begins with 0
lcd.setCursor(0, 1);
//print the number of seconds since reset
lcd.print(millis() / 1000);
}
