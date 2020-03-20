// Solution.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

string vectorInt2String(vector<int> arr) {

	string str = "[";

	for (int i = 0; i < arr.size(); i++) {
		ostringstream ostrStream;
		ostrStream << arr[i];
		str.append(ostrStream.str());
		str.append(", ");
	}
	str.append("]");
	return str;
}

void printVector(vector<vector<int>> arr) {
	if (arr.size() == 0) {
		cout << "[]" << endl;
		return;
	}
	cout << "[" << endl;
	for (int i = 0; i < arr.size(); i++) {
		cout << "  " << vectorInt2String(arr[i]) << "," << endl;
	}
	cout << "]" << endl;
}


class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		vector<vector<int>> result;


		return result;
	}
};


int main()
{
	vector<int> v = { -1, 0, 1, 2, -1, -4 };
	Solution so;
	printVector(so.threeSum(v));
	system("pause");
	return 0;
}
