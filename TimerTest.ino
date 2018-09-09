#include <Adafruit_LEDBackpack.h>

Adafruit_7segment matrix = Adafruit_7segment();

unsigned long start_time = 0;
unsigned long duration = (15UL * 60UL * 1000UL); // Minutes to ms

void setup() {
  Serial.begin(115200);
  matrix.begin(0x70);
  start_time = millis();
  Serial.print("Boot time: ");
  Serial.println(start_time);
}

void loop() {
  unsigned long remaining = duration - millis() + start_time;
  unsigned long seconds = remaining / 1000;
  unsigned long minutes = seconds / 60;
  seconds = seconds % 60;
  unsigned long display_val = (minutes * 100) + seconds;

  matrix.print(display_val, DEC);
  matrix.drawColon(true);
  matrix.writeDisplay();
  delay(1000);
}
