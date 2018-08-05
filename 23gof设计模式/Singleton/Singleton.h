#pragma once

class Singleton
{
public:
	Singleton();
	~Singleton();
	static Singleton* instance();
	void PrintInfo();

private:
	static Singleton* _instance; //�ؼ��㣺˽�г�Ա

};

