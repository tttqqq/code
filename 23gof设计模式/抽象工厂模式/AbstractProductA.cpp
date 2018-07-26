#include "AbstractProductA.h"

AbstractProductA::AbstractProductA()
{
	printf("base class AbstractProductA construct!\n");
}

AbstractProductA::~AbstractProductA()
{
	printf("base class AbstractProductA deconstruct!\n");
}



ProductA1::ProductA1()
{
	printf("sub class ProductA1 construct!\n");
}

ProductA1::~ProductA1()
{
	printf("sub class ProductA1 deconstruct!\n");
}

void ProductA1::createOperation()
{
	printf("sub class ProductA1 create class!\n");
}


ProductA2::ProductA2()
{
	printf("sub class ProductA2 construct!\n");
}

ProductA2::~ProductA2()
{
	printf("sub class ProductA2 deconstruct!\n");
}

void ProductA2::createOperation()
{
	printf("sub class ProductA2 create class!\n");
}

