#include "mainwindow.h"

int main(int argc, char *argv[])
{
	QTextCodec * codec = QTextCodec::codecForName("UTF-8");
//	QTextCodec::setCodecForTr(codec);
	QTextCodec::setCodecForCStrings(codec);
//	QTextCodec::setCodecForLocale(codec);

	QApplication app (argc, argv);

	MainWindow calculator;
	calculator.setWindowTitle("Калькулятор");
	calculator.resize(200, 250);
	QDesktopWidget * desktop = QApplication::desktop();
	calculator.move(desktop->width()/2 - 100, desktop->height()/2 - 150);
	calculator.show();
    
	return app.exec();
}
