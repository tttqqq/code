#include "Flyweight.h"
using namespace std;

int main()
{
	//Produckt *pro = new ConcreteProduckt("Hello");
	//Produckt *pro1 = new ConcreteProduckt("World");

	string exitString = "exit";

	//工厂对象
	FlyWeightFactory* flyFac = new FlyWeightFactory();

	//向工厂申请一个对象，且对象内部状态为Hello
	Produckt* proback = flyFac->GetProduct("Hello");
	//应用外部状态
	proback->Operation("Hello");

	//向工厂申请一个对象
	Produckt* proback1 = flyFac->GetProduct("World");
	//应用外部状态
	proback1->Operation(exitString);
	return 0;
}