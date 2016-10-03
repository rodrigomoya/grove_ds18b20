/*
 * grove_ds18b20.cpp
 *
 * Website    : www.rizoma.io
 * Author     : Rodrigo Moya (rodrigo@rizoma.io)
 *
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "grove_ds18b20.h"
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 5  // DS18B20 on Digital Port 1 = pin 12 look at http://www.seeedstudio.com/wiki/Wio_Link

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);

GroveDs18b20::GroveDs18b20(int pin)
{
    DS18B20.begin();/* Inizialisieren der Dallas Temperature library */
}

/* read count of devices */
bool GroveDs18b20::read_device_count(uint8_t *count)
{
    *count = DS18B20.getDeviceCount();

    return true;
}

/* read temperature of first device in Celsius */
bool GroveDs18b20::read_temperature(uint8_t index, float *temperature)
{
    
    DS18B20.requestTemperatures(); // Temp abfragen

    if (index < 1 || index > DS18B20.getDeviceCount())
    {
        error_desc = "there is no device with this device number";
        return false;
    }

    *temperature = DS18B20.getTempCByIndex(index - 1);

    return true;
}