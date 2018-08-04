#pragma once

#include "Subject.h"
#include <string>

using namespace std;

class Observer
{
public:
	Observer();
	~Observer();
	virtual void update(Subject* sub);
	virtual void printInfo();

protected:
	string _st;
};

class ConcreteObserverA:public Observer
{
public:
	ConcreteObserverA(Subject* sub);
	~ConcreteObserverA();
	void update(Subject* sub);
	void printInfo();
	Subject* GetSubject();
private:
	Subject * _sub;
};

class ConcreteObserverB :public Observer
{
public:
	ConcreteObserverB(Subject *sub);
	~ConcreteObserverB();
	void update(Subject *sub);
	void printInfo();
	Subject* GetSubject();

private:
	Subject * _sub;
};


