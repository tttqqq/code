#include "State.h"
#include <iostream>

using namespace std;

TCPConn::TCPConn(TCPState* state)
{
	this->_state = state;
	cout << "TCPConn::TCPConn: " << _state->GetTCPSatus()<< endl;
}

TCPConn::~TCPConn()
{
	cout << "TCPConn::~TCPConn: " << _state->GetTCPSatus() << endl;
}

void TCPConn::SetTCPState(TCPState * state)
{
	if (NULL != _state) { //ɾ����һ��״̬����������ڴ�й©(ע:�������������ҪΪ�麯����������������ڴ�й©)
		delete _state;
	}
	_state = state;

	cout << "TCPConn::SetTCPState update: " << _state->GetTCPSatus() << endl;
}

void TCPConn::Request()
{
	_state->Handle(this);//�ؼ���1
}

TCPState::TCPState()
{
}

TCPState::~TCPState()
{
}


TCPClose::TCPClose()
{
	status = "TCPClose";
}

TCPClose::~TCPClose()
{
	cout << "TCPClose am dead!" << endl;
}

void TCPClose::Handle(TCPConn * con)
{
	con->SetTCPState(new TCPListen());
	//delete this;
}

string TCPClose::GetTCPSatus()
{
	return status;
}



TCPListen::TCPListen()
{
	status = "TCPListen";
}

TCPListen::~TCPListen()
{
	cout << "TCPListen am dead!" << endl;
}

void TCPListen::Handle(TCPConn * con)
{
	con->SetTCPState(new TCPAccepted());
	//delete this;
}

string TCPListen::GetTCPSatus()
{
	return status;
}


TCPAccepted::TCPAccepted()
{
	status = "TCPAccepted";
}

TCPAccepted::~TCPAccepted()
{
	cout << "TCPAccepted am dead!" << endl;
}


void TCPAccepted::Handle(TCPConn * con)
{
	con->SetTCPState(new TCPConnected());
	//delete this;
}

string TCPAccepted::GetTCPSatus()
{
	return status;
}


TCPConnected::TCPConnected()
{
	status = "TCPConnected";
}

TCPConnected::~TCPConnected()
{
	cout << "TCPConnected am dead!" << endl;
}

void TCPConnected::Handle(TCPConn * con)
{
	con->SetTCPState(new TCPClose());
	//delete this;
}

string TCPConnected::GetTCPSatus()
{
	return 	status;	
}
