#include "Template.h"
#include <iostream>
using namespace std;

AbsTemplate::AbsTemplate()
{
}

AbsTemplate::~AbsTemplate()
{
}

void AbsTemplate::Operation()
{
	ConcreteOperation();
}


ConcreteMemberA::ConcreteMemberA()
{
}

ConcreteMemberA::~ConcreteMemberA()
{
}

void ConcreteMemberA::ConcreteOperation()
{
	cout << "ConcreteMemberA::ConcreteOperation" << endl;
}

ConcreteMemberB::ConcreteMemberB()
{
}

ConcreteMemberB::~ConcreteMemberB()
{
}

void ConcreteMemberB::ConcreteOperation()
{
	cout << "ConcreteMemberB::ConcreteOperation" << endl;
}