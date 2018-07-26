#ifndef _ABSTRACTPRODUCTB_H_
#define _ABSTRACTPRODUCTB_H_

#include <stdio.h>

class AbstractProductB
{
public:
	AbstractProductB();
	virtual ~AbstractProductB();

public:
	virtual void createOperation() = 0;
};

class ProductB1 :public AbstractProductB
{
public:
	ProductB1();
	~ProductB1();

public:
	void createOperation();
};

class ProductB2 :public AbstractProductB
{
public:
	ProductB2();
	~ProductB2();

public:
	void createOperation();
};


#endif // !_ABSTRACTPRODUCTB_H_
