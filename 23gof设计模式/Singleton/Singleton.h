#pragma once

class Singleton
{
public:
	Singleton();
	~Singleton();
	static Singleton* instance();
	void PrintInfo();

private:
	static Singleton* _instance; //关键点：私有成员

};

