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

// �ؼ��㣺��Ա����ʵ����
Singleton * Singleton::instance()
{
	if (0 == _instance) {
		_instance = new Singleton();
	}

	return _instance;
}

void Singleton::PrintInfo()
{
	cout << "Ψһʵ����ӡ" << endl;
}
