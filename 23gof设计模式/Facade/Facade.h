#pragma once

class Subobj1
{
public:
	Subobj1();
	~Subobj1();
	void ShowYourSelf();
private:

};

class Subobj2
{
public:
	Subobj2();
	~Subobj2();
	void DisplayYourSelf();
private:

};


class Facade
{
public:
	Facade();
	~Facade();
	void ShowForClient();
private:
	Subobj1* _obj1;
	Subobj2* _obj2;
};

