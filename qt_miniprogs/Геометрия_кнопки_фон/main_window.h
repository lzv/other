#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtGui>

class MainWindow : public QScrollArea {
    Q_OBJECT

public:
    MainWindow (QWidget * parent = 0) : QScrollArea(parent) {}

public slots:
    void needMove () {
        int corrX = 0, corrY = 0;
        QString name = sender()->objectName();
        if (name == "Up") corrY -= 5;
        else if (name == "Down") corrY += 5;
        else if (name == "Left") corrX -= 5;
        else if (name == "Right") corrX += 5;
        move(x() + corrX, y() + corrY);
        QPoint mpos = QCursor::pos() + QPoint(corrX, corrY);
        QCursor::setPos(mpos);
    }
};

#endif // MAIN_WINDOW_H
