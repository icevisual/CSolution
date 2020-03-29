#include "pch.h"

#define SOLUTION
#ifndef SOLUTION
#define strcpy_s(a, b,c) strcpy(a,c)
#endif // !SOLUTION



#include "stdio.h"
#include "string.h"
#include "math.h"
#include "stdlib.h"

#include <sstream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

#define MAXIN 52



static string calc_hash(string str)
{
	char tmp[MAXIN] = { 0 };

	strcpy_s(tmp, MAXIN, str.c_str());
	sort(tmp, tmp + str.length());
	return string(tmp);
}

int main10()
{
	int n = 0;
	int m = 0;




	while (cin >> n)
	{
		int t = n;
		string word;
		unordered_map<string, vector<string>> hash;
		while (t--)
		{
			cin >> word;
			string key = calc_hash(word);

			auto it = hash.find(key);

			if (it == hash.end())
			{
				vector<string> lst;
				lst.push_back(word);
				hash.insert(pair<string, vector<string>>(key, lst));
			}
			else
			{
				hash[key].push_back(word);
			}
		}
		cin >> word;
		cin >> m;
		int mm = m;
		string key = calc_hash(word);
		auto it = hash.find(key);

		if (it == hash.end())
		{
			// 查不到，输出 0
			cout << 0 << endl;
		}
		else
		{
			auto rs = hash[key];
			// 字典序，需要排序
			sort(rs.begin(), rs.end());

			int c = rs.size();
			for (int i = 0; i < rs.size(); i++)
			{
				if (rs[i] != word) {

					m--;
					if (m == 0)
					{
						key = rs[i];
						// 需要完全遍历，以确定兄弟单词的数量
					}
				}
				else {
					c--;
				}
			}
			cout << c << endl;
			if (c > 0)
			{
				// m 大于 总个数，不输出
				if (mm <= c) {
					cout << key << endl;
				}

			}
		}
	}
	return 0;
}
