#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <qthread.h>
#include "udp.h"

class MyThread : public QThread
{
public:
	MyThread(UDP& w);
	~MyThread();
	void run();

private:
	UDP* udp;
};


#endif // MYTHREAD_H