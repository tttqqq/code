#pragma once


class Implement;

class Abstraction
{
public:
	Abstraction();
	virtual ~Abstraction();
	virtual void  Operation() = 0;
private:

};


class AbstractionA:public Abstraction
{
public:
	AbstractionA(Implement* imp);
	~AbstractionA();
	void  Operation();
private:
	Implement* _imp;

};

