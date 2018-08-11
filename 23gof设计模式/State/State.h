#pragma once
#include <string>

using namespace std;

//�ο�wiki:https://blog.csdn.net/hailong0715/article/details/51994470 , ��pdf��д�ĺ�
class TCPState;
class TCPConn
{
public:
	TCPConn(TCPState* state);
	~TCPConn();
	void SetTCPState(TCPState* state); //״̬�������
	void Request();
private:
	TCPState * _state;

};

///////////////////////////////////////////////////////////////

class TCPState
{
public:
	TCPState();
	virtual ~TCPState();
	virtual void Handle(TCPConn* con) = 0;
	virtual string GetTCPSatus() = 0;
private:
};


class TCPClose:public TCPState
{
public:
	TCPClose();
	~TCPClose();
	void Handle(TCPConn* con);
	string GetTCPSatus();
private:
	string status;
};


class TCPListen :public TCPState
{
public:
	TCPListen();
	~TCPListen();
	void Handle(TCPConn* con);
	string GetTCPSatus();
private:
	string status;
};

class TCPAccepted:public TCPState
{
public:
	TCPAccepted();
	~TCPAccepted();
	void Handle(TCPConn* con);
	string GetTCPSatus();
private:
	string status;
};

class TCPConnected :public TCPState
{
public:
	TCPConnected();
	~TCPConnected();
	void Handle(TCPConn* con);
	string GetTCPSatus();
private:
	string status;
};

