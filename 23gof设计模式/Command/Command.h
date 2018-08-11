#pragma once

//pdf 例子是错误的，参考wiki:https://www.cnblogs.com/jiese/p/3190414.html
class Command
{
public:
	Command();
	virtual ~Command();
	virtual void Execute() = 0;

private:

};

class Receiver;

class ConcreteCommand:public Command
{
public:
	ConcreteCommand(Receiver* rec);
	~ConcreteCommand();
	void Execute();
private:
	Receiver * _rec;
};


class Invoker
{
public:
	Invoker(Command* cmd);
	~Invoker();
	void Invoke();
private:
	Command * _cmd;
};

class Receiver
{
public:
	Receiver();
	~Receiver();
	void OperationInfo();
private:

};

