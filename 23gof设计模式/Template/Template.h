#pragma once

class AbsTemplate
{
public:
	AbsTemplate();
	virtual ~AbsTemplate();
	virtual void Operation();

protected:
	virtual void ConcreteOperation() = 0;
private:

};

class ConcreteMemberA:public AbsTemplate
{
public:
	ConcreteMemberA();
	~ConcreteMemberA();
protected:
	void ConcreteOperation();
private:

};

class ConcreteMemberB :public AbsTemplate
{
public:
	ConcreteMemberB();
	~ConcreteMemberB();
protected:
	void ConcreteOperation();
private:

};

