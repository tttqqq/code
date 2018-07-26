#include "AbstractFactory.h"

AbstractFactory::AbstractFactory()
{
	printf("base class AbstractFactory construct!\n");
}

AbstractFactory::~AbstractFactory()
{
	printf("base class AbstractFactory deconstruct!\n");
}


AbstractFactoryLevel1::AbstractFactoryLevel1()
{
	printf("sub class AbstractFactoryLevel1 construct!\n");
}

AbstractFactoryLevel1::~AbstractFactoryLevel1()
{
	printf("sub class AbstractFactoryLevel1 deconstruct!\n");
}

AbstractProductA* AbstractFactoryLevel1::createProductA()
{
	printf("AbstractFactoryLevel1 create productA!\n");
	return new ProductA1();
}

AbstractProductB* AbstractFactoryLevel1::createProductB()
{
	printf("AbstractFactoryLevel1 create createProductB!\n");
	return new ProductB1();
}



AbstractFactoryLevel2::AbstractFactoryLevel2()
{
	printf("sub class AbstractFactoryLevel2 construct!\n");
}

AbstractFactoryLevel2::~AbstractFactoryLevel2()
{
	printf("sub class AbstractFactoryLevel2 deconstruct!\n");
}

AbstractProductA* AbstractFactoryLevel2::createProductA()
{
	printf("AbstractFactoryLevel2 create productA!\n");
	return new ProductA1();
}

AbstractProductB* AbstractFactoryLevel2::createProductB()
{
	printf("AbstractFactoryLevel2 create createProductB!\n");
	return new ProductB1();
}