#pragma once

class Handle
{
public:
	Handle();
	Handle(Handle *handle);
	virtual ~Handle();
	virtual void SetHandle(Handle *handle) = 0;
	virtual Handle* GetHanle() = 0;
	void NeeedMoney(int money);
	int GetMoney();
	virtual void ShowOperation() = 0;
	virtual bool CanDoIt() = 0;

private:
	//Handle * _handle;
	static int _money;
};

class ConcreteHandleA:public Handle
{
public:
	ConcreteHandleA();
	~ConcreteHandleA();
	void SetHandle(Handle *handle);
	Handle* GetHanle();
	void ShowOperation();
	bool CanDoIt();
private:
	
	Handle * _handle;

};

class ConcreteHandleB :public Handle
{
public:
	ConcreteHandleB();
	~ConcreteHandleB();
	void SetHandle(Handle *handle);
	Handle* GetHanle();
	void ShowOperation();
	bool CanDoIt();
private:

	Handle * _handle;

};

