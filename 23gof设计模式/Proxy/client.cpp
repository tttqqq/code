#include "Proxy.h"

using namespace std;


int main()
{
	Subject* sub = new ConcreteSubject();
	Proxy* pro = new Proxy(sub);
	pro->ProxyOperation();
	return 0;
}