#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);  // Inicia la comunicació per Serial (USB)
  SerialBT.begin("ESP32test"); // Defineix el nom Bluetooth del dispositiu
  Serial.println("The device started, now you can pair it with Bluetooth!");
}

void loop() {
    if (Serial.available()) {
      SerialBT.write(Serial.read());
    }
    if (SerialBT.available()) {
      Serial.write(SerialBT.read());
    }
    delay(20);
  }
  if (Serial.available()) {    
      SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
      Serial.write(SerialBT.read());
  }
delay(20);

}

