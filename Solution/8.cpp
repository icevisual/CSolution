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

#define MAXIN 1000

int main888()
{
	char  t;
	char  line[MAXIN];
	char  r[MAXIN];
	while (~scanf_s("%[^\n]%*c",line, MAXIN)) {
		int len = strlen(line);
		strcpy_s(r, MAXIN,line);
		for (int i = 0; i < len; i++)
		{
			if (line[i] > 0 && !isalpha(line[i])) {
				continue;
			}
			int max_idx = 0;
			// char 255 = -1
			char max_ch = 127;


			for (int j = 0;  j < len; j ++) {
			
				if (!isalpha(line[j])) {
					continue;
				}
				t = line[j];
				if (t > 'Z')
					t = t - ('a' - 'A');

				if (t < max_ch) {
					max_idx = j;
					max_ch = t;
				}
			}
			r[i] = line[max_idx];
			line[max_idx] = 0;
		}

		r[len + 1] = 0;
		string result(r);
		cout << result << endl;
	}
	return 0;
}
