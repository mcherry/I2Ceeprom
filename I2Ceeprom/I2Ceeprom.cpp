/*
  I2Ceeprom.cpp - Library for reading/writing 24AAxxxx/24LCxxxx/25LCxxxx eeproms
  Created by Mike Cherry <mcherry@inditech.org> 06/14/2012
  From code examples at http://arduino.cc/playground/Code/I2CEEPROM
  Released into the public domain.
*/

#include "Wire.h"
#include "Arduino.h"
#include "I2Ceeprom.h"

I2Ceeprom::I2Ceeprom(int device)
{
    _device = device;
}

void I2Ceeprom::WriteByte(unsigned int address, byte data)
{
    int rdata = data;
    
    Wire.beginTransmission(_device);
    Wire.write((int)(address >> 8));
    Wire.write((int)(address & 0xFF));
    Wire.write(rdata);
    Wire.endTransmission();
    
    delay(10);
}

void I2Ceeprom::WritePage(unsigned int address, byte *data, byte length)
{
    byte c;
    
    Wire.beginTransmission(_device);
    Wire.write((int)(address >> 8));
    Wire.write((int)(address & 0xFF));
    
    for ( c = 0; c < length; c++)
    {
      Wire.write(data[c]);
    }
    
    Wire.endTransmission();
    
    delay(10);
}

byte I2Ceeprom::ReadByte(unsigned int address)
{
    byte rdata = 0xFF;
    
    Wire.beginTransmission(_device);
    Wire.write((int)(address >> 8));
    Wire.write((int)(address & 0xFF));
    Wire.endTransmission();
    Wire.requestFrom(_device,1);
    
    if (Wire.available())
    {
        rdata = Wire.read();
    }
    
    return rdata;
}

void I2Ceeprom::ReadBuffer(unsigned int address, byte *buffer, int length)
{
    int c = 0;
    
    Wire.beginTransmission(_device);
    Wire.write((int)(address >> 8));
    Wire.write((int)(address & 0xFF));
    Wire.endTransmission();
    Wire.requestFrom(_device,length);
    
    for ( c = 0; c < length; c++ )
    {
        if (Wire.available())
        {
            buffer[c] = Wire.read();
        }
    }
}
