#pragma once

class Colleage;

class Mediator
{
public:
	Mediator();
	virtual ~Mediator();
	virtual void DoActionFromAtoB() = 0;
	virtual void DoActionFromBtoA() = 0;
	virtual void IntroColleage(Colleage * _clgA, Colleage * _clgB) = 0;
	virtual Colleage* GetConcreteColleageA() = 0;
	virtual Colleage* GetConcreteColleageB() = 0;
private:

};

class ConcreteMediator:public Mediator
{
public:
	ConcreteMediator();
	ConcreteMediator(Colleage * _clgA, Colleage * _clgB);
	~ConcreteMediator();

	void IntroColleage(Colleage * _clgA, Colleage * _clgB);
	void DoActionFromAtoB();
	void DoActionFromBtoA();

	void SetConcreteColleageA(Colleage* clgA);
	void SetConcreteColleageB(Colleage* clgB);
	Colleage* GetConcreteColleageA();
	Colleage* GetConcreteColleageB();
private:
	Colleage * _clgA;
	Colleage * _clgB;
};


