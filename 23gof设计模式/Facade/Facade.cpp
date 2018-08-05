#include "Facade.h"
#include <iostream>

using namespace std;


Subobj1::Subobj1()
{
}

Subobj1::~Subobj1()
{
}

void Subobj1::ShowYourSelf()
{
	cout << "hello,I am Subobj1" << endl;
}

Subobj2::Subobj2()
{
}

Subobj2::~Subobj2()
{
}

void Subobj2::DisplayYourSelf()
{
	cout << "hello,i am Subobj22222222222" << endl;
}


Facade::Facade()
{
	_obj1 = new Subobj1();
	_obj2 = new Subobj2();
}

Facade::~Facade()
{
	delete _obj1;
	delete _obj2;
}

void Facade::ShowForClient()
{
	_obj1->ShowYourSelf();
	this->_obj2->DisplayYourSelf();
}