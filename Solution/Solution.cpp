// Solution.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <sstream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
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
		str.append("\"");
		str.append(arr[i]);
		str.append("\", ");
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

class Reg {

public:
	string str;
	int min_count = 0;
	bool repeatable = false;
};


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define IN_MAP(t,v) (t.find(v) != t.end())
 
class Solution {

public:   
	string minWindow(string s, string t) {
	
	}
	string minWindow0(string s, string t) {


		if (s == "" || t == "")
			return "";
		
		
		cout << "s = " << s << " t = " << t << endl;

		unordered_map<char, vector<int>> mp;
		unordered_map<char, int> f;

		for (int i = 0; i < t.length(); i++)
		{
			if (!IN_MAP(mp, t.at(i)))
			{
				mp.insert(pair<char, vector<int>>(t.at(i), {1,0}));
				f.insert(pair<char, int>(t.at(i), 1));
			}
			else
			{
				mp[t.at(i)][0] ++;
	
			}
		}
		int n = s.length();
		int l = 0, r = 0;
		int min_l = -1, min_r = 100000;
		while (r < n)
		{
			while (!f.empty() && r < n)
			{
				if(IN_MAP(mp, s.at(r)))
				{
					mp[s.at(r)][1]++;
					if(mp[s.at(r)][1] == mp[s.at(r)][0])
					// 标志为已有
					{
						f.erase(s.at(r));
					}
				}
				else
				{
				}
				r++;
			}
			if (f.empty())
			{
				while (l <= r)
				{
					if (IN_MAP(mp, s.at(l)))
					{
						if (mp[s.at(l)][1] == mp[s.at(l)][0])
						{

							if (r - l < min_r - min_l)
							{
								min_l = l;
								min_r = r;
								if(min_r - min_l == t.length())
									return s.substr(min_l, min_r - min_l);
							}
						}
						mp[s.at(l)][1]--;

						if (mp[s.at(l)][1] < mp[s.at(l)][0])
						{
							f.insert(pair<char, int>(s.at(l), 0));
							l++;
							break;
						}
					}
					l++;
				}
			}
			cout << s.substr(l, r - l) << endl;
			
		}
		if (min_l == -1)
			return "";
		return s.substr(min_l,min_r - min_l);
	}



	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 2)
			return nums.size();
		int p = 1;
		for (int i = 2; i < nums.size(); i++)
		{
			if (nums[p - 1] == nums[p] && nums[p] == nums[i]) {
			
			}
			else
			{
				nums[++p] = nums[i];
			}
		}
		return p + 1;
	}

	ListNode* deleteDuplicates(ListNode* head) {

		ListNode result(-1); 
		result.next = head;
		ListNode *p = &result;
	REP:
		while (head != NULL)
		{

			bool has_rep = false;
			while (head->next != NULL && head->val == head->next->val)
			{
				head = head->next;
				has_rep = true;
			}
			if (has_rep)
			{
				
				head = head->next;
				if (NULL == head)
					p->next = head;
				goto REP;
			}
			p->next = head;
			p = head;
			if (NULL != head)
				head = head->next;
		}
		return result.next;
	}

	bool search(vector<int>& nums, int target) {

		int n = nums.size();
		if (n == 0)
			return false;
		if (n == 1)
			return nums[0] == target;
		int i = 1;

		while (i < n && nums[i - 1] <= nums[i])
		{
			i++;
		}
		if (i == n)
		{
			int idx = halfSearch(nums, target, 0, n - 1);
			return idx >=0 && nums[idx] == target;
		}
		else {
			if (target >= nums[0] && target <= nums[i - 1])
			{
				int idx = halfSearch(nums, target, 0, i - 1);
				return nums[idx] == target;
			}
			else {
				int idx = halfSearch(nums, target, i, n - 1);
				return nums[idx] == target;
			}

		}

		return false;
	}

	bool exist(vector<vector<char>>& board, string word) {
		vector<vector<vector<int>>> mp(27);

		int n = board.size();
		int m = board[0].size();

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				mp[board[i][j] - 'A'].push_back({ i,j });
			}
		}

		for (int i = 0; i < word.size(); i++)
		{
			auto p =  mp[word[i] - 'A'];
			if (p.size() == 0)
				return false;
			else
			{

			}
		}

		return false;
	}

	vector<int> inorderTraversal(TreeNode* root) {
		
		vector<int> result;
		if (root == NULL)
			return result;
		stack<TreeNode*> st;

		st.push(root);


		while (!st.empty())
		{
			TreeNode* node = st.top();

			if (node->left != NULL)
			{
				st.push(node->left);
				node->left = NULL;
			}
			else
			{
				result.push_back(node->val);
				st.pop();

				if (node->right != NULL)
				{
					st.push(node->right);
					node->right = NULL;
				}
			}

		}


		return result;
	}

	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == NULL || head->next == NULL)
			return head;
		m--;
		n--;
		ListNode r(0);// pre first
		r.next = head;
		ListNode* phead = &r;// pre first
		
		while (m > 0 && head->next != NULL)
		{
			phead = head;
			head = head->next;
			m--;
			n--;
		}
		ListNode* ehead = head;// last node

		ListNode* shead = ehead;

		head = head->next;
	
		ListNode* t;
		while (n > 0)
		{
			if (head == NULL)
				break;
			t = head;
			head = head->next;
		
			t->next = shead;
			shead = t;
			n--;
		}
		phead->next = shead;
		ehead->next = head;

		return r.next;
	}

	int numDecodings(string s) {
		if (s.at(0) == '0')
			return 0;
		vector<int> c;
		c.push_back(1);
		c.push_back(1);



		vector<int> t;

		// 处理 0 
		for (int i = 0; i < s.length(); i++)
		{
			int cn = s.at(i) - '0';

			if (cn == 0 || (i + 1 < s.length() && s.at(i + 1) == '0'))
			{
				if (cn > 2 || cn == 0)
					return 0;
				else
				{// 10 20 不可与前结合
					t.push_back(60);
					i++;
				}
			}
			else
			{
				t.push_back(cn);
			}
		}
		for (int i = 1; i < t.size(); i++)
		{

			int cn = t[i];
			int cn0 = t[i - 1] * 10 + t[i];


			if (cn0 > 26) {
				c.push_back(c[i]);
			}
			else
			{
				c.push_back(c[i] + c[i-1]);
			}
		}

		return c[t.size()];
	}

	string simplifyPath(string path) {

		stack<string> paths;
		int si = -1;
		int ei = -1;
		int i = 0;
		int len = path.length();
		while (i < len)
		{
			while (i < len && path.at(i) == '/')
			{
				i++;
			}
			si = i - 1;
			if (i < len)
			{
				if (path.at(i) == '.') {
					
					ei = si + 1;
					while (ei < len && path.at(ei) != '/')
					{
						ei++;
					}
					string pn = path.substr(si, ei - si);

					if (pn.size() ==3  && pn[2] == '.')
					{
						if (paths.size() > 0)
							paths.pop();
					}
					else if (pn.size() == 2)
					{

					}
					else {
						paths.push(pn);
					}

					i = ei;

				}
				else
				{
					ei = si + 1;
					while (ei < len && path.at(ei) != '/')
					{
						ei++;
					}
					paths.push(path.substr(si,ei - si));
					i = ei;
				}
			}
		}

		if (paths.size() == 0)
			return "/";
		stack<string> pathsr;
		ostringstream os;
		while (!paths.empty())
		{
			pathsr.push(paths.top());
			paths.pop();
		}

		while (!pathsr.empty())
		{
			os << pathsr.top();
			pathsr.pop();
		}

		return os.str();
	}

	void sortColors(vector<int>& nums) {

		char f[] = { 0,0,0 };

		for (int i = 0; i < nums.size(); i++)
		{
			f[nums[i]] ++;
		}
		int j = 0;
		for (int i = 0; i < 3; i++)
		{
			while (f[i] > 0) {
				nums[j++] = i;
				f[i] --;
			}
		}
	}


	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int n = matrix.size();
		if (n == 0)
			return false;
		int m = matrix[0].size();
		if (m == 0)
			return false;
		for (int i = 0; i < n; i++)
		{
			if (target >= matrix[i][0] && target <= matrix[i][m - 1])
			{
				int t = halfSearch(matrix[i],target,0,m - 1);
				if (matrix[i][t] != target)
					return false;
				else
				{
					return true;
				}
			}

		}
		return false;
	}


	void setZeroes(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int m = matrix[0].size();

		vector<int> nf(n);
		vector<int> mf(m);
		for (int i = 0; i < n; i++)
			nf[i] = 0;
		for (int i = 0; i < m; i++)
			mf[i] = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (matrix[i][j] == 0)
				{
					nf[i] = 1;
					mf[j] = 1;
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			if (nf[i] == 1)
			{
				
				for (int j = 0; j < m; j++)
				{
					matrix[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < m; i++)
		{
			if (mf[i] == 1)
			{
				for (int j = 0; j < n; j++)
				{
					matrix[j][i] = 0;
				}
			}
		}

	}

	int gn[100] = { 0 };

	void calc_gaps(int s, int n)
	{
		int last = floor(s * 1.0 / (n - 1));

		int rest = s - last * (n - 1);

		for (int i = 0; i < n; i++)
		{
			gn[i] = last;
			if (rest)
			{
				gn[i] ++;
				rest--;
			}
		}

	}

	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> result;
		int line_len_sum = 0;
		int line_word_count = 0;
		char val[100] = { 0 };

		for (int i = 0; i < 100; i++)
			val[i] = ' ';
		

		for (int i = 0; i < words.size(); i++)
		{
			
			if (line_len_sum + words[i].length() + line_word_count > maxWidth)
			{
				int gap = maxWidth - line_len_sum;
				
				if (line_word_count > 1)
				{
					calc_gaps(gap, line_word_count);
					int first = ceil(gap * 1.0 / (line_word_count - 1));
					int last = floor(gap * 1.0 / (line_word_count - 1));
		
					ostringstream os;
					int s = 0;
					for (int j = line_word_count - 1; j > 0; j--) {
						os << words[i - 1 - j];
						if (j == 1) {
		
							os << string(val, gn[s++]);
						}
						else
							os << string(val, gn[s++]);
					}
					os << words[i - 1];
					result.push_back(os.str());
				}
				else
				{
					ostringstream os;
					os << words[i - 1];
					os << string(val, gap);
					result.push_back(os.str());
				}

				line_len_sum = words[i].length();
				line_word_count = 1;
			}
			else
			{
				line_len_sum += words[i].length();
				line_word_count++;
			}
		}

		if (line_word_count > 0)
		{
			ostringstream os;
			for (int j = line_word_count - 1; j > 0; j--) {
				os << words[words.size() - 1 - j];
				os << " ";
			}
			os << words[words.size() - 1];

			int gap = maxWidth - line_len_sum - (line_word_count - 1);
			if (gap > 0)
			{
				os << string(val,gap);
				result.push_back(os.str());
			}
			else
				result.push_back(os.str());
		}

		return result;
	}

	bool isNumber(string s) {

		int t = 0;
		while (t < s.length() && s.at(t) == ' ') t++;
		if (t)
		{
			if (t == s.length())
				return false;
			s = s.substr(t);
		}
		t = s.length() - 1;
		while (s.at(t) == ' ') t--;
		if (t != s.length() - 1)
			s = s.substr(0,t + 1);

		unordered_map<string, bool> flagMap;
		// 数字符号、数字、数字点号、E、e数字符号、e数字、e数字点号
		flagMap.insert(pair<string, bool>("Sign_N", false));
		flagMap.insert(pair<string, bool>("Number_N", false));
		flagMap.insert(pair<string, bool>("Number_N_Before", false));
		flagMap.insert(pair<string, bool>("Number_N_Point", false));
		flagMap.insert(pair<string, bool>("Number_N_After", false));
		flagMap.insert(pair<string, bool>("Symbol_E", false));
		flagMap.insert(pair<string, bool>("Sign_E", false));
		flagMap.insert(pair<string, bool>("Number_E", false));
		flagMap.insert(pair<string, bool>("Number_E_Point", false));


		for (int i = 0; i < s.length(); i++)
		{
			char ch = s.at(i);
			if (ch >= '0' && ch <= '9')
			{
				if (!flagMap["Symbol_E"])
				{
					flagMap["Number_N"] = true;
					if (flagMap["Number_N_Point"])
					{
						flagMap["Number_N_After"] = true;
					}
					else
					{
						flagMap["Number_N_Before"] = true;
					}
				}
				else
				{
					flagMap["Number_E"] = true;
				}
			}
			else if (ch == 'e')
			{
				// 前无合法数字
				if (!flagMap["Number_N"])
					return false;
				if (flagMap["Symbol_E"])
					return false;
				flagMap["Symbol_E"] = true;
			}
			else if (ch == '+' || ch == '-')
			{
				if (i - 1 >= 0 && (s.at(i - 1) >= '0' && s.at(i - 1) <= '9'))
					return false;
				if (i - 1 >= 0 && (s.at(i - 1) == '.'))
					return false;
				if (!flagMap["Symbol_E"])
				{
					// 已有符号
					if (flagMap["Sign_N"])
						return false;
					
					// 下一个不是数字
					if(i + 1 >= s.length() || ( (s.at(i+1) < '0' || s.at(i + 1) > '9') && s.at(i + 1) != '.') )
						return false;
					flagMap["Sign_N"] = true;
				}
				else
				{// 已有符号
					if (flagMap["Sign_E"])
						return false;
					if (i + 1 >= s.length() || (s.at(i + 1) < '0' || s.at(i + 1) > '9'))
						return false;
					flagMap["Sign_E"] = true;
				}
			}
			else if (ch == '.')
			{
				// E 之后不能有小数点
				if (flagMap["Symbol_E"])
				{
					return false;
				}
				// 已有小数点
				if (flagMap["Number_N_Point"])
				{
					return false;
				}
				// 没有前导数
				/*if (i - 1 >= 0 && (s.at(i - 1) == '-' || s.at(i - 1) == '+'))
					return false;*/
				//// 上一个不是数字
				//if (i - 1 < 0 || (s.at(i - 1) < '0' || s.at(i - 1) > '9'))
				//	return false;
				// 下一个不是数字
		/*		if (i + 1 >= s.length() || (s.at(i + 1) < '0' || s.at(i + 1) > '9'))
					return false;*/
				flagMap["Number_N_Point"] = true;
			}
			else if (ch == ' ')
			{
				return false;
			}
			else
				return false;
		}
		if (flagMap["Number_N_Point"] && (!flagMap["Number_N_Before"]&&!flagMap["Number_N_After"]))
		{
			return false;
		}
		if (flagMap["Symbol_E"] && !flagMap["Number_E"])
			return false;

		return true;
	}

	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL)
			return head;
		if (head->next == NULL)
			return head;
		if (k == 0)
			return head;
		// 头指针，用于记录原始头，用于和尾部合并
		ListNode* phead = head;
		// 落后头指针 k 步的节点，指向新的末尾节点
		ListNode* nhead = NULL;
		int c = 0;
		int t = 0;
		while (head->next)
		{
			head = head->next;
			t++;
		}
		t ++ ;
		// 头尾结合
		head->next = phead;
		head = head->next;
		k = t - k % t;
		// 步数未到，在圈内循环
		while (c < k)
		{
			c++;
			phead = head;
			head = head->next;
		}

		phead->next = NULL;
		return head;
	}

	string getPermutation(int n, int k) {
		vector<int> flag(n + 1);
		for (int i = 0; i <= n; i++)
			flag[i] = 1;

		vector<int> je;
		je.push_back(1);
		je.push_back(1);
		je.push_back(2);
		for (int i = 3; i < n; i++)
		{
			je.push_back(je[i - 1] * i);
		}

		int kn = je[n - 1];

		ostringstream os;
		// 确认是第几个数，从标记数组取
		// 

		for (int i = 0; i < n; i++)
		{
			kn = je[n - i - 1];
			int c = (int)ceil(k * 1.0 / kn);
			int t = c;
			for (int i = 1; i <= n; i++)
			{
				if (flag[i] == 1)
				{
					c--;
					if (c <= 0)
					{
						os << i;
						flag[i] = 0;
						break;
					}
				}
			}
			k = k - kn * (t - 1);

		}


		return os.str();
	}

	vector<vector<int>> generateMatrix(int n) {


		vector<vector<int>> result(n);

		for (int i = 0; i < n; i++)
			result[i] = vector<int>(n);
		// 空输入
		// 典型输入，这里是 只有一行，只有一束

		int m = n;

		if (m == 0)
			return result;
		int start_x = 0;
		int t = 1;
		while (n > 0 && m > 0) {

			for (int i = start_x; i < start_x + n; i++)
			{
				result[start_x][i] = t++;
			}
			for (int i = start_x + 1; i < start_x + m; i++)
			{
				result[i][start_x + n - 1] = t++;
			}
			for (int i = start_x + n - 2; i >= start_x && m > 1; i--)
			{
				result[start_x + m - 1][i] = t++;
			}
			for (int i = start_x + m - 2; i > start_x && n > 1; i--)
			{
				result[i][start_x] = t++;
			}

			m -= 2;
			n -= 2;
			start_x += 1;
		}

		return result;

		
	}

	int halfSearch2(vector<vector<int>> data, int target, int start, int end) {

		if (start >= end)
		{
			if (target < data[start][0])
				return start - 1;
			return start;
		}
		int mid = int((start + end) / 2);

		if (data[mid][0] >= target && data[mid][1] <= target)
			return mid;
		else if (data[mid][0] > target)
			return halfSearch2(data, target, start, mid - 1);
		else
			return halfSearch2(data, target, mid + 1, end);
	}

	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> result;

		


		return result;
	}




	bool isMatch(string s, string p) {

		vector<Reg> lst;
		int len = p.length();
		for (int i = 0; i < len; i++) {
			
			if (s.at(i) == '.') {
			
			}
			else if (s.at(i) == '*') {
			
			}
			else {
			
			}


		
		}
		return true;
	}


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
	vector<int> v2 = { 3,1 };

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
	vector<int> arr001 = { 1,2 };
	vector<int> arr000 = { 0,1,2 };


	vector<string> d0 = { "This", "is", "an", "example", "of", "text", "justification." };
	vector<string> d1 = { "What","must","be","acknowledgment","shall","be" };
	vector<string> d2 = { "Science","is","what","we","understand","well","enough","to","explain",
		 "to","a","computer.","Art","is","everything","else","we","do" };


	vector<string> d3 = { "ask", "not", "what", "your", "country", "can", "do", "for", "you", "ask", "what", "you", "can", "do", "for", "your", "country" };

	vector<vector<int>> z0 = {
	  {1,   3,  5,  7},
	  {10, 11, 16, 20},
	  {23, 30, 34, 50}
	};
	vector<vector<int>> z1 = {
	  {1,   3,  5,  7},
	  {10, 11, 16, 20},
	  {23, 30, 34, 50}
	};
	vector<vector<int>> z2 = { {}
	};
	vector<int> c0 = { 2,0,2,1,1,0
	}; 
	vector<vector<char>> ee1 = {
  {'A','B','C','E'},
  {'S','F','C','S'},
  {'A','D','E','E'}
	};
	vector<int> vs2 = { 3,1 };
	vector<int> vs3 = {  };
	vector<int> vs4 = { 1,1 };

	cout << so.minWindow("ADOBECODEBANC", "ABC") << endl;

		cout << so.minWindow("acbbaca", "aba") << endl;
		cout << so.minWindow("ABAACBAB", "ABC") << endl;

	cout << so.minWindow("ABAACBAB", "CF") << endl;
	cout << so.minWindow("a", "a") << endl;
	cout << so.minWindow("a", "aa") << endl;

	//auto nd = fromArray({1,2,3,3,4,4,5});
	//printListNode(so.deleteDuplicates(nd));
	//auto nd1 = fromArray({ 1,1,1,2,3 });
	//printListNode(so.deleteDuplicates(nd1));
	//auto nd2 = fromArray({ 1,1,1,1 });
	//printListNode(so.deleteDuplicates(nd2));
	//auto nd3 = fromArray({ 1,2,3,3,4,4,5,5 });
	//printListNode(so.deleteDuplicates(nd3));

	//cout << so.search(vs2,0) << endl;
	//cout << so.search(vs3, 0) << endl;
	//cout << so.search(vs4, 0) << endl;


	//cout << (so.exist(ee1, "ABCCED") == true) << endl;
	//cout << (so.exist(ee1, "SEE") == true) << endl;
	//cout << (so.exist(ee1, "ABCB") == false) << endl;


	//printListNode(so.reverseBetween(fromArray({ 1,2 }), 3, 5));
	//printListNode(so.reverseBetween(fromArray({ 1,2,3,4,5 }), 1, 5));
	//printListNode(so.reverseBetween(fromArray({ 1,2,3,4,5 }), 3, 5));

	//printListNode(so.reverseBetween(fromArray({ 1,2,3,4,5 }), 2, 4));
	//printListNode(so.reverseBetween(fromArray({ 1,2,3,4,5 }), 1, 4));
	//cout << (so.numDecodings("2222") == 5) << endl;
	//cout << (so.numDecodings("1212") == 5) << endl;
	//cout << (so.numDecodings("100") == 0) << endl;
	//cout << (so.numDecodings("1110") == 2) << endl;
	//cout << (so.numDecodings("110") == 1) << endl;

	//cout << (so.numDecodings("101") == 1) << endl;

	//cout << (so.numDecodings("12") == 2) << endl;
	//cout << (so.numDecodings("226") == 3) << endl;
	//cout << (so.numDecodings("2262") == 3) << endl;


	//cout << (so.numDecodings("0") == 0) << endl;
	//cout << (so.numDecodings("10") == 1) << endl;


	//cout << so.simplifyPath("/.a/.b/.c/.../.././") << endl;
	//cout << so.simplifyPath("/...") << endl;
	//cout << so.simplifyPath("/home//foo/") << endl;
	//cout << so.simplifyPath("/../") << endl;
	//// 
	//cout << so.simplifyPath("/a/./b/../../c/") << endl;
	//cout << so.simplifyPath("/a/../../b/../c//.//") << endl;
	//cout << so.simplifyPath("/a//b////c/d//././/..") << endl;

	
