#include "pch.h"


#include "stdio.h"
#include "string.h"
#include "math.h"
#include "stdlib.h"


int mainZuobiao()
{
	

	char ch;
	char cmd[1000];
	int idx = 0;


	while (true) {
		int x = 0, y = 0;
		while ((ch = getchar()) != '\n') {
			if (ch < 0)
				return 0;
			if (ch != ';') {
				cmd[idx++] = ch;

			}
			else {
				int s = 0;
				if (idx > 0 && (cmd[0] == 'A' || cmd[0] == 'D' || cmd[0] == 'W' || cmd[0] == 'S')) {

					for (int i = 1; i < idx; i++) {
						if (cmd[i] >= '0' && cmd[i] <= '9') {
							s = s * 10 + cmd[i] - '0';
						}
						else {
							s = 0;
							break;
						}
					}
				}

				if (s > 0) {

					switch (cmd[0])
					{
					case 'A':
						x -= s;
						break;
					case 'D':
						x += s;
						break;
					case 'S':
						y -= s;
						break;
					case 'W':
						y += s;
						break;
					default:
						break;
					}
				}

				idx = 0;
			}
		}
		printf("%d,%d\n", x, y);
	}
	


	return 0;
}
