#include "Command.h"
#include <iostream>

using namespace std;

Command::Command()
{
}

Command::~Command()
{
}

ConcreteCommand::ConcreteCommand(Receiver* rec)
{
	this->_rec = rec;
}

ConcreteCommand::~ConcreteCommand()
{
}

void ConcreteCommand::Execute()
{
	_rec->OperationInfo();
}

Invoker::Invoker(Command* cmd)
{
	this->_cmd = cmd;
}

Invoker::~Invoker()
{
}

void Invoker::Invoke()
{
	_cmd->Execute();
}

Receiver::Receiver()
{
}

Receiver::~Receiver()
{
}

void Receiver::OperationInfo()
{
	cout << "hello,world!" << endl;
}
