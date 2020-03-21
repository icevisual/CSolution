// Solution.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <sstream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
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

string vectorString(vector<string> arr) {

	string str = "[";

	for (int i = 0; i < arr.size(); i++) {
		str.append(arr[i]);
		str.append(", ");
	}
	str.append("]");
	return str;
}

void printVectorInt(vector<int> arr) {
	std::cout << vectorInt2String(arr) << endl;
}

void printVectorString(vector<string> arr) {
	std::cout << vectorString(arr) << endl;
}
void printVectorVectorInt(vector<vector<int>> arr) {
	if (arr.size() == 0) {
		std::cout << "[]" << endl;
		return;
	}
	std::cout << "[" << endl;
	for (int i = 0; i < arr.size(); i++) {
		std::cout << "  " << vectorInt2String(arr[i]) << "," << endl;
	}
	std::cout << "]" << endl;
}
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		return head;
	}


public:
	vector<string>  c = { "",
	"","abc","def",
	"ghi","jkl","mno",
	"pqrs","tuv","wxyz"
	};
	vector<string> letterCombinations(string digits) {
		vector<string> result;
		int l = digits.length();

		if (l == 0)
			return result;

		if (l == 1) {
			int n = digits.at(0) - '0';
			for (int j = 0; j < c[n].length(); j++) {
				result.push_back(string({ c[n][j] }));
			}
			return result;
		}
		vector<string> first = letterCombinations(digits.substr(0,1));
		vector<string> rest = letterCombinations(digits.substr(1, l-1));

		for (int i = 0; i < first.size(); i++)
		{
			for (int j = 0; j < rest.size(); j++)
			{
				result.push_back(first[i] + rest[j]);
			}
		}

		return result;
	}

	vector<string> letterCombinations2(string digits) {
		vector<string> result;
		int c[] = {0,0,0,3,6,9,12,15,19,22,26,29};

		int l = digits.length();

		if (l == 1) {
			int n = digits.at(0) - '0';
			for (int j = c[n]; j < c[n + 1]; j++) {
				result.push_back(string({ (char)(j + 'a')}));
			}
		}


		for (int i = 2; i <= 9; i++)
		{
			for (int j = c[i]; j < c[i + 1]; j++) {
				char t = j + 'a';
				printf("%c ",t);
			}
			printf("\n");
		}

		for (int i = 0; i < digits.length(); i++)
		{
			int n = digits.at(i) - '0';



		}

		return result;
	}

	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		unordered_map<string, bool>  ext;
		unordered_map<int, vector<vector<int>>> hash;
		unordered_map<int, vector<vector<int>>>::iterator l_it;

		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); i++) {

			for (int j = i + 1; j < nums.size(); j++) {

				int s = nums[i] + nums[j];

				l_it = hash.find(target - s);
				if (l_it != hash.end())
				{
					for (int t = 0; t < l_it->second.size(); t++) {

						if (l_it->second[t][0] != i && l_it->second[t][0] != j && l_it->second[t][1] != i && l_it->second[t][1] != j) {

							vector<int> pr = { nums[l_it->second[t][0]],nums[l_it->second[t][1]] , nums[i], nums[j] };

							sort(pr.begin(), pr.end());

							ostringstream ostrStream;
							ostrStream << pr[0] << ",";
							ostrStream << pr[1] << ",";
							ostrStream << pr[2] << ",";
							ostrStream << pr[3];
			
							if (ext.find(ostrStream.str()) == ext.end()) {
								result.push_back(pr);
								ext.insert(pair<string, bool>(ostrStream.str(), true));
							}
						}
					}
				}

				l_it = hash.find(s);
				if (l_it != hash.end()) {
					hash[s].push_back({ i,j });
				}
				else
				{
					hash.insert(pair<int, vector<vector<int>>>(s, { {i,j} }));
				}
			}
		}


		return result;
	}
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> _map;
		vector<int> rrr;
		unordered_map<int, int>::iterator l_it;
		for (int i = 0; i < nums.size(); i++)
		{
			int sub = target - nums[i];

			l_it = _map.find(sub);
			if (l_it != _map.end()
				&& l_it->second != i)
			{
				rrr.push_back(i);
				rrr.push_back(l_it->second);
				return rrr;
			}
			_map.insert(pair<int, int>(nums[i], i));
		}
		return rrr;
	}


	int threeSumClosest(vector<int>& nums, int target) {

		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		int length = nums.size();

		int min = 999999;
		int min_sum = 0;

		for (int i = 0; i < length; i++) {
			int j = i + 1;
			int k = length - 1;

			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			while (j < k) {
				int s = nums[i] + nums[j] + nums[k];

				if (abs(s - target) < min) {
					min = abs(s - target);
					min_sum = s;
				}

				if (s == target) {
					return target;
				}
				else if (s > target) {
					k--;
				}
				else {
					j++;
				}
			}

		}

		return min_sum;
	}

	vector<vector<int>> threeSum(vector<int>& nums) {

		vector<vector<int>> result;

		sort(nums.begin(), nums.end());

		int length = nums.size();
		for (int i = 0; i < length; i++) {
			int j = i + 1;
			int k = length - 1;
			if (nums[i] > 0)
				break;
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			while (j < k) {
				int s = nums[i] + nums[j] + nums[k];
				if (s == 0) {
					result.push_back({ nums[i], nums[j] , nums[k] });
					while (j < k && nums[j + 1] == nums[j]) j++;
					while (j < k && nums[k - 1] == nums[k]) k--;
					j++;
					k--;
				}
				else if (s > 0) {
					k--;
				}
				else {
					j++;
				}
			}

		}
		return result;
	}
};


int main()
{
	vector<int> v = { 1, 0, -1, 0, -2, 2 };
	vector<int> v1 = { 0,2,2,2,10,-3,-9,2,-10,-4,-9,-2,2,8,7 };
	vector<int> v2 = { 1,1,1,1 };

	Solution so;
	printVectorVectorInt(so.fourSum(v, 0));
	printVectorVectorInt(so.fourSum(v1, 6));


	printVectorString(so.letterCombinations("23"));
	// [[-10,-2,8,10],[-9,-3,8,10],[-9,-2,7,10],[-9,0,7,8],[-4,-2,2,10],[-4,0,2,8],[-3,0,2,7],[0,2,2,2]]
	system("pause");
	return 0;
}


