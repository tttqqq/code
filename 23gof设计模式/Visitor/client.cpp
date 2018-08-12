#include "Visitor.h"

using namespace std;

int main()
{
	//定义原器件对象
	Element* cpu = new CPU("intel i7-8700k");
	Element* videocard = new VideoCard("harman");
	Element* mainboard = new MainBoard("HuaSuo");
	
	//整合原器件成一个整体的对象
	Computer *cpr = new Computer(cpu, videocard, mainboard);

	//不同的人，不同的操作方法
	Visitor* circuiteDec = new CircuitDetector("chentaoquan");
	cpr->Accept(circuiteDec);

	//不同的人，不同的操作方法
	Visitor* funcDec = new FunctionDetector("wangtingting");
	cpr->Accept(funcDec);

	system("Pause");
	return 0;
}