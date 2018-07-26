#ifndef _ABSTRACTPRODUCTA_H_
#define _ABSTRACTPRODUCTA_H_

#include <stdio.h>

class AbstractProductA
{
public:
	AbstractProductA();
	virtual ~AbstractProductA();

public:
	virtual void createOperation() = 0;
};

class ProductA1:public AbstractProductA
{
public:
	ProductA1();
	~ProductA1();

public:
	void createOperation();
};

class ProductA2:public AbstractProductA
{
public:
	ProductA2();
	~ProductA2();

public:
	void createOperation();
};


#endif // !_ABSTRACTPRODUCTA_H_
