#include "udp.h"

UDP::UDP(QWidget *parent)
	: QMainWindow(parent)
{
	IpLength = sizeof(serverAddr);
	std::locale chs("chs");
	recordFile.open("Record", std::ios::app);//打开以追加方式记录聊天记录的文件
	ui.setupUi(this);
	ui.appointIpEdit->setText("<font color=gray>" + QString::fromStdString("Please input IP here")  + "</font>");
	ui.dialogEdit -> installEventFilter(this);
	ui.MyIpLabel->tr("hello world");
	//GetNameAndIp();
	findMyIp();
	std::thread server_thread(&UDP::loop, this);
	server_thread.detach();
	QObject::connect(ui.sendButton, SIGNAL(clicked()), this, SLOT(flushTextView()));
	QObject::connect(ui.flushButton, SIGNAL(clicked()), this, SLOT(GetNameAndIp()));
	QObject::connect(ui.IpListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(getClickedIp(QListWidgetItem*)));
	QObject::connect(ui.appointIpButton, SIGNAL(clicked()), this, SLOT(getAppointIp()));

	QTextCodec::setCodecForLocale(QTextCodec::codecForName("system"));

	//建立客户端服务器
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		ui.dialogBrowser->append("Failed to load Winsock");
	}
	sserver = socket(AF_INET, SOCK_DGRAM, 0);
	sclient = socket(PF_INET, SOCK_DGRAM, 0);
	if (sserver == INVALID_SOCKET)
	{
		ui.dialogBrowser->append("socket()Failed：" + WSAGetLastError());
	}
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(port);
	serverAddr.sin_addr.S_un.S_addr = INADDR_ANY;

	clientAddr.sin_family = AF_INET;
	clientAddr.sin_port = htons(port);
	//clientAddr.sin_addr.S_un.S_addr = inet_addr(chatIp.c_str());
	if(bind(sserver, (sockaddr*)&serverAddr, sizeof(serverAddr)) != 0)
		ui.dialogBrowser->append("bind failed");
}

UDP::~UDP()
{

}

void UDP::flushTextView() 
//刷新输入框
{
	lastTime = time.wMinute;
	QString input = ui.dialogEdit->toPlainText();
	if (input.length() != 0 && sendAble) 
	{
		GetLocalTime(&time);
		ss << " "<< time.wYear << "\\" << time.wMonth << "\\" << time.wDay << " " << time.wHour << ":" << time.wMinute << ":" << time.wSecond;
		ui.dialogBrowser->append("<font color=gray>" + QString::fromStdString(ss.str()) + "</font>");
		ui.dialogBrowser->append("<font color=blue>" + input + "</font>");
		ui.dialogBrowser->moveCursor(QTextCursor::End);//将滚动条移动到底部
		recordFile << "Local to " + chatIp + "  " << ss.str() + "  " << input.toStdString() << std::endl;//记录到本地
		ss.str("");
		//发送给联系人服务器
		const char* send_buf = input.toStdString().c_str();
		memset(sendData, '\0', dataLen);
		strcpy(sendData, input.toStdString().c_str());
		clientAddr.sin_addr.S_un.S_addr = inet_addr(chatIp.c_str());
		send = sendto(sserver, sendData, dataLen, 0, (struct sockaddr*)&clientAddr, sizeof(clientAddr));
		if(send == -1)
			ui.dialogBrowser->append("send failed" + WSAGetLastError());
		ui.dialogEdit->clear();
	}
}

void UDP::receiveFromServer() {
	//从对方接收数据
	memset(receiveData, '\0', dataLen);
	receive = recvfrom(sserver, receiveData, dataLen, 0, (struct sockaddr*)&assistAddr, &IpLength);
	if (receive == 0) {
		ui.dialogBrowser->append("receive failed");
	}
	else if (receive == SOCKET_ERROR) {
		ui.dialogBrowser->append("receive error");
	}
	else {
		GetLocalTime(&time);
		ss << " " << time.wYear << "\\" << time.wMonth << "\\" << time.wDay << " " << time.wHour << ":" << time.wMinute << ":" << time.wSecond;
		ui.dialogBrowser->append("<font color=gray>" + QString::fromStdString(ss.str()) + "</font>");
		QTextCodec *tc = QTextCodec::codecForName("utf-8");
		ui.dialogBrowser->append("<font color=red>" + tc->toUnicode(receiveData) + "</font>");
		recordFile << chatIp + " to Local" + "  " << ss.str() + "  " << receiveData << std::endl;//记录到本地
		ss.str("");
	}
	ui.dialogBrowser->moveCursor(QTextCursor::End);//将滚动条移动到底部
}

