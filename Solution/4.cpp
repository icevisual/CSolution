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


int main444()
{
	char src[100] = { 0 };



	while (~scanf_s("%[^\n]%*c", src, 100)) {
		int len = strlen(src);
		

		for (int i = 0; i < len; i++) {
		
			if (src[i] >= 'A' && src[i] <= 'Z') {
			
				src[i] = src[i] - 'A' + 'a' + 1;
				if (src[i] > 'z')
					src[i] = 'a';
			}
			else if (src[i] >= 'a' && src[i] <= 'z') {

				if (src[i] >= 'a' && src[i] <= 'c') {
					src[i] = '2';
				}
				else if (src[i] >= 'd' && src[i] <= 'f') {
					src[i] = '3';
				}
				else if (src[i] >= 'g' && src[i] <= 'i') {
					src[i] = '4';
				}
				else if (src[i] >= 'j' && src[i] <= 'l') {
					src[i] = '5';
				}
				else if (src[i] >= 'm' && src[i] <= 'o') {
					src[i] = '6';
				}
				else if (src[i] >= 'p' && src[i] <= 's') {
					src[i] = '7';
				}
				else if (src[i] >= 't' && src[i] <= 'v') {
					src[i] = '8';
				}
				else if (src[i] >= 'w' && src[i] <= 'z') {
					src[i] = '9';
				}
				
			}
		}
		printf("%s\n",src);
		// �� 1--1�� abc--2, def--3, ghi--4, jkl--5, mno--6, pqrs--7, tuv--8 wxyz--9, 0--0,����ô�򵥣�
		// Ԩ�Ӱ������г��ֵ�Сд��ĸ����ɶ�Ӧ�����֣����ֺ������ķ��Ŷ������任��
		// ������������û�пո񣬶������г��ֵĴ�д��ĸ����Сд֮��������һλ��
		// �磺X���ȱ��Сд����������һλ��������y����򵥰ɡ���ס��z��������aŶ��

	}

	return 0;
}
