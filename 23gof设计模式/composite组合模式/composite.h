#ifndef _COMPOSITE_H_
#define _COMPOSITE_H_

#include "Component.h"
#include  <vector>
#include <iostream>
using namespace std;

class Composite:public Component
{
public:
	Composite();
	~Composite();

public:
	void Operation();
	void Add(Component* com);
	void Remove(Component* com);
	Component* GetChild(int index);

private:
	vector<Component*> vecCom;
};

#endif // !_COMPOSITE_H_
