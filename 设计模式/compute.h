#pragma once
#include<iostream>

class operation
{
public:
	double getNumA() {
		return this->numA;
	}
	void setNumA(double val) {
		this->numA = val;
	}
	double getNumB() {
		return this->numB;
	}
	void setNumB(double val) {
		this->numB = val;
	}
	virtual double getResult() {
		double result = 0;
		return result;
	}
private:
	double numA = 0;
	double numB = 0;
};


class operationAdd : public operation {
public:
	double getResult() override {
		double result = 0;
		result = getNumA() + getNumB();
		return result;
	}
};

class operationSub : public operation {
public:
	double getResult() override {
		double result = 0;
		result = getNumA() - getNumB();
		return result;
	}
};

class operationMul : public operation {
public:
	double getResult() override {
		double result = 0;
		result = getNumA() * getNumB();
		return result;
	}
};

class operationDiv : public operation {
public:
	double getResult() override {
		double result = 0;
		if (getNumB() == 0) {
			throw std::exception("除数不能为0.");
		}
		result = getNumA() / getNumB();
		return result;
	}
};


//简单工厂类
class operationFac {
public :
	static operation* creatOperate(const char operate) {
		operation* oper = nullptr;
		switch (operate) {
		case '+' :
			oper = new operationAdd();
			break;
		case '-':
			oper = new operationSub();
			break;
		case '*':
			oper = new operationMul();
			break;
		case '/':
			oper = new operationDiv();
			break;
		}
		return oper;
	}
};