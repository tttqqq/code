#include "Visitor.h"

using namespace std;

int main()
{
	//����ԭ��������
	Element* cpu = new CPU("intel i7-8700k");
	Element* videocard = new VideoCard("harman");
	Element* mainboard = new MainBoard("HuaSuo");
	
	//����ԭ������һ������Ķ���
	Computer *cpr = new Computer(cpu, videocard, mainboard);

	//��ͬ���ˣ���ͬ�Ĳ�������
	Visitor* circuiteDec = new CircuitDetector("chentaoquan");
	cpr->Accept(circuiteDec);

	//��ͬ���ˣ���ͬ�Ĳ�������
	Visitor* funcDec = new FunctionDetector("wangtingting");
	cpr->Accept(funcDec);

	system("Pause");
	return 0;
}