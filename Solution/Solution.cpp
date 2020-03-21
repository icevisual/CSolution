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

string vectorString(vector<string> arr,bool vertical = false) {

	string str = "[";
	if (vertical)
		str.append("\n");
	for (int i = 0; i < arr.size(); i++) {
		str.append(arr[i]);
		str.append(", ");
		if (vertical)
			str.append("\n");
	}
	str.append("]");
	return str;
}

void printVectorInt(vector<int> arr) {
	std::cout << vectorInt2String(arr) << endl;
}

void printVectorString(vector<string> arr, bool vertical = false) {
	std::cout << vectorString(arr, vertical) << endl;
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

template<typename T, typename T1>

bool KeyNotExistsAndSet(unordered_map<T, T1> &mp,pair<T,T1> val) {
	if (mp.find(val.first) == mp.end()) {
		mp.insert(val);
		return true;
	}
	return false;
}

template<typename T, typename T1>
bool KeyNotExistsAndSet(unordered_map<T, T1> &mp, T Key,T1 val) {
	if (mp.find(Key) == mp.end()) {
		mp.insert(pair<T,T1>(Key,val));
		return true;
	}
	return false;
}


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode * fromArray(vector<int> arr) {
	ListNode prehead(0);
	ListNode *p = &prehead;
	ListNode * result = &prehead;
	for (int i = 0; i < arr.size(); i++) {
		ListNode * t = new ListNode(arr[i]);
		p->next = t;
		p = p->next;
	}
	return result->next;
}

void printListNode(ListNode * node) {
	if (!node)
		return;
	do
	{
		cout << node->val << "->";
		node = node->next;
	} while (node);

	cout << endl;
}


class Solution {

public:

	vector<string> generateParenthesis(int n) {
		vector<string> result;

		if (n == 0) {
			return result;
		}
		if (n == 1) {
			result.push_back("()");
		}
		else if (n == 2) {
			result.push_back("(())");
			result.push_back("()()");
		}
		else {
		
			unordered_map <string, bool> hash;

			vector<string> r = generateParenthesis(n-1);

			for (int i = 0; i < r.size(); i++) {
				string f = "(" + r[i] + ")";
				if (KeyNotExistsAndSet(hash, f, true)) {
					result.push_back(f);
				}
				f = "()" + r[i];
				if (KeyNotExistsAndSet(hash, f, true)) {
					result.push_back(f);
				}
				f =  r[i] + "()";
				if (KeyNotExistsAndSet(hash, f, true)) {
					result.push_back(f);
				}

				for (int j = 1; j < r[i].length(); j++) {
					f = r[i].substr(0,j) + "()" + r[i].substr(j, r[i].length() - j);
					if (KeyNotExistsAndSet(hash, f, true)) {
						result.push_back(f);
					}
				}

			}
		}

		return result;
	}



	template <typename T>
	int halfSearch(vector<T> data, T target,int start,int end) {
	
		if (start >= end)
		{
			if (target < data[start])
				return start - 1;
			return start;
		}
		int mid = int((start + end) / 2);

		if (data[mid] == target)
			return mid;
		else if (data[mid] > target)
			return halfSearch(data, target,start,mid - 1);
		else 
			return halfSearch(data, target, mid  + 1,end);
	}


	int divide(int dividend, int divisor) {
		long dv = dividend;
		long di = divisor;
		int nag = 1;

		if (-2147483647 - 1 == dv && di == -1)
			return 2147483647;
		if (-2147483647 - 1 == dv && di == 1)
			return -2147483647 - 1;

		if (dv < 0)
		{
			dv = -dv;
			nag = -1;
		}
		if (di < 0)
		{
			di = -di;
			nag *= -1;
		}
		if (dv < di)
			return 0;

		if (di == 1)
			return nag * dv;

		// sum
		vector<long long> map;
		// count
		vector<int> idx;

		long long i = 1;
		long long v = di;
		map.push_back(v);
		idx.push_back(i);

		while (v < dv) {
		   //  * 2 改成 位移， 4ms => 0ms
			v <<= 1;
			i <<= 1;
			map.push_back(v);
			idx.push_back(i);
		}
		if (v == dv)
			return nag * i;

		int r = i / 2;
		long long d = dv - v / 2;
		int last_j = map.size() - 1;
		while (d > 0) {
			if (d < map[0])
				break;

			int id = halfSearch(map,d,0, last_j);
			last_j = id;

			if (map[id] == d)
			{
				r += idx[id];
				d = 0;
			}
			else
			{
				r += idx[id];
				d -= map[id];
			}
		}
		return nag * r;
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

							if (KeyNotExistsAndSet(ext, pair<string, bool>(ostrStream.str(), true))) {
								result.push_back(pr);
							}
						}
					}
				}

				l_it = hash.find(s);
				if (l_it != hash.end()) {
					ostringstream ostrStream;

					if (nums[i] > nums[j]) {
						ostrStream << nums[j] << "," << nums[i];
					}
					else {
						ostrStream << nums[i] << "," << nums[j];
					}

					if (KeyNotExistsAndSet(ext, pair<string, bool>(ostrStream.str(), true))) {
						hash[s].push_back({ i,j });
					}
				}
				else
				{
					hash.insert(pair<int, vector<vector<int>>>(s, { {i,j} }));
				}
			}
		}


		return result;
	}
	
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k <= 1)
			return head;
		// 反转使用数组
		vector<ListNode*> cache;
		// 前置一个节点 指向 head
		ListNode prehead(0);
		prehead.next = head;
		// 结果节点指针
		ListNode * result = &prehead;
		// 上阶段结束节点指针
		ListNode * p0 = &prehead;
		// 阶段开始指针
		ListNode * p1 = head;
		// 下一阶段开始指针
		ListNode * p2 = head->next;
		int i = k;
		do {
			i--;
			cache.push_back(head);
			if (i == 0) {
				p2 = head->next;
				head = p2;
				// reverse

				for (int j = k - 1; j >= 0; j--) {

					p0->next = cache[j];
					p0 = p0->next;
				}
				p0->next = p2;
				i = k;
				cache.clear();
			}
			else
				head = head->next;
		} while (head != NULL);
		return result->next;
	}
	
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
	//printVectorVectorInt(so.fourSum(v, 0));
	//printVectorVectorInt(so.fourSum(v1, 6));

	auto l = fromArray({ 1,2,3,4,5,6,7,8,9,0 });

	printVectorString(so.generateParenthesis(4),true);

	// cout << ((-2147483647 - 1) >> 1) << endl;
	// 1100540749
	// -1090366779
	// cout << so.divide(-2147483647 - 1, -1) << " "  << endl;
	
	//cout << so.divide(1100540749, -1090366779) << " " << int(ceil(1100540749 / -1090366779)) << endl;
	//cout << so.divide(2227, -2) << " " <<  int(ceil(2227/-2)) << endl;
	//cout << so.divide(123123, 123) << " " << int(ceil(123123 / 123)) << endl;
	//cout << so.divide(3343244, 56) << " " << int(ceil(3343244 / 56)) << endl;
	//cout << so.divide(2342, 444) << " " << int(ceil(2342 / 444)) << endl;

	// printVectorString(so.letterCombinations("23"));
	// [[-10,-2,8,10],[-9,-3,8,10],[-9,-2,7,10],[-9,0,7,8],[-4,-2,2,10],[-4,0,2,8],[-3,0,2,7],[0,2,2,2]]
	system("pause");
	return 0;
}


