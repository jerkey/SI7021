#include <Wire.h>
#include <SI7021.h>

// for use with MPIDE / UNO32 / Pic32mx320f128h as seen here:
// http://www.digilentinc.com/Products/Detail.cfm?Prod=CHIPKIT-UNO32

SI7021 sensor;

void setup() {
  Serial.begin(115200);
  Serial.println("reading an SI7020 temperature / humidiy sensor");
    sensor.begin();
}


void loop() {

    // temperature is an integer in hundredths
    int temperature = sensor.getCelsiusHundredths();
    Serial.print((float)temperature / 100.0);
    Serial.print("C, ");
    
    // humidity is an integer representing percent
    int humidity = sensor.getHumidityPercent();
    Serial.print(humidity);
    Serial.print("%RH, ");
    
    // this driver should work for SI7020 and SI7021, this returns 20 or 21
    int deviceid = sensor.getDeviceId();
    Serial.print(deviceid);
    Serial.print(" devID, ");

    // enable internal heater for testing
    sensor.setHeater(true);
    delay(10000);
    sensor.setHeater(false);
    
    // see if heater changed temperature
    temperature = sensor.getCelsiusHundredths();
    Serial.print((float)temperature / 100.0);
    Serial.print("C after heater, ");

    // get humidity and temperature in one shot, saves power because sensor takes temperature when doing humidity anyway
    si7021_env data = sensor.getHumidityAndTemperature();
    Serial.print((float)data.celsiusHundredths / 100.0);
    Serial.print("C2, ");
    Serial.print((float)data.humidityBasisPoints / 100.0);
    Serial.println("%RH2, ");
    delay(1000);
}
