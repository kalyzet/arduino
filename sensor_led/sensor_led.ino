// Definisi pin sensor
const int trigPin = 9;
const int echoPin = 10;

// Definisi pin LED
const int ledMerah = 2;
const int ledKuning = 3;
const int ledHijau = 4;

long durasi;
int jarak;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);

  Serial.begin(9600); // Untuk monitor jarak di Serial Monitor
}

void loop() {
  // Kirim sinyal ultrasonik
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Baca durasi pantulan
  durasi = pulseIn(echoPin, HIGH);
  jarak = durasi * 0.034 / 2;

  Serial.print("Jarak: ");
  Serial.print(jarak);
  Serial.println(" cm");

  // Logika LED berdasarkan jarak
  if (jarak < 10) {
    // Sangat dekat, nyalakan merah
    digitalWrite(ledMerah, HIGH);
    digitalWrite(ledKuning, LOW);
    digitalWrite(ledHijau, LOW);
  } else if (jarak >= 10 && jarak <= 20) {
    // Sedang, nyalakan kuning
    digitalWrite(ledMerah, LOW);
    digitalWrite(ledKuning, HIGH);
    digitalWrite(ledHijau, LOW);
  } else {
    // Jauh, nyalakan hijau
    digitalWrite(ledMerah, LOW);
    digitalWrite(ledKuning, LOW);
    digitalWrite(ledHijau, HIGH);
  }

  delay(300); // jeda antar pembacaan
}
