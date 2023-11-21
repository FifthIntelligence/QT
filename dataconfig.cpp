#include "dataconfig.h"

dataConfig::dataConfig(QObject *parent)
    : QObject{parent}
{
    this->matrix1();
    this->matrix2();
    this->matrix3();
    this->matrix4();
    this->matrix5();
    this->matrix6();
    this->matrix7();
    this->matrix8();
    this->matrix9();
    this->matrix10();
    this->matrix11();
    this->matrix12();
    this->matrix13();
    this->matrix14();
    this->matrix15();
    this->matrix16();
    this->matrix17();
    this->matrix18();
    this->matrix19();
    this->matrix20();
}

void dataConfig::matrix1()
{
    int array[4][4] = {     // 1-gold coin, 0- silver coin
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 0, 0, 0},
        {1, 1, 0, 1}
    };
    QVector<QVector<int>> v;
    for(int i = 0; i < 4; ++i){
        QVector<int>v1;
        for(int j = 0; j < 4; ++j){
            v1.push_back(array[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(1, v);
}

void dataConfig::matrix2()
{
    int array[4][4] = {
        {1, 0, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 0, 0},
        {1, 1, 0, 1}
    };
    QVector<QVector<int>> v;
    for(int i = 0; i < 4; ++i){
        QVector<int>v1;
        for(int j = 0; j < 4; ++j){
            v1.push_back(array[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(2, v);
}

void dataConfig::matrix3()
{
    int array[4][4] = {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {1, 0, 0, 1}
    };
    QVector<QVector<int>> v;
    for(int i = 0; i < 4; ++i){
        QVector<int>v1;
        for(int j = 0; j < 4; ++j){
            v1.push_back(array[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(3, v);
}

void dataConfig::matrix4()
{
    int array[4][4] = {
        {1, 1, 0, 1},
        {1, 1, 0, 1},
        {1, 0, 1, 1},
        {1, 0, 1, 1}
    };
    QVector<QVector<int>> v;
    for(int i = 0; i < 4; ++i){
        QVector<int>v1;
        for(int j = 0; j < 4; ++j){
            v1.push_back(array[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(4, v);
}

void dataConfig::matrix5()
{
    int array[4][4] = {
        {0, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 0}
    };
    QVector<QVector<int>> v;
    for(int i = 0; i < 4; ++i){
        QVector<int>v1;
        for(int j = 0; j < 4; ++j){
            v1.push_back(array[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(5, v);
}

void dataConfig::matrix6()
{
    int array[4][4] = {
        {1, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 0, 1}
    };
    QVector<QVector<int>> v;
    for(int i = 0; i < 4; ++i){
        QVector<int>v1;
        for(int j = 0; j < 4; ++j){
            v1.push_back(array[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(6, v);
}

void dataConfig::matrix7()
{
    int array[4][4] = {
        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {1, 0, 0, 1}
    };
    QVector<QVector<int>> v;
    for(int i = 0; i < 4; ++i){
        QVector<int>v1;
        for(int j = 0; j < 4; ++j){
            v1.push_back(array[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(7, v);
}

void dataConfig::matrix8()
{
    int array[4][4] = {
        {1, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 1, 0}
    };
    QVector<QVector<int>> v;
    for(int i = 0; i < 4; ++i){
        QVector<int>v1;
        for(int j = 0; j < 4; ++j){
            v1.push_back(array[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(8, v);
}

void dataConfig::matrix9()
{
    int array[4][4] = {
        {1, 0, 1, 1},
        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 1, 1, 1}
    };
    QVector<QVector<int>> v;
    for(int i = 0; i < 4; ++i){
        QVector<int>v1;
        for(int j = 0; j < 4; ++j){
            v1.push_back(array[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(9, v);
}

void dataConfig::matrix10()
{
    int array[4][4] = {
        {1, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 0, 1, 1}
    };
    QVector<QVector<int>> v;
    for(int i = 0; i < 4; ++i){
        QVector<int>v1;
        for(int j = 0; j < 4; ++j){
            v1.push_back(array[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(10, v);
}

void dataConfig::matrix11()
{
    int array[4][4] = {
        {1, 0, 1, 1},
        {1, 0, 1, 1},
        {0, 0, 1, 1},
        {1, 0, 1, 1}
    };
    QVector<QVector<int>> v;
    for(int i = 0; i < 4; ++i){
        QVector<int>v1;
        for(int j = 0; j < 4; ++j){
            v1.push_back(array[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(11, v);
}

void dataConfig::matrix12()
{
    int array[4][4] = {
        {0, 0, 0, 1},
        {1, 1, 0, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1}
    };
    QVector<QVector<int>> v;
    for(int i = 0; i < 4; ++i){
        QVector<int>v1;
        for(int j = 0; j < 4; ++j){
            v1.push_back(array[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(12, v);
}

void dataConfig::matrix13()
{
    int array[4][4] = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };
    QVector<QVector<int>> v;
    for(int i = 0; i < 4; ++i){
        QVector<int>v1;
        for(int j = 0; j < 4; ++j){
            v1.push_back(array[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(13, v);
}

void dataConfig::matrix14()
{
    int array[4][4] = {
        {1, 1, 1, 1},
        {0, 0, 0, 1},
        {1, 1, 0, 1},
        {1, 1, 0, 1}
    };
    QVector<QVector<int>> v;
    for(int i = 0; i < 4; ++i){
        QVector<int>v1;
        for(int j = 0; j < 4; ++j){
            v1.push_back(array[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(14, v);
}

void dataConfig::matrix15()
{
    int array[4][4] = {
        {0, 0, 1, 1},
        {1, 0, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 0}
    };
    QVector<QVector<int>> v;
    for(int i = 0; i < 4; ++i){
        QVector<int>v1;
        for(int j = 0; j < 4; ++j){
            v1.push_back(array[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(15, v);
}

void dataConfig::matrix16()
{
    int array[4][4] = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 0}
    };
    QVector<QVector<int>> v;
    for(int i = 0; i < 4; ++i){
        QVector<int>v1;
        for(int j = 0; j < 4; ++j){
            v1.push_back(array[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(16, v);
}

void dataConfig::matrix17()
{
    int array[4][4] = {
        {1, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1},
        {0, 1, 1, 1}
    };
    QVector<QVector<int>> v;
    for(int i = 0; i < 4; ++i){
        QVector<int>v1;
        for(int j = 0; j < 4; ++j){
            v1.push_back(array[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(17, v);
}

void dataConfig::matrix18()
{
    int array[4][4] = {
        {0, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 1, 0, 0},
        {1, 0, 0, 0}
    };
    QVector<QVector<int>> v;
    for(int i = 0; i < 4; ++i){
        QVector<int>v1;
        for(int j = 0; j < 4; ++j){
            v1.push_back(array[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(18, v);
}

void dataConfig::matrix19()
{
    int array[4][4] = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 0, 0, 0},
        {1, 1, 0, 1}
    };
    QVector<QVector<int>> v;
    for(int i = 0; i < 4; ++i){
        QVector<int>v1;
        for(int j = 0; j < 4; ++j){
            v1.push_back(array[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(19, v);
}

void dataConfig::matrix20()
{
    int array[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    QVector<QVector<int>> v;
    for(int i = 0; i < 4; ++i){
        QVector<int>v1;
        for(int j = 0; j < 4; ++j){
            v1.push_back(array[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(20, v);
}
