#pragma once

#include <string>

using namespace std;

class Memento;
class Originator
{
public:
	Originator();
	~Originator();
	void SetStatus(const string& status);
	string GetStatus();
	Memento* CreateMemento();
	void RestoreToOriginator(Memento* mt);
	void SetMemento(Memento* mt);
	void ShowContent();
private:
	string _status;
	Memento* _mt;
};

class Memento
{
public:
	Memento();
	Memento(const string& _status);
	~Memento();
	string GetStatus();
	void SetStatus(const string& status);

	friend class Originator;

private:
	string _status;
};

