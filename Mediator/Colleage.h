#pragma once

#include <string>

using namespace std;

class Mediator;
class Colleage
{
public:
	Colleage();
	virtual ~Colleage();
	virtual void Action() = 0;
	virtual void SetState(const string& str) = 0;
	virtual string GetState() = 0;

protected:
	Colleage(Mediator* mdt);
	Mediator* _mdt;

private:

};

class ConcreteColleageA:public Colleage
{
public:
	ConcreteColleageA();
	ConcreteColleageA(Mediator* mdt);
	~ConcreteColleageA();
	void Action();
	void SetState(const string& str);
	string GetState();
private:
	string _str;
};

class ConcreteColleageB:public Colleage
{
public:
	ConcreteColleageB();
	ConcreteColleageB(Mediator* mdt);
	~ConcreteColleageB();
	void Action();
	void SetState(const string& str);
	string GetState();

private:
	string _str;
};
