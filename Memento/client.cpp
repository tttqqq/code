#include "Memento.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Originator* pOri = new Originator();
	pOri->SetStatus("chentaoquan");
	pOri->ShowContent();
	//�ֶ�����pOri����״̬
	Memento* pMemChen =  pOri->CreateMemento();

	//�ı�����״̬
	pOri->SetStatus("wangtingting");
	pOri->ShowContent();
	//�ֶ�����pOri����״̬
	Memento* pMemWang = pOri->CreateMemento();

	//�ı�����״̬
	pOri->SetStatus("I Love U");
	pOri->ShowContent();
	//�ֶ�����pOri����״̬
	Memento* pMemLove = pOri->CreateMemento();

	//�ָ�����״̬
	pOri->RestoreToOriginator(pMemChen);
	pOri->ShowContent();
	pOri->RestoreToOriginator(pMemWang);
	pOri->ShowContent();

	delete pMemChen;
	delete pMemWang;
	delete pMemLove;
	delete pOri;
	return 0;
}