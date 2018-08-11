#include "Memento.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Originator* pOri = new Originator();
	pOri->SetStatus("chentaoquan");
	pOri->ShowContent();
	//手动备份pOri内容状态
	Memento* pMemChen =  pOri->CreateMemento();

	//改变内容状态
	pOri->SetStatus("wangtingting");
	pOri->ShowContent();
	//手动备份pOri内容状态
	Memento* pMemWang = pOri->CreateMemento();

	//改变内容状态
	pOri->SetStatus("I Love U");
	pOri->ShowContent();
	//手动备份pOri内容状态
	Memento* pMemLove = pOri->CreateMemento();

	//恢复内容状态
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