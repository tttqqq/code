#pragma once

class Subject
{
public:
	Subject();
	~Subject();
	virtual void ShowOperation() = 0;
private:

};


class ConcreteSubject:public Subject
{
public:
	ConcreteSubject();
	~ConcreteSubject();
	void ShowOperation();
private:

};



class Proxy
{
public:
	Proxy(Subject* sub);
	~Proxy();
	void ProxyOperation();

private:
	Subject * _sub;
};