/*
	cout << (so.searchMatrix(z0, 3) == true) << endl;
	cout << (so.searchMatrix(z1, 13) == true)<< endl;
	cout << (so.searchMatrix(z2, 13) == true) << endl;*/

	/*

	
	printVector(so.fullJustify(d3, 16), true);
	printVector(so.fullJustify(d0, 16), true);
	printVector(so.fullJustify(d1, 16), true);
	printVector(so.fullJustify(d2, 20), true);*/
	//cout << (so.isNumber(" +.8 ") == true) << endl;
	//cout << (so.isNumber(" .+1 ") == false) << endl;
	//cout << (so.isNumber(" 6+1 ") == false) << endl;
	//cout << (so.isNumber(" . ") == false) << endl;
	//cout << (so.isNumber(" ") == false) << endl;
	//cout << (so.isNumber(" .5 ") == true) << endl;
	//cout << (so.isNumber(" 3. ") == true) << endl;

	//cout << (so.isNumber("0") == true) << endl;
	//cout << (so.isNumber(" 0.1 ") == true) << endl;
	//cout << (so.isNumber("abc") == false) << endl;
	//cout << (so.isNumber("1 a") == false) << endl;
	//cout << (so.isNumber("2e10") == true) << endl;
	//cout << (so.isNumber(" -90e3   ") == true) << endl;
	//cout << (so.isNumber(" 1e") == false) << endl;
	//cout << (so.isNumber("e3") == false) << endl;
	//cout << (so.isNumber(" 6e-1") == true) << endl;
	//cout << (so.isNumber(" 99e2.5 ") == false) << endl;
	//cout << (so.isNumber("53.5e93") == true) << endl;
	//cout << (so.isNumber(" --6 ") == false) << endl;
	//cout << (so.isNumber("-+3") == false) << endl;
	//cout << (so.isNumber("95a54e53") == false) << endl;

	// printVector(so.generateMatrix(10));
	// printVector(so.combinationSum(arr000, 7));

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


