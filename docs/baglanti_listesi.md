# Gaz PPM Ölçüm ve Veri Takip Sistemi - Bağlantı Listesi

## Kullanılan Bileşenler
- ESP32
- MQ Serisi Gaz Sensörü (örnek: MQ135)
- LED
- Buzzer
- Breadboard
- Jumper kablolar

## Bağlantılar
- MQ sensörü AO -> ESP32 GPIO34
- MQ sensörü VCC -> 5V
- MQ sensörü GND -> GND

- LED uzun bacak -> 220 ohm direnç -> ESP32 GPIO18
- LED kısa bacak -> GND

- Buzzer pozitif uç -> ESP32 GPIO19
- Buzzer negatif uç -> GND

## Notlar
- ESP32 analog okuma için GPIO34 kullanılabilir.
- MQ sensör modülünde çoğu zaman AO (analog çıkış) pini kullanılır.
- Sensörün doğru PPM ölçümü için kalibrasyon gereklidir.
- 5V ve GND hatlarının doğru bağlandığından emin olun.
