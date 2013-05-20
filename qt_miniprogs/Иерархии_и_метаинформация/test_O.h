#ifndef TEST_O_H
#define TEST_O_H

#include <QtCore>

// Макрос Q_OBJECT нужен не только для слотов и сигналов, но и для правильной метаинформации.
class test_O : public QObject {
    Q_OBJECT

    public:
        test_O (test_O * p = 0) : QObject(p) {}
        ~test_O () {
            qDebug() << "Удаляется объект: " << objectName();
        }
};

#endif // TEST_O_H
