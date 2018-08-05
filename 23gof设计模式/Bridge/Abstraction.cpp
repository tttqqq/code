#include "Abstraction.h"
#include "Implement.h"

using namespace std;


Abstraction::Abstraction()
{
}

Abstraction::~Abstraction()
{
}


AbstractionA::AbstractionA(Implement* imp)
{
	 _imp = imp;
}

AbstractionA::~AbstractionA()
{
}

void AbstractionA::Operation()
{
	_imp->Operation();
}
