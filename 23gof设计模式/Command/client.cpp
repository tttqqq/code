#include "Command.h"

using namespace std;

int main()
{
	Receiver* rev = new Receiver();
	Command* cmd = new ConcreteCommand(rev);
	Invoker* inv = new Invoker(cmd);

	inv->Invoke();

	return 0;
}