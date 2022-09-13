#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*****������ģʽ******/
class PersonBuilder
{
protected:
	string p = "";
public:
	virtual void BuildHead() = 0;
	virtual void BuildBody() = 0;
	virtual void BuildArmLeft() = 0;
	virtual void BuildArmRight() = 0;
	virtual void BuildLegLeft() = 0;
	virtual void BuildLegRight() = 0;
	virtual void Show() = 0;
};

//�����������˽����ϸ��,�����Ҫ�����µľ��½�һ��������
class PersonThinBuilder : public PersonBuilder
{
public:
	void BuildHead() override {
		p += " o\n";
	}

	void BuildBody() override {
		p += '|';
	}
	void BuildArmLeft() override {
		p += '/';
	}
	void BuildArmRight() override {
		p += "\\\n";
		//p += '\\' + '\n';

	}
	void BuildLegLeft() override {
		p += ' ';
		p += '/';
	}
	void BuildLegRight() override {
		p += '\\';
	}

	void Show() override {
		cout << p << endl;
	}
};

//ָ������ʹ�ý����ߵĽӿ�
class PersonDirector
{
	PersonBuilder* pb;
public:
	PersonDirector():pb(nullptr) {}
	PersonDirector(PersonBuilder* pb) {
		this->pb = pb;
	}
	void CreatPerson() {
		pb->BuildHead();
		pb->BuildArmLeft();
		pb->BuildBody();
		pb->BuildArmRight();
		pb->BuildLegLeft();
		pb->BuildLegRight();

		pb->Show();
	}


	~PersonDirector() {
		if (pb) delete pb;
	}
};