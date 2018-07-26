#ifndef _ABSTRACTFACTORY_H_
#define _ABSTRACTFACTORY_H_

#include "AbstractProductA.h"
#include "AbstractProductB.h"

class AbstractFactory
{
public:
	AbstractFactory();
	virtual ~AbstractFactory();

public:
	virtual AbstractProductA* createProductA() = 0;
	virtual AbstractProductB* createProductB() = 0;
};

class AbstractFactoryLevel1:public AbstractFactory
{
public:
	AbstractFactoryLevel1();
	~AbstractFactoryLevel1();

public:
	AbstractProductA* createProductA();
	AbstractProductB* createProductB();
};


class AbstractFactoryLevel2 :public AbstractFactory
{
public:
	AbstractFactoryLevel2();
	~AbstractFactoryLevel2();

public:
	AbstractProductA* createProductA();
	AbstractProductB* createProductB();
};





#endif // !_ABSTRACTFACTORY_H_
