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
	
	//��compo2Ϊ���ڵ㣬���õݹ�������leaf1�ڵ㣬��ɾ��
	compo2->Remove(leaf1);
	
	//��compo2Ϊ���ڵ㣬���õݹ����°����нڵ������ɡ�
	compo2->Operation();
	Component* getchild = compo2->GetChild(0);
	getchild->Operation();
	return 0;
}