#include <Servo.h>

#define TRIG_PIN 9
#define ECHO_PIN 10
#define SERVO_PIN 11
#define LED_PIN 6
#define MAX_DISTANCE 20  // Jarak maksimal agar servo buka (cm)

Servo servo;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  servo.attach(SERVO_PIN);
  servo.write(0); // posisi tutup
}

void loop() {
  long duration;
  int distance;

  // Kirim pulsa trigger
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Baca pulsa echo
  duration = pulseIn(ECHO_PIN, HIGH, 30000); // timeout 30ms
  distance = duration * 0.034 / 2; // Konversi ke cm

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance <= MAX_DISTANCE) {
    // Deteksi tangan/sampah
    servo.write(90); // buka tutup
    digitalWrite(LED_PIN, HIGH);
    delay(1500); // tunggu 1.5 detik
  } else {
    // Tidak ada objek
    servo.write(0); // tutup
    digitalWrite(LED_PIN, LOW);
  }

  delay(200); // interval baca
}
