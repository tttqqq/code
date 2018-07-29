#include "Component.h"
#include "composite.h"
#include "leaf.h"

int main()
{
	Component* leaf1 = new leaf();
	Component* leaf2 = new leaf();
	Component* compo1 = new Composite();
	Component* compo2 = new Composite();

	compo1->Add(leaf1);
	compo1->Add(leaf2);
	compo2->Add(compo1);
	
	//以compo2为根节点，利用递归向下找leaf1节点，并删除
	compo2->Remove(leaf1);
	
	//以compo2为根节点，利用递归向下把所有节点操作完成。
	compo2->Operation();
	Component* getchild = compo2->GetChild(0);
	getchild->Operation();
	return 0;
}