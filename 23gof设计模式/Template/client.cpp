#include "Template.h"

using namespace std;

int main()
{
	AbsTemplate *tmpA = new ConcreteMemberA();
	AbsTemplate *tmpB = new ConcreteMemberB();
	tmpA->Operation();
	tmpB->Operation();

	return 0;
}