#include <QtWidgets/QApplication>
#include "udp.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	UDP w;
	w.show();
	return a.exec();
}

