#pragma once
#include<iostream>
using namespace std;

class LeiFeng
{
public:
	void sweep()
	{
		cout << "ɨ��" << endl;
	}
	void wash() 
	{
		cout << "ϴ��" << endl;
	}
	void buyRice()
	{
		cout << "����" << endl;
	}
};

class UnderGraduate : public LeiFeng
{
};

class Volunteer : public LeiFeng
{
};

class IFactory
{
public:
	virtual LeiFeng* CreatLeiFeng() = 0;
};


class UnderGraduateFactory :public IFactory
{
public:
	LeiFeng* CreatLeiFeng() {
		return new UnderGraduate();
	}
};

class VolunteerFactory :public IFactory
{
public:
	LeiFeng* CreatLeiFeng() {
		return new Volunteer();
	}
};

