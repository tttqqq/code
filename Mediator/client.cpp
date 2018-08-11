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
	pclgA->Action();//�ı�B��״̬
	pclgB->Action();//�ı�A��״̬
	cout << endl;

	pclgA->SetState("follower!");
	pclgA->Action();//�ı�B��״̬

	pclgB->SetState("beatufull!");
	pclgB->Action();//�ı�A��״̬
	pclgA->Action();//�ı�B��״̬
	return 0;
}