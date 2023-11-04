#ifndef CRCCHECK_H
#define CRCCHECK_H

class CRCcheck
{
public:
    static CRCcheck* getInstance();
    unsigned int calculateCRC(char* data, int length);
private:
    CRCcheck();
    static CRCcheck* crcCheck_ins;
    unsigned int crcTable[256];
};

#endif // CRCCHECK_H
