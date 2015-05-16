/*
  Copyright 2014 Marcus Sorensen <marcus@electron14.com>

This program is licensed under the GNU GPL v2
*/
#ifndef si7021_h
#define si7021_h
#include <Wire.h>

typedef struct si7021_env {
    int celsiusHundredths;
    int fahrenheitHundredths;
    unsigned int humidityBasisPoints;
} si7021_env;

class SI7021
{
  public:
    SI7021();
    bool begin();
    bool sensorExists();
    int getFahrenheitHundredths();
    int getCelsiusHundredths();
    unsigned int getHumidityPercent();
    unsigned int getHumidityBasisPoints();
    struct si7021_env getHumidityAndTemperature();
    int getSerialBytes(uint8_t * buf);
    int getDeviceId();
    void setHeater(bool on);
  private:
    void _command(uint8_t * cmd, uint8_t * buf );
    void _writeReg(uint8_t * reg, int reglen);
    int _readReg(uint8_t * reg, int reglen);
    int _getCelsiusPostHumidity();
};

#endif

