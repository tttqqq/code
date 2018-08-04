#include "Observer.h"
#include "Subject.h"

using namespace std;

int main() 
{
	Subject* sub = new ConcreteSubject();
	Observer* obsA = new ConcreteObserverA(sub);
	Observer* obsB = new ConcreteObserverB(sub);

	sub->SetStatus("ok");
	sub->Notify();

	sub->SetStatus("err");
	sub->Notify();
	return 0;
}