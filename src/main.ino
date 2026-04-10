#include <WiFi.h>
#include <HTTPClient.h>

#define MQ_PIN 34
#define LED_PIN 18
#define BUZZER_PIN 19

const char* ssid = "WIFI_ADIN";
const char* password = "WIFI_SIFREN";

// PHP endpoint örneği: http://192.168.1.10/gazppm/insert_data.php
const char* serverUrl = "http://SUNUCU_ADRESIN/insert_data.php";

const int ppmThreshold = 350;
const unsigned long sendInterval = 10000;

unsigned long previousMillis = 0;

float convertToPPM(int rawValue)
{
    // Bu dönüşüm örnek amaçlıdır.
    // Kullandığın MQ sensörüne göre gerçek kalibrasyon yapılmalıdır.
    return (rawValue / 4095.0) * 1000.0;
}

void connectWiFi()
{
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("WiFi baglaniyor...");
    }

    Serial.println("WiFi baglandi.");
    Serial.print("IP Adresi: ");
    Serial.println(WiFi.localIP());
}

void setup()
{
    Serial.begin(115200);

    pinMode(LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);

    connectWiFi();
}

void loop()
{
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= sendInterval)
    {
        previousMillis = currentMillis;

        int sensorRaw = analogRead(MQ_PIN);
        float ppm = convertToPPM(sensorRaw);

        bool alarmState = ppm >= ppmThreshold;

        digitalWrite(LED_PIN, alarmState ? HIGH : LOW);
        digitalWrite(BUZZER_PIN, alarmState ? HIGH : LOW);

        Serial.print("Ham Deger: ");
        Serial.print(sensorRaw);
        Serial.print(" | PPM: ");
        Serial.print(ppm);
        Serial.print(" | Alarm: ");
        Serial.println(alarmState ? "AKTIF" : "PASIF");

        if (WiFi.status() == WL_CONNECTED)
        {
            HTTPClient http;
            http.begin(serverUrl);
            http.addHeader("Content-Type", "application/x-www-form-urlencoded");

            String postData = "ppm=" + String(ppm, 2) +
                              "&raw_value=" + String(sensorRaw) +
                              "&alarm=" + String(alarmState ? 1 : 0);

            int httpResponseCode = http.POST(postData);

            Serial.print("HTTP Cevap Kodu: ");
            Serial.println(httpResponseCode);

            if (httpResponseCode > 0)
            {
                String response = http.getString();
                Serial.println("Sunucu Yaniti: " + response);
            }

            http.end();
        }
        else
        {
            Serial.println("WiFi baglantisi yok.");
        }
    }
}
