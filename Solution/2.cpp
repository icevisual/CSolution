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

int main22()
{
	char file[100] = {0};
	string record[8];
	int i = 0;
	unordered_map<string, int> hash;

	while (~scanf_s("%[^\n]%*c", file,100)) {
	
		if (file[0] == '.')
			break;
		int l = strlen(file);
		int k = l -  1;
		while (k >= 0 && file[k] == ' ') k--;
		while (k >= 0 && file[k] != ' ') k--;
		int c = 0;
		while (c <= 16 && k >= 0 && file[k] != '\\'&& file[k] != '/') {
			k--;
			c++;
		}
		string str(file, k + 1,l);
		if (!KeyNotExistsAndSet(hash, str, 1)) {
			hash[str] ++;
		}
		else
		{
			record[i % 8] = str;
			i++;
		}
		
	}

	if (i < 8) {
		for (int t = 0; t < i; t++) {
			cout << record[t] << " " <<hash[record[t]] << endl;
		}
	}
	else {
		
		for (int t = i ; t < i  + 8; t++) {
			cout << record[t % 8] << " " << hash[record[t % 8]] << endl;
		}
	}
	

	system("pause");
	return 0;
}
