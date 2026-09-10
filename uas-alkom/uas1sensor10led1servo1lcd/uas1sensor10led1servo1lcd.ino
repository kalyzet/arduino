#include <LiquidCrystal.h>
#include <Servo.h>

// Pin sensor ultrasonik
#define TRIG_PIN 9
#define ECHO_PIN 10

// Pin lainnya
#define SERVO_PIN 11
#define POT_PIN A0

// Pin LED
const int ledGroup1[5] = {6, 8, 13, A0, A1};  // LED grup pertama
const int ledGroup2[4] = {A2, A3, A4, A5};   // LED grup kedua

// LCD setup
LiquidCrystal lcd(12, 5, 4, 3, 2, 7);
Servo servo;

unsigned long openStartTime = 0;
const long OPEN_DURATION = 3000;
bool lidOpen = false;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Tempat Sampah");
  delay(2000);
  lcd.clear();

  // Inisialisasi sensor dan servo
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  servo.attach(SERVO_PIN);
  servo.write(0);

  // Inisialisasi LED
  for (int i = 0; i < 5; i++) {
    pinMode(ledGroup1[i], OUTPUT);  // LED grup pertama
    digitalWrite(ledGroup1[i], LOW);
  }

  for (int i = 0; i < 4; i++) {
    pinMode(ledGroup2[i], OUTPUT);  // LED grup kedua
    digitalWrite(ledGroup2[i], LOW);
  }

  lcd.setCursor(0, 0);
  lcd.print("Jarak: --- cm");
  lcd.setCursor(0, 1);
  lcd.print("Tutup Sampah!");
}

void loop() {
  long duration;
  int distance;

  // Proses pengukuran jarak dengan sensor ultrasonik
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duration == 0) {
    distance = 999;
  } else {
    distance = duration * 0.034 / 2;
  }

  // Baca potensiometer untuk jarak maksimal
  int potValue = analogRead(POT_PIN);
  int maxDistance = map(potValue, 0, 1023, 10, 100);

  // Tampilkan jarak di LCD
  lcd.setCursor(0, 0);
  lcd.print("Jarak: ");
  lcd.print(distance);
  lcd.print(" cm   ");

  // Update LED berdasarkan jarak sensor
  updateLedState(distance, maxDistance);

  // Kontrol servo dan status LCD
  if (distance > 0 && distance <= maxDistance) {
    if (!lidOpen) {
      servo.write(80);   // Buka tempat sampah
      openStartTime = millis();
      lidOpen = true;
      lcd.setCursor(0, 1);
      lcd.print("Buka Sampah!   ");
    } else {
      lcd.setCursor(0, 1);
      lcd.print("Buka Sampah!   ");
    }
  } else {
    if (lidOpen && millis() - openStartTime >= OPEN_DURATION) {
      servo.write(0);    // Tutup tempat sampah
      lidOpen = false;
      lcd.setCursor(0, 1);
      lcd.print("Tutup Sampah!");
    } else if (!lidOpen) {
      lcd.setCursor(0, 1);
      lcd.print("Tutup Sampah!");
    }
  }

  delay(200);
}

// Fungsi untuk mengatur status LED berdasarkan jarak
void updateLedState(int distance, int maxDistance) {
  if (distance <= maxDistance) {
    // Grup pertama LED nyala
    for (int i = 0; i < 5; i++) {
      digitalWrite(ledGroup1[i], HIGH);  // Nyalakan grup pertama LED
    }
    for (int i = 0; i < 4; i++) {
      digitalWrite(ledGroup2[i], LOW);   // Matikan grup kedua LED
    }
  } else {
    // Grup kedua LED nyala
    for (int i = 0; i < 5; i++) {
      digitalWrite(ledGroup1[i], LOW);   // Matikan grup pertama LED
    }
    for (int i = 0; i < 4; i++) {
      digitalWrite(ledGroup2[i], HIGH);  // Nyalakan grup kedua LED
    }
  }
}
