#include "Proxy.h"
#include <iostream>

using namespace std;


Subject::Subject()
{
}

Subject::~Subject()
{
}


ConcreteSubject::ConcreteSubject()
{
}

ConcreteSubject::~ConcreteSubject()
{
}

void ConcreteSubject::ShowOperation()
{
	cout << "hello,this is ConcreteSubject Showoperatin!" << endl;
}


Proxy::Proxy(Subject* sub)
{
	_sub = sub;
}

Proxy::~Proxy()
{
}

void Proxy::ProxyOperation()
{
	_sub->ShowOperation();
}
