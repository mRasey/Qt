#include <QtWidgets/QApplication>
#include "MyThread.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	UDP w;
	MyThread* m = new MyThread(w);
	w.show();
	m->start();//������Ϣ�߳�
	return a.exec();
}

