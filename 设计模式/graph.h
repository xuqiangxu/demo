#pragma once
#include<iostream>
#include<random>
#include<compare>
#include <queue>
#include<unordered_map>
using namespace std;


//��������
//�����Ϊ0�ĵ����
//����ʱ��Ӧָ��Ľڵ����-1
//Ȼ���ӡ�����ok

//edges����� [1,2],[2,3]�����洢��
vector<int> topologicalSort(int k, vector<vector<int>>& edges)
{
	//��������������
	vector<int> ans;
	vector<int> indegree(k,0);
	//�ĳɱ߽ṹ
	vector<vector<int>> graph(k);
	//�洢���Ϊ0�Ľڵ�
	queue<int> q;
	//��������BFS 
	
	//Ԥ����ͼ��
	for (int i = 0; i < edges.size(); ++i)
	{
		int x = edges[i][0] - 1;
		int y = edges[i][1] - 1;
		//ͳ��������
		++indegree[y];
		graph[x].push_back(y);
	}

	//Ԥ�������
	for (int i = 0; i < k ; ++i) {
		if (indegree[i] == 0) q.push(i);
	}
	//ִ��BFS
	while (!q.empty()) {
		int from = q.front();
		q.pop();
		ans.push_back(from+1);
		for (int to : graph[from]) {
			if (--indegree[to] == 0) q.push(to);
		}
	}
	return ans;
}




