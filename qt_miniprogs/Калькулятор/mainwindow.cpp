#include "mainwindow.h"

MainWindow::MainWindow (QWidget * parent) : QWidget(parent)
{
	displ = new QLCDNumber(12);
	displ->setSegmentStyle(QLCDNumber::Flat);
	displ->setMinimumSize(200, 40);
	displ->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
	displ->display("HELLO");

	QChar buttons[5][4] = {{'C', '/', '*', '-'},
							{'7', '8', '9', 0},
							{'4', '5', '6', 0},
							{'1', '2', '3', 0},
							{0, 0, '.', 0}};

	QGridLayout * ptopLayout = new QGridLayout;
	ptopLayout->setSpacing(0);
	ptopLayout->setMargin(5);
	ptopLayout->addWidget(displ, 0, 0, 1, 4);
	ptopLayout->addWidget(createButton("+"), 2, 3, 2, 1);
	ptopLayout->addWidget(createButton("="), 4, 3, 2, 1);
	ptopLayout->addWidget(createButton("0"), 5, 0, 1, 2);
	for (short int i = 0; i < 5; ++i)
		for (short int j = 0; j < 4; ++j)
			if (buttons[i][j] != 0) ptopLayout->addWidget(createButton(buttons[i][j]), i + 1, j);

	setLayout(ptopLayout);
}

QPushButton * MainWindow::createButton(const QString & val)
{
	QPushButton * btn = new QPushButton(val);
	btn->setMinimumSize(40, 40);
	btn->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
	btn->setStyleSheet("background-color: rgb(220, 220, 220)");
	connect(btn, SIGNAL(clicked()), SLOT(ButtonClicked()));
	return btn;
}

bool MainWindow::is_operation (const QChar & val)
{
	return val == '/' or val == '*' or val == '-' or val == '+';
}

void MainWindow::ButtonClicked()
{
	QString str = qobject_cast<QPushButton *>(sender())->text();
	if (str == "C") {
		stk.clear();
		dstr = "";
		displ->display("0");
	} else if (str.contains(QRegExp("[0-9]")) or str == ".") {
		if (dstr.length() < 12 and (str != "." or !dstr.contains(QRegExp("\\.")))) {
			dstr += str;
			displ->display(dstr);
		}
	} else if (is_operation(str.at(0))) {
		if (dstr.length() > 0) {
			stk.push(dstr);
			stk.push(str);
			dstr = "";
		}
	} else if (str == "=") {
		stk.push(dstr.length() > 0 ? dstr : QString().setNum(displ->value()));
		dstr = "";
		calculate();
	}
}

double MainWindow::calculate_req ()
{
	if (stk.size() == 0) {
		return 0;
	} else if (stk.size() == 1) {
		return stk.pop().toDouble();
	} else {
		double val2 = stk.pop().toDouble();
		QString oper = stk.pop();
		double val1 = calculate_req();
		double result = 0;
		if (oper == "+") result = val1 + val2;
		else if (oper == "-") result = val1 - val2;
		else if (oper == "*") result = val1 * val2;
		else if (oper == "/") result = val1 / val2;
		return result;
	}
}

void MainWindow::calculate()
{
	double result = calculate_req();
	displ->display(result);
}
