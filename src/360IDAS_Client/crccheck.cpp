#include "crccheck.h"

CRCcheck* CRCcheck::crcCheck_ins=nullptr;

CRCcheck *CRCcheck::getInstance()
{
    if(CRCcheck::crcCheck_ins==nullptr)
    {
        CRCcheck::crcCheck_ins=new CRCcheck();
    }
    return CRCcheck::crcCheck_ins;
}

unsigned int CRCcheck::calculateCRC(char *data, int length)
{
    unsigned int crc = 0xFFFFFFFF; // 初始值为全1
    for (int i = 0; i < length; i++) {
        unsigned char index = (crc ^ data[i]) & 0xFF;
        crc = (crc >> 8) ^ crcTable[index];
    }
    crc ^= 0xFFFFFFFF; // 最后异或0xFFFFFFFF
    return crc;
}

CRCcheck::CRCcheck()
{
    unsigned int polynomial = 0xEDB88320; // CRC32多项式
    for (unsigned int i = 0; i < 256; i++) {
        unsigned int crc = i;
        for (int j = 0; j < 8; j++) {
            if (crc & 1) {
                crc = (crc >> 1) ^ polynomial;
            }
            else {
                crc >>= 1;
            }
        }
        crcTable[i] = crc;
    }
}
