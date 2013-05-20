#include <QtGui>

int main(int argc, char *argv[])
{
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
//    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForCStrings(codec);
//    QTextCodec::setCodecForLocale(codec);

    QApplication a(argc, argv);
    QLabel lbl("Привет мир!");
    lbl.setWindowTitle("Привет мир!");
    QDesktopWidget * desktop = QApplication::desktop();
    int width = desktop->width();
    int height = desktop->height();
    lbl.move(width/2 - 100, height/2 - 50);
    lbl.resize(200, 100);
    lbl.setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QPixmap pix(":/mouse_icon.png");
    QCursor cur(pix);
    lbl.setCursor(cur);
    lbl.show();
    return a.exec();
}
