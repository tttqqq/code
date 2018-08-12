#include "Handle.h"
#include <iostream>

using namespace std;

int Handle::_money = 0;
Handle::Handle()
{
	//this->_handle = 0;
}

Handle::Handle(Handle * handle)
{
	//this->_handle = handle;
}

Handle::~Handle()
{
}

//bool Handle::CanDoIt()
//{
//	if (_money > 30000) {
//		return false;
//	}
//
//	return true;
//}

void Handle::NeeedMoney(int money)
{
	this->_money = money;
}

int Handle::GetMoney()
{
	return _money;
}

ConcreteHandleA::ConcreteHandleA()
{
}

ConcreteHandleA::~ConcreteHandleA()
{
}

void ConcreteHandleA::SetHandle(Handle * handle)
{
	this->_handle = handle;
}

Handle * ConcreteHandleA::GetHanle()
{
	return _handle;
}

void ConcreteHandleA::ShowOperation()
{
	if (true == this->CanDoIt()) {
		cout << "ConcreteHandleA:wangtingting can do it" << endl;
	}
	else
	{
		if (this->_handle == 0) {
			cout << "ConcreteHandleA:wangtingting can not do it, and no body can do it. so ,stop!" << endl;
			return ;
		}
		cout << "ConcreteHandleA:wangtingting can not do it, pass it to next" << endl;
		this->_handle->ShowOperation();
	}
}

bool ConcreteHandleA::CanDoIt()
{
	if (GetMoney() > 30000) {
		return false;
	}

	return true;
}

ConcreteHandleB::ConcreteHandleB()
{
}

ConcreteHandleB::~ConcreteHandleB()
{
}

void ConcreteHandleB::SetHandle(Handle * handle)
{
	this->_handle = handle;
}

Handle * ConcreteHandleB::GetHanle()
{
	return _handle;
}

void ConcreteHandleB::ShowOperation()
{
	if (true == this->CanDoIt()) {
		cout << "ConcreteHandleB:chentaoquan can do it" << endl;
	}
	else
	{
		if (this->_handle == 0) {
			cout << "ConcreteHandleA:chentaoquan can not do it, and no body can do it. so ,stop!" << endl;
			return;
		}
		cout << "ConcreteHandleB:chentaoquan can not do it, pass it to next" << endl;
		this->_handle->ShowOperation();
	}
}

bool ConcreteHandleB::CanDoIt()
{
	if (GetMoney() > 40000) {
		return false;
	}

	return true;
}
