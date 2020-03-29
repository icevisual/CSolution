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

bool IsSubInt(int s, int n) {

	if (n == 0)
	{

		if (s == 0)
			return true;
		while (s > 0) {
			if (s % 10 == 0)
				return true;
			s = int(s / 10);
		}
		return false;
	}

	int t = 1;

	int z = 10;

	while (n >= z) {
		z *= 10;
	}

	while (s > 0) {
		cout << ((s % z) ^ n) << endl;
		if (((s % z) ^ n) == 0)
			return true;
		s = int(s / 10);
	}


	return false;
}



int main777()
{

/*
	cout << IsSubInt(10451, 10) << endl;

	cout << IsSubInt(2002, 100) << endl;
	cout << IsSubInt(1, 0) << endl;

	cout << IsSubInt(3, 3) << endl;
	cout << IsSubInt(1, 1) << endl;
	cout << IsSubInt(0, 0) << endl;

	cout << IsSubInt(30, 0) << endl;
	cout << IsSubInt(303, 0) << endl;
	cout << IsSubInt(300, 3) << endl;
	cout << IsSubInt(2300, 3) << endl;
	cout << IsSubInt(2300, 23) << endl;
	cout << IsSubInt(2300, 30) << endl;
	cout << IsSubInt(2300, 300) << endl;
	cout << IsSubInt(2300, 2300) << endl;

*/


	int n_I = 0;
	int n_R = 0;
	int t;
	while (cin >> n_I) {
		;
		vector<int> I;
		vector<int> R;
		while (n_I--) {

			cin >> t;
			I.push_back(t);
		}
		cin >> n_R;
		while (n_R--) {

			cin >> t;
			R.push_back(t);
		}

		sort(R.begin(), R.end());

		vector<string> result;
		int total = 0;
		for (int i = 0; i < R.size(); i++)
		{

			if (i > 0 && R[i] == R[i - 1])
				continue;

			ostringstream out;
			int c = 0;
			for (int j = 0; j < I.size(); j++) {

				if (IsSubInt(I[j], R[i])) {

					if (c == 0) {
						out << j << " " << I[j];
					}
					else {
						out << " " << j << " " << I[j];
					}
					c++;
				}
			}
			if (c > 0) {
				ostringstream out1;
				out1 << R[i] << " " << c << " " << out.str();
				result.push_back(out1.str());
				total += (c + 1) << 1;
			}
		}

		cout << total;

		for (int i = 0; i < result.size(); i++) {


			cout << " ";
			cout << result[i];
		}
		cout << endl;
	}

	return 0;
}
