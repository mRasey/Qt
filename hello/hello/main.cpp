#include "hello.h"
#include <QtWidgets\QApplication>
#include <QtWidgets\qlabel.h>
#include <QtWidgets\qpushbutton.h>

int main(int argc, char *argv[]){
	QApplication a(argc, argv);
	//QPushButton *button = new QPushButton("quit");
	//QObject::connect(button, SIGNAL(clicked()), &a, SLOT(quit()));
	//button->show();
	//QLabel *q = new QLabel("hello qt");
	//q->show();
	QPushButton *send = new QPushButton("");
	hello w;
	w.show();
	return a.exec();
}
