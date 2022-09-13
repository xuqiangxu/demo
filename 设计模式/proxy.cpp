#include<iostream>
#include<vector>
#include<unordered_set>
#include <random>
#include<string>
#include <queue>
#include "proxy.h"
using namespace std;


void proxyTest()
{
	SchoolGirl* jiaojiao = new SchoolGirl("LJJ");
	Proxy daili(jiaojiao);
	daili.GiveChocolate();
	daili.GiveDolls();
	daili.GiveFlowers();
}
