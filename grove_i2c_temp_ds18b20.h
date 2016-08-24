/*
 * grove_i2c_temp_ds18b20.h
 *
 * Copyright (c) 2012 seeed technology inc.
 * Website    : www.seeed.cc
 * Author     : Lambor, Jack
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


#ifndef __GROVE_I2C_TEMP_DS18B20_H__
#define __GROVE_I2C_TEMP_DS18B20_H__

#include "suli2.h"

//GROVE_NAME        "Grove - I2C Temp (DS18B20)"
//SKU               101020112396122
//IF_TYPE           I2C
//IMAGE_URL         https://statics3.seeedstudio.com/images/product/onewiretempsensor.jpg
//DESCRIPTION       "Driver for DS18B20 de SeeedStudio"
//WIKI_URL          http://www.rizoma.io
//ADDED_AT          "2016-08-24"
//AUTHOR            "Rodrigo Moya Toro - rodrigo@rizoma.io"

#define ONE_WIRE_BUS 2

class GroveI2CTempDs18b20
{
public:
    GroveI2CTempDs18b20(int pinsda, int pinscl);
    bool read_temperature(float *temperature);

private:
    I2C_T *i2c;
};

#endif
