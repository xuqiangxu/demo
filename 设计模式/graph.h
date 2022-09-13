#pragma once
#include<iostream>
#include<random>
#include<compare>
#include <queue>
#include<unordered_map>
using namespace std;


//拓扑排序
//将入度为0的点入队
//出队时对应指向的节点入度-1
//然后打印结果就ok

//edges情况是 [1,2],[2,3]这样存储的
vector<int> topologicalSort(int k, vector<vector<int>>& edges)
{
	//储存拓扑排序结果
	vector<int> ans;
	vector<int> indegree(k,0);
	//改成边结构
	vector<vector<int>> graph(k);
	//存储入度为0的节点
	queue<int> q;
	//后续处理即BFS 
	
	//预处理图像
	for (int i = 0; i < edges.size(); ++i)
	{
		int x = edges[i][0] - 1;
		int y = edges[i][1] - 1;
		//统计入度情况
		++indegree[y];
		graph[x].push_back(y);
	}

	//预处理队列
	for (int i = 0; i < k ; ++i) {
		if (indegree[i] == 0) q.push(i);
	}
	//执行BFS
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




