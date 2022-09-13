#pragma once
#include <iostream>
using namespace std;

//ģ�巽��ģʽ
class TestPaper
{
protected:
	virtual string answer1() = 0;
	virtual string answer2() = 0;
	virtual string answer3() = 0;
public:
	void TestQuestion1()
	{
		cout << "��һ�����ѡ����:" << endl;
		cout << answer1() << endl;
	}

	void TestQuestion2()
	{
		cout << "�ڶ������ѡ����:" << endl;
		cout << answer2() << endl;
	}

	void TestQuestion3()
	{
		cout << "���������ѡ����:" << endl;
		cout << answer3() << endl;
	}
};

class Student1 : public TestPaper
{
protected:
	string answer1() override
	{
		return "a";
	}
	string answer2() override
	{
		return "b";
	}
	string answer3() override
	{
		return "c";
	}
};

class Student2 : public TestPaper
{
protected:
	string answer1() override
	{
		return "d";
	}
	string answer2() override
	{
		return "a";
	}
	string answer3() override
	{
		return "b";
	}
};