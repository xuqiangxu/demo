#pragma once

#include<iostream>
#include <string>
using namespace std;
class Person
{
	string m_name;
public:
	Person() { m_name = ""; }
	Person(const string& name) {
		m_name = name;
	}

	virtual void show() {
		cout << "װ���" << m_name << endl;
	}
	virtual ~Person() {}
};


class Finery : public Person
{
protected:
	Person* component;
public:
	Finery() { component = nullptr; }
	void Decorate(Person* component) {
		this->component = component;
	}

	void show() override
	{
		if (component != nullptr) {
			component->show();
		}
	}

	~Finery() override{
		if (component) delete component;
	}
};

class Tshirts : public Finery
{
public:
	void show() override
	{
		if (component != nullptr) {
			cout << "��T��" << endl;
			component->show();
		}
	}
};

class BigTrouser : public Finery
{
public:
	void show() override
	{
		if (component != nullptr) {
			cout << "���" << endl;
			component->show();
		}
	}
};


class Sneakers : public Finery
{
public:
	void show() override
	{
		if (component != nullptr) {
			cout << "����Ь" << endl;
			component->show();
		}
	}
};

class Tie : public Finery
{
public:
	void show() override
	{
		if (component != nullptr) {
			cout << "���" << endl;
			component->show();
		}
	}
};

class LeatherShoes : public Finery
{
public:
	void show() override
	{
		if (component != nullptr) {
			cout << "ƤЬ" << endl;
			component->show();
		}
	}
};

class Suit : public Finery
{
public:
	void show() override
	{
		if (component != nullptr) {
			cout << "��װ" << endl;
			component->show();
		}
	}
};