#include "Abstraction.h"
#include "Implement.h"	

using namespace std;

int main()
{
	Implement* impA = new ConcreteImplementA();
	Implement* impB = new ConcreteImplementB();

	Abstraction* Abs11 = new  AbstractionA(impA);
	Abstraction* Abs22 = new  AbstractionA(impB);

	Abs11->Operation();
	Abs22->Operation();
	return 0;
}