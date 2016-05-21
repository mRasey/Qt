#include <QtWidgets/QApplication>
#include "MyThread.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	UDP w;
	MyThread* m = new MyThread(w);
	w.show();
	m->start();//接受消息线程
	return a.exec();
}

