#include "Colleage.h"
#include "Mediator.h"
#include <iostream>

using namespace std;

Colleage::Colleage()
{
	this->_mdt = 0;
}

Colleage::~Colleage()
{
}

Colleage::Colleage(Mediator * mdt)
{
	this->_mdt = mdt;
}


ConcreteColleageA::ConcreteColleageA()
{
	this->_mdt = 0;
	this->_str = "";
}

ConcreteColleageA::ConcreteColleageA(Mediator* mdt) :Colleage(mdt)
{
}

ConcreteColleageA::~ConcreteColleageA()
{
}

void ConcreteColleageA::Action()
{
	_mdt->DoActionFromAtoB();
	cout << "State of ConcreteColleageB: " << this->GetState() << endl;
	cout << "State of ConcreteColleageA&B: " << this->_mdt->GetConcreteColleageA()->GetState() <<"&"<< this->_mdt->GetConcreteColleageB()->GetState() << endl;
}

void ConcreteColleageA::SetState(const string & str)
{
	this->_str = str;
}

string ConcreteColleageA::GetState()
{
	return _str;
}


ConcreteColleageB::ConcreteColleageB()
{
	this->_mdt = 0;
	this->_str = "";
}

ConcreteColleageB::ConcreteColleageB(Mediator * mdt) :Colleage(mdt)
{
}

ConcreteColleageB::~ConcreteColleageB()
{
}

void ConcreteColleageB::Action()
{
	_mdt->DoActionFromBtoA();
	cout << "State of ConcreteColleageA: " << this->GetState() << endl;
	cout << "State of ConcreteColleageA&B: " << this->_mdt->GetConcreteColleageA()->GetState() << "&" << this->_mdt->GetConcreteColleageB()->GetState() << endl;
}

void ConcreteColleageB::SetState(const string & str)
{
	_str = str;
}

string ConcreteColleageB::GetState()
{
	return _str;
}
