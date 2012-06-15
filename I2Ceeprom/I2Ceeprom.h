/*
  I2Ceeprom.h - Library for reading/writing 24AAxxxx/24LCxxxx/25LCxxxx eeproms
  Created by Mike Cherry <mcherry@inditech.org> 06/14/2012
  From code examples at http://arduino.cc/playground/Code/I2CEEPROM
  Released into the public domain.
*/

#ifndef I2Ceeprom_h
#define I2Ceeprom_h

#include "Arduino.h"

class I2Ceeprom
{
    public:
        I2Ceeprom(int device);
        void WriteByte(unsigned int address, byte data);
        void WritePage(unsigned int address, byte *data, byte length);
        byte ReadByte(unsigned int address);
        void ReadBuffer(unsigned int address, byte *buffer, int length);
    private:
        int _device;
};

#endif
