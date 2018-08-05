#include "Singleton.h"
using namespace std;

int main()
{
	Singleton* OnlyOne = Singleton::instance();//不是直接new，而是直接调用静态方法
	OnlyOne->PrintInfo();
	return 0;
}