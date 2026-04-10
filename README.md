
# Gaz-PPM-Ölçüm-Ve-Veri-Takip-Sistemi
MQ sensörü ve ESP32 kullanarak gaz PPM ölçümü yapan, verileri MySQL veritabanına kaydeden ve web arayüzünde gösteren IoT sistemi.
# Gaz PPM Ölçüm ve Veri Takip Sistemi

## Proje Hakkında
Bu proje, MQ serisi gaz sensörü kullanılarak ortamdaki gaz yoğunluğunu PPM cinsinden ölçen, ölçüm sonuçlarını web arayüzünde gösteren ve MySQL veritabanında saklayan IoT tabanlı bir izleme sistemidir.

Sistem; sensörden alınan verileri Arduino / ESP32 ile işler, belirli aralıklarla sunucuya gönderir ve kullanıcıların web arayüzü üzerinden geçmiş ölçümleri takip etmesini sağlar. Belirlenen eşik değerinin aşılması durumunda LED ve buzzer ile uyarı verilebilir.

## Amaç
- Ortamdaki gaz seviyesini izlemek
- PPM verisini düzenli olarak kaydetmek
- Web arayüzünden canlı ve geçmiş verileri görüntülemek
- Tehlikeli eşiklerde uyarı oluşturmak

## Kullanılan Teknolojiler
- MQ Serisi Gaz Sensörü (örnek: MQ135)
- ESP32 / Arduino
- C++ (Arduino Framework)
- WiFi / HTTP istemci
- PHP
- MySQL
- HTML / CSS
- Veri işleme ve eşik tabanlı karar mantığı

## Sistem Özellikleri
- Gerçek zamanlı PPM ölçümü
- Belirli aralıklarla veri gönderimi
- MySQL veritabanına kayıt
- Basit web panel üzerinden veri listeleme
- LED ve buzzer ile alarm sistemi
- Eşik aşıldığında uyarı üretme

## Örnek Donanım Bağlantıları
| Bileşen | Bağlantı |
|---|---|
| MQ sensörü AO | ESP32 GPIO34 |
| MQ sensörü VCC | 5V |
| MQ sensörü GND | GND |
| Alarm LED | GPIO18 |
| Buzzer | GPIO19 |

## Klasör Yapısı
- `src/main.ino` → ESP32 final kodu
- `database/schema.sql` → MySQL tablo yapısı
- `web/insert_data.php` → Veriyi veritabanına kaydetme
- `web/index.php` → Ölçüm kayıtlarını listeleme
- `docs/baglanti_listesi.md` → Donanım bağlantıları

## Kurulum
1. ESP32 kodunda WiFi bilgilerini gir.
2. Sunucu adresini kendi PHP sunucuna göre güncelle.
3. MySQL'de `schema.sql` dosyasını çalıştır.
4. `web` klasörünü PHP sunucuna koy.
5. ESP32 kodunu karta yükle.
6. Web arayüzünden gelen ölçümleri kontrol et.

## Veritabanı Yapısı
Sistem her ölçüm için şu bilgileri kaydeder:
- PPM değeri
- Sensör ham değeri
- Alarm durumu
- Kayıt zamanı

## Dil
C++ (Arduino), PHP, SQL, HTML
## 🔌 Donanım Bağlantıları

### 🧠 Kullanılan Bileşenler

* ESP32
* MQ Serisi Gaz Sensörü (MQ135 önerilir)
* LED (alarm için)
* Buzzer (sesli uyarı için)
* 220Ω direnç (LED için)
* Breadboard ve jumper kablolar

---

### 🔹 MQ Gaz Sensörü Bağlantısı

| Sensör Pin      | Bağlantı |
| --------------- | -------- |
| VCC             | 5V       |
| GND             | GND      |
| AO (Analog Out) | GPIO34   |

📌 Not:
MQ sensörünün analog çıkışı kullanılır. Dijital çıkış kullanılmaz.

---

### 🔹 LED Bağlantısı (Alarm)

| LED Ucu        | Bağlantı             |
| -------------- | -------------------- |
| Uzun bacak (+) | 220Ω direnç → GPIO18 |
| Kısa bacak (-) | GND                  |

---

### 🔹 Buzzer Bağlantısı

| Buzzer Ucu  | Bağlantı |
| ----------- | -------- |
| Pozitif (+) | GPIO19   |
| Negatif (-) | GND      |

---

### 🔹 ESP32 Pin Özeti

| Pin    | Görev                 |
| ------ | --------------------- |
| GPIO34 | MQ sensör analog veri |
| GPIO18 | LED (alarm)           |
| GPIO19 | Buzzer                |
| 5V     | Sensör besleme        |
| GND    | Ortak toprak          |

---

### ⚠️ Önemli Notlar

* ESP32 analog giriş için **GPIO34** kullanılır.
* MQ sensörü **ısınma süresi (warm-up)** gerektirir.
* Doğru PPM ölçümü için **kalibrasyon yapılmalıdır**.
* Tüm GND bağlantıları ortak olmalıdır.
* LED mutlaka direnç ile bağlanmalıdır.

---

### 🔥 Kısa Özet

```text
MQ Sensör → GPIO34
LED → GPIO18
Buzzer → GPIO19
```

## Geliştirici
Enes Argama
Bilgisayar Mühendisliği Öğrencisi
