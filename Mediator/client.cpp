#include "Colleage.h"
#include "Mediator.h"
#include <iostream>

using namespace std;

int main()
{
	Mediator* pMdr = new ConcreteMediator();
	Colleage* pclgA = new ConcreteColleageA(pMdr);
	Colleage* pclgB = new ConcreteColleageB(pMdr);

	//Mediator* pMdr = new ConcreteMediator(pclgA, pclgB);
	pMdr->IntroColleage(pclgA, pclgB);
	
	pclgA->SetState("A colleage!");
	pclgB->SetState("B colleage!");
	pclgA->Action();//改变B的状态
	pclgB->Action();//改变A的状态
	cout << endl;

	pclgA->SetState("follower!");
	pclgA->Action();//改变B的状态

	pclgB->SetState("beatufull!");
	pclgB->Action();//改变A的状态
	pclgA->Action();//改变B的状态
	return 0;
}