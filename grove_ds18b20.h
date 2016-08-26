/*
 * grove_ds18b20.h
 *
 * Copyright (c) 2012 seeed technology inc.
 * Website    : www.seeed.cc
 * Author     : Kai 
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


#ifndef __GROVE_DS18B20_H__
#define __GROVE_DS18B20_H__

#include "suli2.h"

//GROVE_NAME        "Grove_ds18b20"
//SKU               0497dd7c-2faf-4ccb-900d-9a8f3b099fed 
//IF_TYPE           GPIO
//IMAGE_URL         http://i.imgur.com/McTQZjy.jpg 


class GroveDs18b20
{
public:
    GroveDs18b20(int pin);
    
    /**
     * get the number of devices at the bus 
     * 
     * @param device_count - count of devices  
     * 
     * @return bool 
     */
    bool read_device_count(uint8_t *device_count);

    /**
     * read the temperature of device with number device_index 
     * 
     * @param device_index - number of device to read from (1~n) 
     * @param celsius_degree - unit: Celsius degree 
     * 
     * @return bool 
     */
    bool read_temperature_C(uint8_t device_index, float *celsius_degree);

    /**
     * read the temperature of device with number device_index 
     * 
     * @param device_count - number of device to read from (1~n) 
     * @param fahrenheit_degree - unit: Fahrenheit degree 
     * 
     * @return bool 
     */
    bool read_temperature_F(uint8_t device_index, float *fahrenheit_degree);

    char *get_last_error() { return error_desc; };

private:
    char *error_desc;

};


#endif