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

string vectorString(vector<string> arr, bool vertical = false) {

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

void printVector(vector<int> arr) {
	std::cout << vectorInt2String(arr) << endl;
}
void printVector(vector<vector<int>> arr) {
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
void printVector(vector<string> arr, bool vertical = false) {
	std::cout << vectorString(arr, vertical) << endl;
}


template<typename T, typename T1>

bool KeyNotExistsAndSet(unordered_map<T, T1> &mp, pair<T, T1> val) {
	if (mp.find(val.first) == mp.end()) {
		mp.insert(val);
		return true;
	}
	return false;
}

template<typename T, typename T1>
bool KeyNotExistsAndSet(unordered_map<T, T1> &mp, T Key, T1 val) {
	if (mp.find(Key) == mp.end()) {
		mp.insert(pair<T, T1>(Key, val));
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



bool cmp_vector_int(vector<int> a, vector<int> b)
{
	return a[0] < b[0];
}


class Solution {

public:
	void combinationSumR(vector<int>& candidates, int target,int start_idx) {
		vector<int> result;
		int t = target;
		for (int i = start_idx; i >= 0; i--)
		{
			while (candidates[i] <= target) {
				result.push_back(candidates[i]);
				
				target -= candidates[i];
			}
		}

		printVector(result);


		if (start_idx != 0)
			combinationSumR(candidates, t, start_idx - 1);

	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		sort(candidates.begin(), candidates.end());

		combinationSumR(candidates,target, candidates.size() - 1);
		return result;
	}

	bool isValidSudoku(vector<vector<char>>& board) {

		int flags[10][10][10] = {0};

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] == '.') {
					for (int k = 0; k < 9; k++)
					{
						if (board[i][k] != '.')
						{
							flags[i][j][board[i][k] - '0'] = 1;
						}

						if (board[k][j] != '.')
						{
							flags[i][j][board[k][j] - '0'] = 1;
						}
					}

					int m0i = (int)(i / 3);
					int m0j = (int)(j / 3);

					for (int ti = m0i * 3; ti < m0i * 3 + 3;ti ++)
					{

						for (int tj = m0j * 3; tj < m0j * 3 + 3; tj++)
						{
							if (board[ti][tj] != '.')
							{
								flags[i][j][board[ti][tj] - '0'] = 1;
							}
						}
					}

				}
		
			}


		}

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] == '.') {
					printf("(%d, %d) ",i,j);
					printVector(vector<int>(flags[i][j] + 1, flags[i][j] + 10));
				}
			}
		}

		//printVectorInt(vector<int>(flags[0][2], flags[0][2] + 10));
		//printVectorInt(vector<int>(flags[1][1], flags[1][1] + 10));
		//printVectorInt(vector<int>(flags[1][2], flags[1][2] + 10));
		//printVectorInt(vector<int>(flags[2][0], flags[2][0] + 10));


		return false;
	}

	void rotate(vector<vector<int>>& matrix) {

		int n = matrix.size();
		//printVectorVectorInt(matrix);

		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				int t = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = t;
			}
		}

		//printVectorVectorInt(matrix);

		int hn = (int)(n / 2);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < hn; j++)
			{
				int t = matrix[i][j];
				matrix[i][j] = matrix[i][n - j - 1];
				matrix[i][n - j - 1] = t;
			}
		}


		//printVectorVectorInt(matrix);

	}

	//  1, 2, 3 → 1, 3, 2
	//	3, 2, 1 → 1, 2, 3
	//	2, 3, 1 → 3  1  2
	//	1, 1, 5 → 1, 5, 1

	void nextPermutation(vector<int>& nums) {

	}



	vector<vector<int>> merge(vector<vector<int>>& intervals) {

		vector<vector<int>> result;

		int len = intervals.size();
		if (len == 0)
			return result;

		sort(intervals.begin(), intervals.end(), cmp_vector_int);

		result.push_back(intervals[0]);
		int idx = 0;
		for (int i = 1; i < len; i++)
		{
			if (intervals[i][0] <= result[idx][1]) {
				result[idx][1] = max(intervals[i][1], result[idx][1]);
			}
			else
			{
				result.push_back(intervals[i]);
				idx++;
			}
		}


		return result;
	}


	vector<int> spiralOrder(vector<vector<int>>& matrix) {

		vector<int> result;

		// 空输入
		// 典型输入，这里是 只有一行，只有一束

		int m = matrix.size();

		if (m == 0)
			return result;
		int n = matrix[0].size();
		int start_x = 0;
		while (n > 0 && m > 0) {

			for (int i = start_x; i < start_x + n; i++)
			{
				result.push_back(matrix[start_x][i]);
			}
			for (int i = start_x + 1; i < start_x + m; i++)
			{
				result.push_back(matrix[i][start_x + n - 1]);
			}
			for (int i = start_x + n - 2; i >= start_x && m > 1; i--)
			{
				result.push_back(matrix[start_x + m - 1][i]);
			}
			for (int i = start_x + m - 2; i > start_x && n > 1; i--)
			{
				result.push_back(matrix[i][start_x]);
			}

			m -= 2;
			n -= 2;
			start_x += 1;
		}

		return result;

	}

	void backtrack(vector<string> &result, int n, string s, int left, int right) {
		cout << ":" << s << endl;
		if (s.length() == 2 * n) {
			result.push_back(s);
			return;
		}
		if (left < n)
			backtrack(result, n, s + "(", left + 1, right);
		if (right < left)
			backtrack(result, n, s + ")", left, right + 1);
	}

	vector<string> generateParenthesis(int n) {
		vector<string> result;
		backtrack(result, n, "", 0, 0);
		return result;
	}

	vector<string> generateParenthesis0(int n) {
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

			vector<string> r = generateParenthesis(n - 1);

			for (int i = 0; i < r.size(); i++) {
				string f = "(" + r[i] + ")";
				if (KeyNotExistsAndSet(hash, f, true)) {
					result.push_back(f);
				}
				f = "()" + r[i];
				if (KeyNotExistsAndSet(hash, f, true)) {
					result.push_back(f);
				}
				f = r[i] + "()";
				if (KeyNotExistsAndSet(hash, f, true)) {
					result.push_back(f);
				}

				for (int j = 1; j < r[i].length(); j++) {
					f = r[i].substr(0, j) + "()" + r[i].substr(j, r[i].length() - j);
					if (KeyNotExistsAndSet(hash, f, true)) {
						result.push_back(f);
					}
				}

			}
		}

		return result;
	}

	template <typename T>
	int halfSearch(vector<T> data, T target, int start, int end) {

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
			return halfSearch(data, target, start, mid - 1);
		else
			return halfSearch(data, target, mid + 1, end);
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

			int id = halfSearch(map, d, 0, last_j);
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
		vector<string> first = letterCombinations(digits.substr(0, 1));
		vector<string> rest = letterCombinations(digits.substr(1, l - 1));

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

// Ctrl + M,Ctrl + A 全部折叠
// Ctrl + M,Ctrl + X 全部展开

int main()
{
	vector<int> v = { 1, 0, -1, 0, -2, 2 };
	vector<int> v1 = { 0,2,2,2,10,-3,-9,2,-10,-4,-9,-2,2,8,7 };
	vector<int> v2 = { 1,1,1,1 };

	Solution so;

	vector<vector<int>> mtx = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	vector<vector<int>> mtx3 = {
		{1, 2, 3, 4},
		{ 5, 6, 7, 8 },
		{ 9,10,11,12 },
		{ 13,14,15,16 }
	};
	vector<vector<int>> mtx23 = { {2,6},{8,10},{15,18} ,{1,3}, };

	vector<vector<int>> mtx231 = { {1,4},{2,3} };
	//{{1,4},{4,5}}
	vector<vector<char>> mtx2 = {
	  {'5','3','.','.','7','.','.','.','.'},
	  {'6','.','.','1','9','5','.','.','.'},
	  {'.','9','8','.','.','.','.','6','.'},
	  {'8','.','.','.','6','.','.','.','3'},
	  {'4','.','.','8','.','3','.','.','1'},
	  {'7','.','.','.','2','.','.','.','6'},
	  {'.','6','.','.','.','.','2','8','.'},
	  {'.','.','.','4','1','9','.','.','5'},
	  {'.','.','.','.','8','.','.','7','9'}
	};
	//so.isValidSudoku(mtx2);
	//printVectorInt(so.spiralOrder(mtx23));

	vector<int> arr000 = { 2,3,6,7 };

	printVector(so.combinationSum(arr000, 7));

	//printVector(so.merge(mtx231));

	//merge

	//
	//vector<vector<int>> mtx1 = {
	//  { 5, 1, 9,11},
	//  { 2, 4, 8,10},
	//  {13, 3, 6, 7},
	//  {15,14,12,16}
	//};

	//so.rotate(mtx1);

	//printVectorVectorInt(so.fourSum(v, 0));
	//printVectorVectorInt(so.fourSum(v1, 6));

	//auto l = fromArray({ 1,2,3,4,5,6,7,8,9,0 });

	//printVectorString(so.generateParenthesis(2), true);

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


