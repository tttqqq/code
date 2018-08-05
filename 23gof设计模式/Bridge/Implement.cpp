#include "Implement.h"
#include <iostream>

using namespace std;

Implement::Implement()
{
}

Implement::~Implement()
{
}


ConcreteImplementA::ConcreteImplementA()
{
}

ConcreteImplementA::~ConcreteImplementA()
{
}

void ConcreteImplementA::Operation()
{
	cout << "ConcreteImplementA::Operation" << endl;
}


ConcreteImplementB::ConcreteImplementB()
{
}

ConcreteImplementB::~ConcreteImplementB()
{
}

void ConcreteImplementB::Operation()
{
	cout << "ConcreteImplementB::Operation" << endl;
}