#include "Colleage.h"
#include "Mediator.h"

using namespace std;


Mediator::Mediator()
{
}

Mediator::~Mediator()
{
}


ConcreteMediator::ConcreteMediator()
{
}

ConcreteMediator::ConcreteMediator(Colleage * _clgA, Colleage * _clgB)
{
	this->_clgA = _clgA;
	this->_clgB = _clgB;
}

ConcreteMediator::~ConcreteMediator()
{
}

void ConcreteMediator::IntroColleage(Colleage * _clgA, Colleage * _clgB)
{
	this->_clgA = _clgA;
	this->_clgB = _clgB;
}

void ConcreteMediator::DoActionFromAtoB()
{
	this->_clgB->SetState(_clgA->GetState());
}

void ConcreteMediator::DoActionFromBtoA()
{
	this->_clgA->SetState(_clgB->GetState());
}

void ConcreteMediator::SetConcreteColleageA(Colleage * clgA)
{
	this->_clgA = clgA;
}

void ConcreteMediator::SetConcreteColleageB(Colleage * clgB)
{
	this->_clgB = clgB;
}

Colleage * ConcreteMediator::GetConcreteColleageA()
{
	return _clgA;
}

Colleage * ConcreteMediator::GetConcreteColleageB()
{
	return _clgB;
}