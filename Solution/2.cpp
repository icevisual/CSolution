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

int main()
{

	char file[100] = {0};
	int line = 0;
	
	unordered_map<string, int> hash;

	while (~scanf_s("%s%d", file,100, &line)) {
	
		printf("%s %d\n",file,line);
		if (file[0] == '.')
			break;
		
		ostringstream os;
		os << string(file) << " " << line;
		if (!KeyNotExistsAndSet(hash, os.str(), 1)) {
			hash[os.str()] ++;
		}

	}

	unordered_map<string, int>::iterator it = hash.begin();
	while (it != hash.end()) {

		int k = it->first.length();

		while (k >= 0 && it->first[k] != ' ') {
			k--;
		}
		int c = 0;
		while (c < 16 && k >= 0 && it->first[k] != '\\') {
			k--;
			c++;
		}

		cout << it->first.substr(k + 1, it->first.length() - k - 1) << " " << it->second << endl;
		it++;
	}

	system("pause");
	return 0;
}
