#include "Observer.h"
#include <string>
using namespace std;


Observer::Observer()
{
	_st = '\0';
}

Observer::~Observer()
{
}

void Observer::update(Subject * sub)
{
}

void Observer::printInfo()
{
}

ConcreteObserverA::ConcreteObserverA(Subject * sub)
{
	//获取注册管理者，同时自己注册到管理者中
	this->_sub = sub;
	_sub->Register(this);
}

ConcreteObserverA::~ConcreteObserverA()
{
	_sub->Unregister(this);
	if (0 != _sub) {
		delete _sub;
	}
}

void ConcreteObserverA::update(Subject * sub)
{
	//由注册管理者来调用此函数进行状态更新
	_st = sub->GetStatus();
	printInfo();
}

void ConcreteObserverA::printInfo()
{
	cout << "ConcreteObserverA::printInfo：fater define _st: " << _st << "me _st: " << _sub->GetStatus() << endl;
}

Subject * ConcreteObserverA::GetSubject()
{
	return _sub;
}

ConcreteObserverB::ConcreteObserverB(Subject *sub)
{
	//获取注册管理者，同时自己注册到管理者中
	_sub = sub;
	_sub->Register(this);
}

ConcreteObserverB::~ConcreteObserverB()
{
	_sub->Unregister(this);
	if (0 != _sub) {
		delete _sub;
	}
}

void ConcreteObserverB::update(Subject * sub)
{
	//由注册管理者来调用此函数进行状态更新
	_st = sub->GetStatus();
	printInfo();
}

void ConcreteObserverB::printInfo()
{
	cout << "ConcreteObserverB::printInfo：fater define _st: " << _st << "me _st: " << _sub->GetStatus() << endl;
}

Subject * ConcreteObserverB::GetSubject()
{
	return _sub;
}
