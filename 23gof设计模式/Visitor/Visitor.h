#pragma once

#include <iostream>
#include <string>
#include <vector>

//pdf 上也可以用，但是没有wiki讲的好:https://www.cnblogs.com/suzhou/p/designpattern17visitor.html

using namespace std;

class Visitor;

/****需要操作的原器件对象***/
class Element
{
public:
	Element(const string &EleName);
	virtual ~Element();
	string GetEleName();
	virtual void Accept(Visitor *vtor) = 0;
private:
	string elementName;
};


class CPU:public Element
{
public:
	CPU(const string &name);
	~CPU();
	void Accept(Visitor* vtor);

private:
};


class VideoCard:public Element
{
public:
	VideoCard(const string &name);
	~VideoCard();
	void Accept(Visitor *vtor);
private:

};

class MainBoard :public Element
{
public:
	MainBoard(const string &name);
	~MainBoard();
	void Accept(Visitor *vtor);
private:

};
/*****整合一下以上的原器件*****/
class Computer
{
public:
	Computer(Element* cpu, Element* videocard, Element* mainboard);
	Computer();
	~Computer();

	void Accept(Visitor* vis);

private:
	vector<Element*> _ele;
};

/*访问者*/
class Visitor
{
public:
	Visitor();
	virtual ~Visitor();
	virtual void OperationCPUInfo(Element *ele) = 0;
	virtual void OperationVideoCardInfo(Element *ele) = 0;
	virtual void OperationMainBoardInfo(Element *ele) = 0;
private:

};


class CircuitDetector:public Visitor
{
public:
	CircuitDetector();
	CircuitDetector(const string &cirname);
	~CircuitDetector();
	string GetCirName();
	void OperationCPUInfo(Element *ele);
	void OperationVideoCardInfo(Element *ele);
	void OperationMainBoardInfo(Element *ele);
private:
	string CirName;
};


class FunctionDetector:public Visitor
{
public:
	FunctionDetector();
	FunctionDetector(const string &funName);
	~FunctionDetector();
	string GetCirName();
	void OperationCPUInfo(Element *ele);
	void OperationVideoCardInfo(Element *ele);
	void OperationMainBoardInfo(Element *ele);
private:
	string funName;
};
