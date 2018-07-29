#include "composite.h"

Composite::Composite()
{
}

Composite::~Composite()
{
}

void Composite::Operation()
{
	std::cout << "composite operation!" << std::endl;
	std::vector<Component*>::iterator it_vec;
	for (it_vec = vecCom.begin(); it_vec != vecCom.end(); it_vec++)
	{
		(*it_vec)->Operation();
	}
}
void Composite::Add(Component* com)
{
	vecCom.push_back(com);
}
void Composite::Remove(Component* com)
{
	std::vector<Component*>::iterator it_vec;
	for (it_vec = vecCom.begin(); it_vec != vecCom.end(); it_vec++)
	{
		if ((*it_vec) == com)
		{
			break;
		}
		else
		{
			(*it_vec)->Remove(com);
		}
	}
	if (it_vec != vecCom.end()) {
		vecCom.erase(it_vec);
	}
	//vecCom.erase(&com);

}

Component* Composite::GetChild(int index)
{
	return vecCom[index];
}
