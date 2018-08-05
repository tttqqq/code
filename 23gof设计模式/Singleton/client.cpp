#include "Singleton.h"
#include <iostream>
using namespace std;

Singleton* Singleton::_instance = 0;

Singleton::Singleton()
{
	cout << "Singleton::Singleton" << endl;
}

Singleton::~Singleton()
{
}

// 关键点：成员函数实例化
Singleton * Singleton::instance()
{
	if (0 == _instance) {
		_instance = new Singleton();
	}

	return _instance;
}

void Singleton::PrintInfo()
{
	cout << "唯一实例打印" << endl;
}
