#pragma once
#include<iostream>
#include <string>
using namespace std;
/************原型模式******************/

class Prototype
{
public:
	Prototype() {}
	virtual ~Prototype() = default;
	virtual Prototype* clone() = 0;
};

class WorkExperience : public Prototype
{
	string m_workData;
	string m_company;
public:
	WorkExperience() = default;
	WorkExperience(const string& workData, const string& company) {
		m_workData = workData;
		m_company = company;
	}
	void SetWorkData(const string& workData) {
		m_workData = workData;
	}
	string GetWorkData() {
		return m_workData;
	}
	void SetCompany(const string& company) {
		m_company = company;
	}
	string GetCompany() {
		return m_company;
	}
	Prototype* clone() override {
		return new WorkExperience(*this);
	}
};

class Resume : public Prototype
{
	string m_name;
	string m_sex;
	string m_age;
	string m_timeArea;
	string m_company;
	WorkExperience* m_workExp=nullptr;	
	//深拷贝
	Resume(WorkExperience* workEx) {
		if (m_workExp) delete m_workExp;
		m_workExp = (WorkExperience*)workEx->clone();
	}
public:
	Resume() {};
	Resume(const string& name) : m_name(name) {}


	//设置个人信息
	void SetPersonInfo(const string& sex, const string& age) {
		m_sex = sex;
		m_age = age;
	}
	//设置工作经历
	void SetWorkExperience(const string& timeArea,const string& company) {
		if (m_workExp == nullptr)
		{
			m_workExp = new WorkExperience(timeArea, company);
		}
		else {
			m_workExp->SetCompany(company);
			m_workExp->SetWorkData(timeArea);
		}
	}
	void Display() {
		cout << m_name << " " << m_sex << " " << m_age << endl;
		cout << m_workExp->GetCompany() << " " << m_workExp->GetWorkData() << endl;
	}
	Prototype* clone() override {
		Resume* obj = new Resume(this->m_workExp);
		obj->m_name = this->m_name;
		obj->m_sex = this->m_sex;
		obj->m_age = this->m_age;
		return obj;
	}
	~Resume() override {
		delete m_workExp;
	}

};