#ifndef TOOLS_H
#define TOOLS_H
#include <QString>
#include <QCryptographicHash>//MD5加密

class Tools
{
public:
    Tools();
    static QString generateMD5(const QString &value);
};

#endif // TOOLS_H
