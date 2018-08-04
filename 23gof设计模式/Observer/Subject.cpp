#include "Subject.h"
#include "Observer.h"
using namespace std;

Subject::Subject()
{
	//_obs = new list<Observer*>;
	cout << "Subject::Subject" << endl;
}

Subject::~Subject()
{
	cout << "Subject::~Subject" << endl;
}

void Subject::Register(Observer * obs)
{
	_obs.push_front(obs);
}

void Subject::Unregister(Observer * obs)
{
	if (!_obs.empty()) {
		_obs.remove(obs);
	}
}

void Subject::Notify()
{
	list<Observer*>::iterator it_lstObs;
	for (it_lstObs = _obs.begin(); it_lstObs != _obs.end(); it_lstObs++) {
		(*it_lstObs)->update(this);
	}
}

void Subject::SetStatus(const string & st)
{
}

string Subject::GetStatus()
{
	return 0;
}

ConcreteSubject::ConcreteSubject()
{
	_st = '\0';
}

ConcreteSubject::~ConcreteSubject()
{
}

void ConcreteSubject::SetStatus(const string & st)
{
	_st = st;
}

string ConcreteSubject::GetStatus()
{
	return _st;
}