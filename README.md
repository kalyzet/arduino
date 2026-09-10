# Laporan Koleksi Projek Arduino

## 1. Gambaran Umum

Folder ini berisi beberapa projek Arduino yang menggunakan LED, sensor ultrasonik, servo, LCD, dan potensiometer. Projek tersusun dari contoh dasar hingga projek terpadu tempat sampah otomatis.

## 2. Struktur dan Penjelasan Folder

### `A.H/`

- **File:** `A.H.ino`
- **Fungsi:** Mengendalikan servo berdasarkan jarak objek yang dibaca sensor ultrasonik.
- **Cara kerja:** Sensor mengirim pulsa melalui pin 9 dan membaca pantulan melalui pin 10. Jika objek berada pada jarak maksimal 20 cm, servo bergerak ke 90 derajat. Jika objek lebih jauh, servo kembali ke 0 derajat.
- **Komponen:** Arduino, sensor ultrasonik, servo.
- **Pin utama:** Trigger 9, Echo 10, Servo 11.
- **Output:** Jarak ditampilkan pada Serial Monitor dengan baud rate 9600.

### `lampu_led/`

- **File:** `lampu_led.ino`
- **Fungsi:** Menguji pola nyala tiga LED.
- **Cara kerja:** Semua LED menyala dan mati secara bersamaan, kemudian berkedip satu per satu, lalu menyala bergantian seperti running LED.
- **Komponen:** Tiga LED, resistor, Arduino.
- **Pin utama:** LED merah 2, LED kuning 3, LED hijau 4.
- **Output:** Pola cahaya LED berulang sesuai interval waktu yang ditentukan.

### `lcd/`

- **File:** `lcd.ino`
- **Fungsi:** Menampilkan teks dan waktu berjalan pada LCD 16x2.
- **Cara kerja:** Saat Arduino mulai, LCD menampilkan teks `Hahahay`. Baris kedua menampilkan jumlah detik sejak Arduino melakukan reset.
- **Komponen:** LCD 16x2, Arduino.
- **Pin LCD:** RS 12, EN 11, D4 5, D5 4, D6 3, D7 2.
- **Library:** `LiquidCrystal`.

### `roboarny/`

- **File:** `roboarny.ino`
- **Fungsi:** Membuat mekanisme tempat sampah otomatis sederhana.
- **Cara kerja:** Sensor ultrasonik mengukur jarak objek. Jika objek berada dalam jarak 20 cm, servo membuka tutup ke 90 derajat dan LED menyala selama proses deteksi. Jika tidak ada objek, servo menutup pada 0 derajat dan LED mati.
- **Komponen:** Sensor ultrasonik, servo, LED, Arduino.
- **Pin utama:** Trigger 9, Echo 10, Servo 11, LED 6.
- **Output:** Jarak tampil pada Serial Monitor.

### `sensor_led/`

- **File:** `sensor_led.ino`
- **Fungsi:** Menampilkan kategori jarak menggunakan tiga LED.
- **Cara kerja:** Sensor ultrasonik membaca jarak lalu memilih LED sesuai kategori:
  - Jarak kurang dari 10 cm: LED merah menyala.
  - Jarak 10 sampai 20 cm: LED kuning menyala.
  - Jarak lebih dari 20 cm: LED hijau menyala.
- **Komponen:** Sensor ultrasonik, tiga LED, resistor, Arduino.
- **Pin utama:** Trigger 9, Echo 10, LED merah 2, LED kuning 3, LED hijau 4.
- **Output:** Jarak tampil pada Serial Monitor.

### `sensor/`

- **File:** `sensor.ino`
- **Fungsi:** Menguji pembacaan jarak menggunakan sensor ultrasonik.
- **Cara kerja:** Arduino mengirim pulsa ultrasonik melalui pin Trigger, membaca durasi pantulan melalui pin Echo, kemudian mengubahnya menjadi satuan sentimeter.
- **Komponen:** Sensor ultrasonik, Arduino.
- **Pin utama:** Trigger 9, Echo 10.
- **Output:** Nilai jarak tampil pada Serial Monitor dengan baud rate 9600 setiap 500 ms.

### `uas-alkom/`

- **File:** `uas1sensor10led1servo1lcd.ino`
- **Fungsi:** Projek terpadu tempat sampah otomatis dengan sensor ultrasonik, sembilan LED, satu servo, LCD, dan potensiometer.
- **Cara kerja:** Sensor mengukur jarak objek. Potensiometer mengatur batas jarak antara 10 sampai 100 cm. Saat objek berada dalam batas tersebut, servo membuka tutup dan grup LED pertama menyala. Setelah objek tidak terdeteksi selama 3 detik, servo menutup dan status ditampilkan pada LCD.
- **Komponen:** Sensor ultrasonik, servo, LCD 16x2, sembilan LED, potensiometer, Arduino.
- **Pin utama:** Trigger 9, Echo 10, Servo 11, potensiometer A0, LCD menggunakan pin 12, 5, 4, 3, 2, 7.
- **Tampilan LCD:** Menampilkan jarak serta status `Buka Sampah!` atau `Tutup Sampah!`.
- **Catatan rangkaian:** Program menetapkan potensiometer pada A0 dan juga memasukkan A0 sebagai salah satu pin LED pada `ledGroup1`. Kedua fungsi ini berpotensi konflik sehingga pin LED perlu dipindahkan ke pin yang tidak digunakan sebelum rangkaian dijalankan.

## 3. Library yang Digunakan

- `Servo.h` untuk mengendalikan motor servo pada folder `A.H`, `roboarny`, dan `uas-alkom`.
- `LiquidCrystal.h` untuk mengendalikan LCD pada folder `lcd` dan `uas-alkom`.

## 4. Cara Menjalankan Projek

1. Buka folder projek yang ingin digunakan melalui Arduino IDE.
2. Buka file `.ino` dengan nama yang sesuai.
3. Hubungkan komponen berdasarkan konfigurasi pin pada program.
4. Pilih board dan port Arduino.
5. Upload program.
6. Buka Serial Monitor pada baud rate 9600 jika projek menampilkan data sensor.

## 5. Kesimpulan

Koleksi ini menunjukkan tahapan pembelajaran sistem Arduino, mulai dari kendali LED dan pembacaan sensor, kemudian penggunaan LCD dan servo, hingga integrasi beberapa komponen dalam sistem tempat sampah otomatis. Setiap folder memiliki program mandiri sehingga dapat diuji secara terpisah.
