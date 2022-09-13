#pragma once
#include<iostream>
using namespace std;

class LeiFeng
{
public:
	void sweep()
	{
		cout << "É¨µØ" << endl;
	}
	void wash() 
	{
		cout << "Ï´ÒÂ" << endl;
	}
	void buyRice()
	{
		cout << "ÂòÃ×" << endl;
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

