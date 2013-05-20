#include "main_window.h"

int main(int argc, char *argv[])
{
    QTextCodec * codec = QTextCodec::codecForName("UTF-8");
//    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForCStrings(codec);
//    QTextCodec::setCodecForLocale(codec);

    int mainW = 270, mainH = 200;
    int mainHW = mainW/2, mainHH = mainH/2;

    QApplication a(argc, argv);
    MainWindow main_widget;

    QWidget * main_in = new QWidget();
    main_in->setFixedSize(mainW, mainH);
    main_widget.setWidget(main_in);

    QWidget * pwgt1 = new QWidget(main_in);
    QPalette pal1;
    pal1.setColor(pwgt1->backgroundRole(), QColor(100, 255, 100));
    pwgt1->setPalette(pal1);
    pwgt1->resize(100, 100);
    pwgt1->move(mainHW - 75, 25);
    pwgt1->setAutoFillBackground(true);

    QWidget * pwgt2 = new QWidget(main_in);
    QPalette pal2;
    pal2.setBrush(pwgt2->backgroundRole(), QBrush(QPixmap(":/back_img.png")));
    pwgt2->setPalette(pal2);
    pwgt2->resize(100, 100);
    pwgt2->move(mainHW - 25, 75);
    pwgt2->setAutoFillBackground(true);

    QFrame * borders = new QFrame(main_in);
    borders->setFrameStyle(QFrame::Box | QFrame::Raised);
    borders->setLineWidth(5);
    borders->resize(100, 100);
    borders->move(mainHW - 50, mainHH - 50);
//  borders->setAutoFillBackground(true);

    QPushButton * toUp = new QPushButton("вверх", main_in);
    QPushButton * toDown = new QPushButton("вниз", main_in);
    QPushButton * toLeft = new QPushButton("влево", main_in);
    QPushButton * toRight = new QPushButton("вправо", main_in);
    toUp->setObjectName("Up");
    toUp->resize(60, 24);
    toUp->move(mainHW - 30, 5);
    toDown->setObjectName("Down");
    toDown->resize(60, 24);
    toDown->move(mainHW - 30, mainH - 29);
    toLeft->setObjectName("Left");
    toLeft->resize(60, 24);
    toLeft->move(5, mainHH - 12);
    toRight->setObjectName("Right");
    toRight->resize(60, 24);
    toRight->move(mainW - 65, mainHH - 12);

    QObject::connect(toUp, SIGNAL(clicked()), & main_widget, SLOT(needMove()));
    QObject::connect(toDown, SIGNAL(clicked()), & main_widget, SLOT(needMove()));
    QObject::connect(toLeft, SIGNAL(clicked()), & main_widget, SLOT(needMove()));
    QObject::connect(toRight, SIGNAL(clicked()), & main_widget, SLOT(needMove()));

    QDesktopWidget * desktop = QApplication::desktop();
    main_widget.setWindowTitle("Геометрия кнопки фон");
    main_widget.resize(mainW + 2, mainH + 2);
    main_widget.move(desktop->width()/2 - mainHW, desktop->height()/2 - mainHH);
    main_widget.show();
    
    return a.exec();
}
