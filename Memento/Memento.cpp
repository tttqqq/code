#include "Memento.h"
#include <iostream>
#include <iostream>


Originator::Originator()
{
	this->_status = "";
	this->_mt = 0;
}

Originator::~Originator()
{
}

void Originator::SetStatus(const string& status)
{
	this->_status = status;
	this->_mt = 0;
}

string Originator::GetStatus()
{
	return _status;
}

Memento* Originator::CreateMemento()
{
	return new Memento(_status);//如果是自动备份，应该是复制给_mt，而不是函数返回，个人理解。
}

void Originator::RestoreToOriginator(Memento * mt)
{
	this->_status = mt->GetStatus();
}

void Originator::SetMemento(Memento * mt)//感觉这个函数用于内部备份和还原的,如果是客户端手动备份和恢复，用不到
{
	this->_mt = mt;
}

void Originator::ShowContent()
{
	if (_mt != 0) {
		cout << "Originator::ShowContent _mt status: " << _mt->GetStatus() << endl;
	}
	else
	{
		cout << "no iner auto Memento!" << endl;
	}

	cout << "Originator::ShowContent _status: " << GetStatus() << endl;
	
}



Memento::Memento()
{
}

Memento::Memento(const string & _status)
{
	this->_status = _status;
}

Memento::~Memento()
{
}

string Memento::GetStatus()
{
	return _status;
}

void Memento::SetStatus(const string & status)
{
	this->_status = status;
}