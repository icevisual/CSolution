#include "pch.h"


#include "stdio.h"
#include "string.h"
#include "math.h"
#include "stdlib.h"

int main555()
{
	int n = 0;
	int i = 0;
	while (scanf_s("%d", &n) != EOF) {
		if (n == 0)
			break;
		printf("%d\n", int(ceil(n / 2)));
		i++;
		if (i >= 10) break;
	}
	return 0;
}
