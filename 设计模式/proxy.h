#pragma once

#include <iostream>
using namespace std;

// ����
class SchoolGirl
{
	string m_name;
public:
	SchoolGirl() {
		m_name = "";
	}
	SchoolGirl(const string& name) {
		m_name = name;
	}
	string getName() {
		return m_name;
	}
	bool setName(string& name) {
		m_name = name;
		return true;
	}
};

//���󷽷�
class GiveGift
{
public:
	virtual void GiveDolls()=0;
	virtual void GiveFlowers()=0;
	virtual void GiveChocolate()=0;
	virtual ~GiveGift() = default;
};



//׷����
class Pursuit : public GiveGift
{
	SchoolGirl* mm;
public:
	Pursuit() {
		mm = nullptr;
	}
	Pursuit(SchoolGirl* g) {
		mm = g;
	}
	void GiveDolls() override {
		cout << mm->getName()<<"GiveDolls" << endl;
	};
	void GiveFlowers() override {
		cout << mm->getName() << "GiveFlowers" << endl;
	};
	void GiveChocolate() override {
		cout << mm->getName() << "GiveChocolate" << endl;
	};

	~Pursuit() override {
		if (mm) delete mm;
	}
};

//����׷����
class Proxy : GiveGift
{
	Pursuit* gg;
public:
	Proxy() {
		gg = nullptr;
	}
	Proxy(SchoolGirl* g) {
		if (gg) delete gg;
		gg = new Pursuit(g);
	}
	void GiveDolls() override {
		gg->GiveDolls();
	};
	void GiveFlowers() override {
		gg->GiveFlowers();
	};
	void GiveChocolate() override {
		gg->GiveChocolate();
	};
	~Proxy() override {
		if(gg) delete gg;
	}
};



