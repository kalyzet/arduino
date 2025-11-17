// Definisikan pin LED
const int ledMerah = 2;
const int ledKuning = 3;
const int ledHijau = 4;

void setup() {
  // Atur semua pin LED sebagai output
  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);
}

void loop() {
  // --- LED Hidup Semua ---
  digitalWrite(ledMerah, HIGH);   // Nyalakan LED Merah
  digitalWrite(ledKuning, HIGH);  // Nyalakan LED Kuning
  digitalWrite(ledHijau, HIGH);   // Nyalakan LED Hijau
  delay(1000);                    // Tunggu 1 detik

  // --- LED Mati Semua ---
  digitalWrite(ledMerah, LOW);    // Matikan LED Merah
  digitalWrite(ledKuning, LOW);   // Matikan LED Kuning
  digitalWrite(ledHijau, LOW);    // Matikan LED Hijau
  delay(1000);                    // Tunggu 1 detik

  // --- LED Berkedip Satu per Satu ---
  digitalWrite(ledMerah, HIGH);
  delay(500);
  digitalWrite(ledMerah, LOW);
  delay(500);

  digitalWrite(ledKuning, HIGH);
  delay(500);
  digitalWrite(ledKuning, LOW);
  delay(500);

  digitalWrite(ledHijau, HIGH);
  delay(500);
  digitalWrite(ledHijau, LOW);
  delay(500);

  // --- LED Bergantian Menyala (Running LED) ---
  digitalWrite(ledMerah, HIGH);
  delay(300);
  digitalWrite(ledMerah, LOW);

  digitalWrite(ledKuning, HIGH);
  delay(300);
  digitalWrite(ledKuning, LOW);

  digitalWrite(ledHijau, HIGH);
  delay(300);
  digitalWrite(ledHijau, LOW);
}
