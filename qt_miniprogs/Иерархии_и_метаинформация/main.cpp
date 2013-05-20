#include "test_O.h"

int main(int argc, char** argv)
{
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
//    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForLocale(codec);

    test_O * t1 = new test_O;
    test_O * t2 = new test_O(t1);
    test_O * t3 = new test_O(t1);
    test_O * t4 = new test_O(t2);
    t1->setObjectName("object 1");
    t2->setObjectName("object 2");
    t3->setObjectName("object 3");
    t4->setObjectName("object 4");

    QString info1 = "Для объекта t4 родительский объект: ";
    info1 += t4->parent()->objectName();
    qDebug() << info1;

    QString info2 = "Для объекта t1 дочерние объекты: ";
    QList<QObject *> ch = t1->children();
    QList<QObject *>::size_type i, num = ch.size();
    for (i = 0; i < num; ++i) {
        info2 += ch[i]->objectName();
        if (i < num - 1) info2 += ", ";
    }
    qDebug() << info2;

    t1->dumpObjectTree(); // У меня не работает - не отладочная версия Qt.
    t1->dumpObjectInfo(); // Аналогично.

    qDebug() << "Название класса объекта t1: " << t1->metaObject()->className();
    qDebug() << "Наследован ли он от QWidget: " << (t1->inherits("QWidget") ? "да" : "нет");
    qDebug() << "Наследован ли он от QObject: " << (t1->inherits("QObject") ? "да" : "нет");

    delete t1; // Все дочерние в иерархии удаляются автоматически.

    return 0;
}
