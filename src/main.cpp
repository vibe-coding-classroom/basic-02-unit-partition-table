#include <Arduino.h>
#include <Preferences.h>
#include <LittleFS.h>

Preferences preferences;

void setup() {
    Serial.begin(115200);
    delay(1000);

    Serial.println("\n--- ESP32 Partition Table & Persistence Lab ---");

    // 任務 2: NVS 參數持久化 (Preferences)
    // TODO: 實作一個能自動記錄「開機累計次數」的功能
    preferences.begin("my-app", false);
    unsigned int counter = preferences.getUInt("counter", 0);
    counter++;
    Serial.printf("Current Boot Count: %u\n", counter);
    preferences.putUInt("counter", counter);
    preferences.end();

    // 任務 3: LittleFS 檔案部署
    // TODO: 掛載 LittleFS 並從 Flash 讀取 /index.html
    if (!LittleFS.begin(true)) {
        Serial.println("LittleFS Mount Failed");
        return;
    }

    File file = LittleFS.open("/index.html", "r");
    if (!file) {
        Serial.println("Failed to open /index.html for reading");
        return;
    }

    Serial.println("--- Content of /index.html ---");
    while (file.available()) {
        Serial.write(file.read());
    }
    Serial.println("\n-----------------------------");
    file.close();
}

void loop() {
    // Nothing here for this lab
}
