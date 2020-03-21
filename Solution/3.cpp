#include "pch.h"


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

template<typename T, typename T1>
bool KeyNotExistsAndSet(unordered_map<T, T1> &mp, T Key, T1 val) {
	if (mp.find(Key) == mp.end()) {
		mp.insert(pair<T, T1>(Key, val));
		return true;
	}
	return false;
}


int main333()
{
	char src[100] = { 0 };
	string record[8];
	int i = 0;


	while (~scanf_s("%[^\n]%*c", src, 100)) {
		int len = strlen(src);
		//1.长度超过8位
		if (len <= 8) {
		
			printf("NG\n");
		}
		else
		{
			
			//2.包括大小写字母.数字.其它符号, 以上四种至少三种
			int flag[4] = {0};
			for (int i = 0; i < len; i++)
			{
				if (src[i] >= '0' && src[i] <= '9') {
					flag[0] = 1;
				}
				else if (src[i] >= 'a' && src[i] <= 'z') {
					flag[1] = 1;
				}
				else if (src[i] >= 'A' && src[i] <= 'Z') {
					flag[2] = 1;
				}
				else {
					flag[3] = 1;
				}
			}

			if (flag[0] + flag[1] + flag[2] + flag[3] < 3) {
			
				printf("NG\n");
				continue;
			}
			unordered_map<string, int> hash;
			bool error = false;
			for (int i = 2; i < len; i++)
			{
				string sub(src, i - 2, 3);
				if (!KeyNotExistsAndSet(hash, sub, 1)) {
					printf("NG\n");
					error = true;
					break;
				}
			}
			//3.不能有相同长度超2的子串重复
			if (!error)
				printf("OK\n");
		}
	}

	return 0;
}
