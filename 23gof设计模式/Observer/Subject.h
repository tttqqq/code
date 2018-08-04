#pragma once

#include <list>
#include <string>
#include <iostream>

using namespace std;

class Observer;

class Subject
{
public:
	Subject();
	~Subject();
	virtual void Register(Observer* obs);
	virtual void Unregister(Observer* obs);
	virtual void Notify();
	virtual void SetStatus(const string& st);
	virtual string GetStatus();
private:
	list<Observer*> _obs;
};

class ConcreteSubject:public Subject
{
public:
	ConcreteSubject();
	~ConcreteSubject();
	void SetStatus(const string& st);
	string GetStatus();
private:
	string _st;

};


