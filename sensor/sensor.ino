// Pin sensor
const int trigPin = 9;
const int echoPin = 10;

// Variabel jarak
long durasi;
int jarak;

void setup() {
  Serial.begin(9600);            // Mulai komunikasi serial
  pinMode(trigPin, OUTPUT);      // Trig sebagai output
  pinMode(echoPin, INPUT);       // Echo sebagai input
}

void loop() {
  // Kirim sinyal ultrasonik
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);   // Kirim pulsa 10µs
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Baca durasi pantulan
  durasi = pulseIn(echoPin, HIGH);

  // Hitung jarak (cm)
  jarak = durasi * 0.034 / 2;

  // Tampilkan jarak di Serial Monitor
  Serial.print("Jarak: ");
  Serial.print(jarak);
  Serial.println(" cm");

  delay(500); // Delay 0.5 detik
}
