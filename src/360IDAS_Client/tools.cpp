#include "tools.h"

Tools::Tools()
{

}

QString Tools::generateMD5(const QString &value)
{
    QString md5;
    QByteArray bb;
    bb=QCryptographicHash::hash(value.toUtf8(),QCryptographicHash::Md5);
    md5.append(bb.toHex());
    return md5;
}
