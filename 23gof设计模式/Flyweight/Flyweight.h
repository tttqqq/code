#pragma once

#include <vector>
#include <iostream>
#include <string>

using namespace std;

//例子比pdf完整，参考：https://www.cnblogs.com/jiese/p/3171463.html

class Produckt
{
public:
	Produckt(const string &s1);
	virtual ~Produckt();
	virtual void Operation(const string &s1) = 0;
	string GetString();
private:
	string _str;

};

class ConcreteProduckt:public Produckt
{
public:
	ConcreteProduckt(const string &s1);
	~ConcreteProduckt();
	void Operation(const string &s1);
private:

};


class UnsharedConcreteFlyweight :public Produckt
{
public:
    virtual void Operation(const string& extrinsicState);
    UnsharedConcreteFlyweight(string intrinsicState);
    ~UnsharedConcreteFlyweight();
};

class FlyWeightFactory
{
public:
	FlyWeightFactory();
	~FlyWeightFactory();
	Produckt* GetProduct(const string & s1);

private:
	vector<Produckt*> _product;
};
