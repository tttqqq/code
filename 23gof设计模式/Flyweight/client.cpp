#include "Flyweight.h"
using namespace std;

int main()
{
	//Produckt *pro = new ConcreteProduckt("Hello");
	//Produckt *pro1 = new ConcreteProduckt("World");

	string exitString = "exit";

	//��������
	FlyWeightFactory* flyFac = new FlyWeightFactory();

	//�򹤳�����һ�������Ҷ����ڲ�״̬ΪHello
	Produckt* proback = flyFac->GetProduct("Hello");
	//Ӧ���ⲿ״̬
	proback->Operation("Hello");

	//�򹤳�����һ������
	Produckt* proback1 = flyFac->GetProduct("World");
	//Ӧ���ⲿ״̬
	proback1->Operation(exitString);
	return 0;
}