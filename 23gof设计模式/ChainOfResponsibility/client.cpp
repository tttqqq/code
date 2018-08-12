#include "Handle.h"

using namespace std;

int main()
{
	Handle* phandleA = new ConcreteHandleA();
	Handle* phandleB = new ConcreteHandleB();
	
	//设置B为A的下一个审核者
	phandleA->SetHandle(phandleB);

	//客户端向A索要4w
	phandleA->NeeedMoney(40000);

	//A开始操作，并判断是否传递给下一个
	phandleA->ShowOperation();

	return 0;
}