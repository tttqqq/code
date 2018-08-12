#include "Visitor.h"

Element::Element(const string &EleName)
{
	this->elementName = EleName;
}

Element::~Element()
{
}

string Element::GetEleName()
{
	return this->elementName;
}


CPU::CPU(const string &name) :Element(name)
{
}

CPU::~CPU()
{
}

void CPU::Accept(Visitor* vtor)
{
	vtor->OperationCPUInfo(this);
}


VideoCard::VideoCard(const string &name) :Element(name)
{
}

VideoCard::~VideoCard()
{
}

void VideoCard::Accept(Visitor * vtor)
{
	vtor->OperationVideoCardInfo(this);
}


MainBoard::MainBoard(const string &name) :Element(name)
{
}

MainBoard::~MainBoard()
{
}

void MainBoard::Accept(Visitor * vtor)
{
	vtor->OperationMainBoardInfo(this);
}


Computer::Computer()
{
}

Computer::Computer(Element * cpu, Element * videocard, Element * mainboard)
{
	this->_ele.push_back(cpu);
	this->_ele.push_back(videocard);
	this->_ele.push_back(mainboard);
}

Computer::~Computer()
{
}

void Computer::Accept(Visitor * vis)
{
	vector<Element*>::iterator it;
	for (it = _ele.begin(); it != _ele.end(); it++) {
		(*it)->Accept(vis);
	}
}


Visitor::Visitor()
{
}

Visitor::~Visitor()
{
}


CircuitDetector::CircuitDetector()
{
}

CircuitDetector::CircuitDetector(const string &cirname)
{
	CirName = cirname;
}

CircuitDetector::~CircuitDetector()
{
}

string CircuitDetector::GetCirName()
{
	return CirName;
}

void CircuitDetector::OperationCPUInfo(Element * ele)
{
	cout << GetCirName() << ": I think the Circuit cpu: " << ele->GetEleName() << " is ok" << endl;
}

void CircuitDetector::OperationVideoCardInfo(Element * ele)
{
	cout << GetCirName() << ": I think the Circuit VideoCard: " << ele->GetEleName() << " is ok" << endl;
}

void CircuitDetector::OperationMainBoardInfo(Element * ele)
{
	cout << GetCirName() << ": I think the Circuit MainBoard: " << ele->GetEleName() << " is ok" << endl;
}


FunctionDetector::FunctionDetector()
{
}

FunctionDetector::FunctionDetector(const string &funName)
{
	this->funName = funName;
}

FunctionDetector::~FunctionDetector()
{
}

string FunctionDetector::GetCirName()
{
	return funName;
}

void FunctionDetector::OperationCPUInfo(Element * ele)
{
	cout << GetCirName() << ": I think the Function cpu: " << ele->GetEleName() << " is ok" << endl;
}

void FunctionDetector::OperationVideoCardInfo(Element * ele)
{
	cout << GetCirName() << ": I think the Function VideoCard: " << ele->GetEleName() << " is error!!!!!!!" << endl;
}

void FunctionDetector::OperationMainBoardInfo(Element * ele)
{
	cout << GetCirName() << ": I think the Function MainBoard: " << ele->GetEleName() << " is ok" << endl;
}
