#ifndef UDP_H
#define UDP_H


#include <QtWidgets/QMainWindow>
#include <windows.h>
#include <qtextcodec>
#include <iostream>
#include <fstream>
#include <sstream>
#include <QKeyEvent>
#include <string.h>
#include <atlstr.h>
//#include <WinSock2.h>
#include <winnetwk.h>
#include <map>
#include "ui_udp.h"

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "mpr.lib")

using namespace std;

class UDP : public QMainWindow
{
	Q_OBJECT

public:
	UDP(QWidget *parent = 0);
	~UDP();
	bool eventFilter(QObject* obj, QEvent* e);
	void flushIpList();
	void findMyIp();
	void receiveFromServer();
	void loop();

//private:
public:
	Ui::UDPClass ui;
	SYSTEMTIME time;
	int oldTime;
	int lastTime;
	ostringstream ss;
	string t;
	map<string, string> names;
	string chatIp;
	string myIp;
	QListWidgetItem* old;
//	bool flag = FALSE;
	bool sendAble = false;//是否允许发送消息
	bool appointFlag = false;
	int port = 7001;
	WSADATA wsaData;
	SOCKET sserver, sclient;
	int IpLength;
	int send;
	int receive;
	char* receiveData;
	bool fBroadcast = TRUE;
	string sendMassege;//发出的信息
	struct sockaddr_in  serverAddr, clientAddr;
	ofstream recordFile;

private slots:
	void GetNameAndIp(); 
	void flushTextView();
	void getClickedIp(QListWidgetItem* newly);
	void getAppointIp();
};

#endif // UDP_H