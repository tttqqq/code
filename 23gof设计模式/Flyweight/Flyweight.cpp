#include "Flyweight.h"

Produckt::Produckt(const string &s1)
{
	this->_str = s1;
}

Produckt::~Produckt()
{
}

string Produckt::GetString()
{
	return _str;
}


ConcreteProduckt::ConcreteProduckt(const string &s1) :Produckt(s1)
{
	cout << "init iner string: " << s1 << endl;
}

ConcreteProduckt::~ConcreteProduckt()
{
}

void ConcreteProduckt::Operation(const string & s1)
{
	cout << "out input string: " << s1 << endl;
	cout << "iner string: " << GetString() << endl;
}


UnsharedConcreteFlyweight::UnsharedConcreteFlyweight(string intrinsicState) :Produckt(intrinsicState)
{
}

UnsharedConcreteFlyweight::~UnsharedConcreteFlyweight()
{
}

void UnsharedConcreteFlyweight::Operation(const string& extrinsicState)
{
	cout << "extrinsicState" << endl;
}


FlyWeightFactory::FlyWeightFactory()
{
}

FlyWeightFactory::~FlyWeightFactory()
{
}

Produckt* FlyWeightFactory::GetProduct(const string & s1)
{
	vector<Produckt*>::iterator _it;
	for (_it = _product.begin(); _it != _product.end(); _it++) {
		if (s1 == (*_it)->GetString()) {
			return  *_it;
		}
	}
	Produckt* pro = new ConcreteProduckt(s1);
	_product.push_back(pro);
	return pro;
}
