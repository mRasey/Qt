#include "MyThread.h"

void MyThread::run() {
	udp->loop();
}

MyThread::MyThread(UDP& w)
{
	udp = &w;
}

MyThread::~MyThread()
{
}
