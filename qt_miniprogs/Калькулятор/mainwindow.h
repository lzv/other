#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>

class MainWindow : public QWidget {
    Q_OBJECT
    
	private:
		QLCDNumber * displ;
		QStack<QString> stk;
		QString dstr;

	public:
		MainWindow (QWidget * = 0);

		QPushButton * createButton (const QString &);
		void calculate ();
		double calculate_req ();
		bool is_operation (const QChar &);

	public slots:
		void ButtonClicked ();
};

#endif // MAINWINDOW_H
