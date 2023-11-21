#ifndef DATACONFIG_H
#define DATACONFIG_H

#include <QObject>
#include <QMap>

class dataConfig : public QObject
{
    Q_OBJECT
public:
    explicit dataConfig(QObject *parent = nullptr);
    QMap<int, QVector<QVector<int>>> mData;
private:
    void matrix1();
    void matrix2();
    void matrix3();
    void matrix4();
    void matrix5();
    void matrix6();
    void matrix7();
    void matrix8();
    void matrix9();
    void matrix10();
    void matrix11();
    void matrix12();
    void matrix13();
    void matrix14();
    void matrix15();
    void matrix16();
    void matrix17();
    void matrix18();
    void matrix19();
    void matrix20();


signals:

};

#endif // DATACONFIG_H
