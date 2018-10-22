#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_TSL2591.h"
#include "Adafruit_HTU21DF.h"

// Connect Vin to 3.3V
// Connect GND to ground
// Connect SCL to P6.5
// Connect SDA to P6.4

Adafruit_TSL2591 tsl = Adafruit_TSL2591();
Adafruit_HTU21DF htu = Adafruit_HTU21DF();

// Configures the gain and integration time for the TSL2591
void configureSensor(void)
{
  // You can change the gain on the fly, to adapt to brighter/dimmer light situations
  //tsl.setGain(TSL2591_GAIN_LOW);    // 1x gain (bright light)
  tsl.setGain(TSL2591_GAIN_MED);      // 25x gain
  //tsl.setGain(TSL2591_GAIN_HIGH);   // 428x gain
  
  // Changing the integration time gives you a longer time over which to sense light
  // longer timelines are slower, but are good in very low light situtations!
  //tsl.setTiming(TSL2591_INTEGRATIONTIME_100MS);  // shortest integration time (bright light)
  // tsl.setTiming(TSL2591_INTEGRATIONTIME_200MS);
  tsl.setTiming(TSL2591_INTEGRATIONTIME_300MS);
  // tsl.setTiming(TSL2591_INTEGRATIONTIME_400MS);
  // tsl.setTiming(TSL2591_INTEGRATIONTIME_500MS);
  // tsl.setTiming(TSL2591_INTEGRATIONTIME_600MS);  // longest integration time (dim light)
}

void advancedRead(int* red, int* spec)
{
  // More advanced data read example. Read 32 bits with top 16 bits IR, bottom 16 bits full spectrum
  // That way you can do whatever math and comparisons you want!
  uint32_t lum = tsl.getFullLuminosity();
  *red = lum >> 16;
  *spec = lum & 0xFFFF;
}

void setup() {
  Serial.begin(9600);
  if (!htu.begin()) {
    Serial.println("Couldn't find HTU sensor!");
    while (1);
  }
  if (!tsl.begin()) {
    Serial.println("Couldn't find TSL sensor!");
    while (1);
  }
  /* Configure the TSL sensor */
  configureSensor();
}

void loop() {
    uint16_t ir, full;
    float temp = htu.readTemperature();
    float rel_hum = htu.readHumidity();

    advancedRead(&ir, &full);
    Serial.print("Temp = "); Serial.print(temp); Serial.print(" ");
    Serial.print("Humidity = "); Serial.print(rel_hum); Serial.println();
    Serial.print("IR = "); Serial.print(ir); Serial.print(" ");
    Serial.print("Full = "); Serial.print(full); Serial.println();
    delay(500);
}
