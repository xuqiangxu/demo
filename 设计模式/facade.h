#pragma once

#include<iostream>
#include<mutex>
using namespace std;
/*******外观模式**********/

class Stock1
{
public:
	void buy() {
		cout << "buy Stock1"<<endl;
	}

	void sell() {
		cout << "sell Stock1"<<endl;
	}

};
class Stock2
{
public:
	void buy() {
		cout << "buy Stock2"<<endl;
	}

	void sell() {
		cout << "sell Stock2"<<endl;
	}

};
class Stock3
{
public:
	void buy() {
		cout << "buy Stock3"<<endl;
	}

	void sell() {
		cout << "sell Stock3"<<endl;
	}

};

class Fund 
{
	Stock1* s1 = nullptr;
	Stock2* s2 = nullptr;
	Stock3* s3 = nullptr;
public:
	Fund() {
		if (s1 == nullptr) {
			s1 = new Stock1();
		}
		if (s2 == nullptr) {
			s2 = new Stock2();
		}
		if (s3 == nullptr) {
			s3 = new Stock3();
		}
	}
	void BuyFund() {
		s1->buy();
		s2->buy();
		s3->buy();
	}
	void SellFund() {
		s1->sell();
		s2->sell();
		s3->sell();
	}

	~Fund() {
		if (s1) delete s1;
		if (s2) delete s2;
		if (s3) delete s3;
	}
};
