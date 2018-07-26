#include "AbstractFactory.h"
//�ο�wiki:https://www.cnblogs.com/cxjchen/p/3143633.html  ���󹤳�ģʽ��ʵ��


int main()
{
	printf("main:now,creat level 1 product!\n");
	printf("main:creat productA\n");
	AbstractFactory* fac = new AbstractFactoryLevel1();
	AbstractProductA *prodoctA = fac->createProductA();
	prodoctA->createOperation();
	delete prodoctA;

	printf("main:creat productB\n");
	AbstractProductB* prodoctB = fac->createProductB();
	prodoctB->createOperation();
	delete prodoctB;
	delete fac;


	printf("main:***************************************\n");
	printf("main:now,creat level 2 product!\n");
	printf("main:creat productA\n");
	fac = new AbstractFactoryLevel2();
	prodoctA = fac->createProductA();
	prodoctA->createOperation();
	delete prodoctA;

	printf("main:creat productB\n");
	prodoctB = fac->createProductB();
	prodoctB->createOperation();
	delete prodoctB;
	delete fac;
}