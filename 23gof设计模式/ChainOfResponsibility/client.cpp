#include "Handle.h"

using namespace std;

int main()
{
	Handle* phandleA = new ConcreteHandleA();
	Handle* phandleB = new ConcreteHandleB();
	
	//����BΪA����һ�������
	phandleA->SetHandle(phandleB);

	//�ͻ�����A��Ҫ4w
	phandleA->NeeedMoney(40000);

	//A��ʼ���������ж��Ƿ񴫵ݸ���һ��
	phandleA->ShowOperation();

	return 0;
}