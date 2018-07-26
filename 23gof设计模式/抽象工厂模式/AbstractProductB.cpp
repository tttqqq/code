#include "AbstractProductB.h"

AbstractProductB::AbstractProductB()
{
	printf("base class AbstractProductB construct!\n");
}

AbstractProductB::~AbstractProductB()
{
	printf("base class AbstractProductB deconstruct!\n");
}



ProductB1::ProductB1()
{
	printf("sub class ProductB1 construct!\n");
}

ProductB1::~ProductB1()
{
	printf("sub class ProductB1 deconstruct!\n");
}

void ProductB1::createOperation()
{
	printf("sub class ProductB1 create class!\n");
}


ProductB2::ProductB2()
{
	printf("sub class ProductB2 construct!\n");
}

ProductB2::~ProductB2()
{
	printf("sub class ProductB2 deconstruct!\n");
}

void ProductB2::createOperation()
{
	printf("sub class ProductB2 create class!\n");
}

