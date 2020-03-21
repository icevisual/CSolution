#include "pch.h"


#include "stdio.h"
#include "string.h"
#include "math.h"
#include "stdlib.h"

int main()
{
	char str[100];
	while (scanf_s("%s", str,100) != EOF) {
		
		int flag[28] = { 0 };
		char result[100] = {0};
		int min =11110;
		for (int i = 0; i < strlen(str); i++) {
		
			flag[str[i] - 'a'] ++;

		}

		for (int i = 0; i < 28; i++)
			if (flag[i] > 0 && flag[i] < min)
				min = flag[i];


		int j = 0;
		for (int i = 0; i < strlen(str); i++) {

			if (flag[str[i] - 'a'] != min) {
				result[j] = str[i];
				j++;
			}
		}
		printf("%s\n", result);
	}
	return 0;
}
