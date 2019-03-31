#ifndef READ_H
#define READ_H
#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <iostream>
#include <QTextStream>

class read
{
public:
    read();
    void setloc(QString loc);
    QString getloc(QString loc);
    QVariantMap readjson();

private:
    QString loc;

};

#endif // READ_H
