#include "read.h"
#include <QDebug>
read::read()
{
    this->loc = "C:/Users/Abhi/Desktop/config.json";
}

void read::setloc(QString loc)
{
    this->loc = loc;
}

QString read::getloc(QString loc)
{
    return this->loc;
}

QVariantMap read::readjson()
{
    QFile file(this->loc);
    file.open(QIODevice::ReadOnly);

    QTextStream file_text(&file);
    QString json_string;
    json_string = file_text.readAll();
    file.close();
    QByteArray json_bytes = json_string.toLocal8Bit();
    auto json_doc = QJsonDocument::fromJson(json_bytes);

    QJsonObject json_obj = json_doc.object();

    QVariantMap json_map = json_obj.toVariantMap();

    QString val1 =  json_map["background"].toString();
    QString val2 = json_map["velocity"].toString();
    QString val3 = json_map["xposition"].toString();
    QString val4 = json_map["height"].toString();

    return json_map;
}