bool UDP::eventFilter(QObject *obj, QEvent *e)
{
	Q_ASSERT(obj == ui.dialogEdit);
	if (e->type() == QEvent::KeyPress)
	{
		QKeyEvent *event = (QKeyEvent*)(e);
		if (event->key() == Qt::Key_Return && (event->modifiers() & Qt::ControlModifier))
		{
			flushTextView(); //发送消息的槽
			return true;
		}
	}
	return false;
}

void UDP::getClickedIp(QListWidgetItem* newly) {
	//获取被点击的联系人
	if (sendAble && appointFlag) {
		old->setBackgroundColor(Qt::white);
		old->setTextColor(Qt::black);
	}
	newly->setBackgroundColor(Qt::yellow);
	newly->setTextColor(Qt::red);
	old = newly;
	sendAble = true;
	ui.chatIpLabel->setText(newly->text() + ": " + QString::fromStdString(names[newly->text().toStdString()]));
	chatIp = names[newly->text().toStdString()];
	serverAddr.sin_addr.S_un.S_addr = inet_addr(newly->text().toStdString().c_str());
	appointFlag = true;
}

void UDP::findMyIp() {
//获取本机IP
	WORD v = MAKEWORD(1, 1);
	WSADATA wsaData;
	WSAStartup(v, &wsaData); // 加载套接字库  

	struct hostent *phostinfo = gethostbyname("");
	myIp = inet_ntoa(*((struct in_addr *)(*phostinfo->h_addr_list)));
	ui.MyIpLabel->setText(QString::fromStdString(phostinfo->h_name) + ": " + QString::fromStdString(myIp));
	WSACleanup();
}

void UDP::GetNameAndIp()
//获取局域网所有联系人的主机名称和IP
{

	struct   hostent   *host;
	struct   in_addr   *ptr;

	DWORD   dwScope = RESOURCE_CONTEXT;
	NETRESOURCE   *NetResource = NULL;
	HANDLE   hEnum;
	WNetOpenEnum(dwScope, NULL, NULL, NULL, &hEnum);

	WSADATA   wsaData;
	WSAStartup(MAKEWORD(1, 1), &wsaData);
	ui.IpListWidget->clear();//清空列表
	names.clear();//清空map
	ui.chatIpLabel->setText("");//清除当前联系人
	sendAble = false;
	appointFlag = false;

	if (hEnum)
	{
		DWORD   Count = 0xFFFFFFFF;
		DWORD   BufferSize = 10240;
		LPVOID   Buffer = new char[10240];
		WNetEnumResource(hEnum, &Count, Buffer, &BufferSize);
		NetResource = (NETRESOURCE*)Buffer;

		char szHostName[200];

		for (unsigned int i = 0; i < BufferSize / sizeof(NETRESOURCE); i++, NetResource++)
		{
			if (NetResource->dwUsage == RESOURCEUSAGE_CONTAINER && NetResource->dwType == RESOURCETYPE_ANY)
			{
				if (NetResource->lpRemoteName)
				{
					CString   strFullName = NetResource->lpRemoteName;
					if (0 == strFullName.Left(2).Compare(_T("\\\\")))
						strFullName = strFullName.Right(strFullName.GetLength() - 2);

					gethostname(szHostName, strlen(szHostName));
					USES_CONVERSION;
					char *pchar = T2A(strFullName);
					host = gethostbyname(pchar);

					if (host == NULL)   continue;
					ptr = (struct in_addr *)   host->h_addr_list[0];

					std::string str = "";
					for (int n = 0; n < 4; n++)
					{
						CString addr;
						if (n > 0)
						{
							str += ".";
						}
						int value = (unsigned int)((unsigned char*)host->h_addr_list[0])[n];
						char p[20];
						sprintf(p, "%d", value);
						str.append(p);
					}
					names.insert(std::pair<std::string, std::string>(host->h_name, str));//加入map
					ui.IpListWidget->addItem(QString::fromStdString(host->h_name));//显示主机名称
				}
			}
		}
		delete   Buffer;
		WNetCloseEnum(hEnum);
	}
	WSACleanup();
}

void UDP::loop() {
	while(true){
		Sleep(1000);
		receiveFromServer();
	}
}

void UDP::getAppointIp() {
	chatIp = ui.appointIpEdit->toPlainText().toStdString();
	ui.chatIpLabel->setText("Talking with: " + ui.appointIpEdit->toPlainText());
	if (appointFlag) {
		old->setBackground(Qt::white);
		old->setTextColor(Qt::black);
		ui.IpListWidget->clearSelection();
		appointFlag = false;
	}
	sendAble = true;
}