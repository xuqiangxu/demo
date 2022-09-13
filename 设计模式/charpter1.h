#pragma once
#include<iostream>
#include<random>
#include <compare>
using namespace std;

template<typename T>
void arrPrint(T& arr)
{
	cout << "[ ";
	for (const auto& x : arr) {
		cout << x << " ";
	}
	cout << "]" << endl;
}

//简单插入排序
template<typename T>
void InnsertionSort(T& arr)
{
	int n = arr.size();
	for (int i = 1; i < n; ++i) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}


//递归快排-----非随机化
template<typename T>
void QuickSort(T& arr,int left , int right)
{
	if (left >= right) return;
	int idx = left + rand() % (right - left + 1);
	swap(arr[left], arr[idx]);
	int base = arr[left];
	//确认base在arr中位置
	int l = left , r = right;
	while (l < r) {
		while (l < r && arr[r] >= base) {
			--r;
		}
		if (l < r) {
			arr[l] = arr[r];
		}
		while (l < r && arr[l] < base) ++l;
		if (l < r) {
			arr[r] = arr[l];
		}
	}
	arr[l] = base;
	QuickSort(arr, left, l - 1);
	QuickSort(arr, l + 1, right);
}


template<typename T>
void QuickSort(T& arr)
{
	int n = arr.size();
	QuickSort(arr, 0, n - 1);
}



template<typename T>
void Merge(T& arr, int Lstart, int Lend, int Rstart, int Rend) {
	if (Rstart > Rend) return;
	int size = Rend - Lstart + 1;
	int lptr = Lstart;
	vector<int> tmp(size, 0);
	int idx = 0;
	while (Lstart <= Lend && Rstart <= Rend) {
		while (Lstart <= Lend && arr[Lstart] <= arr[Rstart]) {
			tmp[idx++] = arr[Lstart++];
		}
		while (Rstart <= Rend && arr[Lstart] >= arr[Rstart]) {
			tmp[idx++] = arr[Rstart++];
		}
	}
	while (Lstart <= Lend) {
		tmp[idx++] = arr[Lstart++];
	}
	while (Rstart <= Rend) {
		tmp[idx++] = arr[Rstart++];
	}
	for (int i = 0; i < size; ++i) {
		arr[lptr++] = tmp[i];
	}
}

//非递归实现归并排序 ?怎么搞
template<typename T>
void MergeSort(T& arr)
{
	int len = arr.size();
	int Lstart = 0,	Rstart = 0, Lend = 0, Rend = 0;

	for (int i=1; i < len; i*=2 ) {
		Lstart = 0;
		while (Rend < len - 1) {
			Lend = Lstart + i - 1;
			Rstart = Lend + 1;
			Rend = min(Rstart + i - 1, len-1);
			//合并L 和 R 
			int size = Rend - Lstart + 1;
			Merge(arr, Lstart, Lend, Rstart, Rend);
			Lstart = Rend + 1;
		}
		Rend = 0;
	}

}





