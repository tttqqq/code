#include "Singleton.h"
using namespace std;

int main()
{
	Singleton* OnlyOne = Singleton::instance();//����ֱ��new������ֱ�ӵ��þ�̬����
	OnlyOne->PrintInfo();
	return 0;
}