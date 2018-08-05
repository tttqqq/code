#pragma once

class Implement
{
public:
	Implement();
	virtual ~Implement();
	virtual void Operation() = 0;
private:

};


class ConcreteImplementA:public Implement
{
public:
	ConcreteImplementA();
	~ConcreteImplementA();
	void Operation();

private:

};


class ConcreteImplementB :public Implement
{
public:
	ConcreteImplementB();
	~ConcreteImplementB();
	void Operation();

private:

};

