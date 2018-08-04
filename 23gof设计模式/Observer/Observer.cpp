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
	//��ȡע������ߣ�ͬʱ�Լ�ע�ᵽ��������
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
	//��ע������������ô˺�������״̬����
	_st = sub->GetStatus();
	printInfo();
}

void ConcreteObserverA::printInfo()
{
	cout << "ConcreteObserverA::printInfo��fater define _st: " << _st << "me _st: " << _sub->GetStatus() << endl;
}

Subject * ConcreteObserverA::GetSubject()
{
	return _sub;
}

ConcreteObserverB::ConcreteObserverB(Subject *sub)
{
	//��ȡע������ߣ�ͬʱ�Լ�ע�ᵽ��������
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
	//��ע������������ô˺�������״̬����
	_st = sub->GetStatus();
	printInfo();
}

void ConcreteObserverB::printInfo()
{
	cout << "ConcreteObserverB::printInfo��fater define _st: " << _st << "me _st: " << _sub->GetStatus() << endl;
}

Subject * ConcreteObserverB::GetSubject()
{
	return _sub;
}
