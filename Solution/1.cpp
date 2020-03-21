#include "pch.h"


#include "stdio.h"
#include "string.h"
#include "math.h"
#include "stdlib.h"


#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define ERR 5
#define PRI 6
//
//A类地址1.0.0.0~126.255.255.255;
//B类地址128.0.0.0~191.255.255.255;
//C类地址192.0.0.0~223.255.255.255;
//D类地址224.0.0.0~239.255.255.255；
//E类地址240.0.0.0~255.255.255.255
//私网IP范围是：
//10.0.0.0～10.255.255.255
//172.16.0.0～172.31.255.255
//192.168.0.0～192.168.255.255

int getip(char * ips,int length, unsigned int * output) {

	char ip[4] = { 0 };
	unsigned int t = 0;
	unsigned int a = 0;
	for (int i = 0; i < length; i++) {
		if (ips[i] >= '0' && ips[i] <= '9') {
			t = t * 10 + ips[i] - '0';
		}
		else if (ips[i] == '.' || ips[i] == '~') {
			
			if (t > 255)
				return -1;
			if (i > 0 &&  (ips[i - 1] < '0' || ips[i - 1] > '9') )
			{
				return -1;
			}
			if (i < length-1 && (ips[i +1] < '0' || ips[i + 1] > '9') )
			{
				return -1;
			}
			
			a = (a << 8) + t;
			if (ips[i] == '~') {

				if (a << 8 == a)
				{
					// skip
					return 1;
				}

				*output = a;
				output++;
				a = 0;
			}


			t = 0;
		}
		else {
			// invalid
			return -1;
		}
	}
	return 0;
}

int main111()
{
	char ips[40] = { 0 };

	int r[] = {0,0,0,0,0,0,0 };


	unsigned int out[2] = { 0 };

	char ip_p0[] = "10.0.0.0~10.255.255.255~";
	char ip_p1[] = "172.16.0.0~172.31.255.255~";
	char ip_p2[] = "192.168.0.0~192.168.255.255~";

	
	char ip_a[] = "1.0.0.0~126.255.255.255~";
	char ip_b[] = "128.0.0.0~191.255.255.255~";
	char ip_c[] = "192.0.0.0~223.255.255.255~";
	char ip_d[] = "224.0.0.0~239.255.255.255~";
	char ip_e[] = "240.0.0.0~255.255.255.255~";


	//getip(ip_p0, strlen(ip_p0), out);
	//printf("P0=%u,%u\n", out[0], out[1]);
	//getip(ip_p1, strlen(ip_p1), out);
	//printf("P1=%u,%u\n", out[0], out[1]);
	//getip(ip_p2, strlen(ip_p2), out);
	//printf("P2=%u,%u\n", out[0], out[1]);

	//getip(ip_a, strlen(ip_a), out);
	//printf("A=%u,%u\n", out[0], out[1]);
	//getip(ip_b, strlen(ip_b), out);
	//printf("B=%u,%u\n", out[0], out[1]);
	//getip(ip_c, strlen(ip_c), out);
	//printf("C=%u,%u\n", out[0], out[1]);
	//getip(ip_d, strlen(ip_d), out);
	//printf("D=%u,%u\n", out[0], out[1]);
	//getip(ip_e, strlen(ip_e), out);
	//printf("E=%u,%u\n", out[0], out[1]);


	while (~scanf_s("%s", ips,40) ) {

		int len = strlen(ips);
		if (len <= 4)
			break;
		ips[len] = '~';
		ips[len + 1] = '\0';

		int ret = getip(ips, len + 1, out);
		if (ret == 0) {
			// printf("%d,%d\n", out[0], out[1]);

			if (out[1] == 0 || out[1] == 16777215)
			{
				r[ERR] ++;
				continue;
			}
			bool iserror = false;
			for (int k = 0; k < 31; k++) {
				char b = 1 & (out[1] >> (32 - k - 1));
				if (b == 0) {
					if ( 0xffffffff & (out[1] << (k + 1)) != 0) {
						r[ERR] ++;
						iserror = true;
						break;
					}
				}
			}
			if (iserror)
				continue;

			/*

		P0=167772160,184549375
		P1=2886729728,2887778303
		P2=3232235520,3232301055
		A=16777216,2130706431
		B=2147483648,3221225471
		C=3221225472,3758096383
		D=3758096384,4026531839
		E=4026531840,4294967295
		*/
			if (out[0] >= 16777216 && out[0] <= 2130706431) {
				r[A] ++;
			}
			else if (out[0] >= 2147483648 && out[0] <= 3221225471) {
				r[B] ++;
			}
			else if (out[0] >= 3221225472 && out[0] <= 3758096383) {
				r[C] ++;
			}
			else if (out[0] >= 3758096384 && out[0] <= 4026531839) {
				r[D] ++;
			}
			else if (out[0] >= 4026531840 && out[0] <= 4294967295) {
				r[E] ++;
			}

			if (out[0] >= 167772160 && out[0] <= 184549375) {
				r[PRI] ++;
			}
			else if (out[0] >= 2886729728 && out[0] <= 2887778303) {
				r[PRI] ++;
			}
			else if (out[0] >= 3232235520 && out[0] <= 3232301055) {
				r[PRI] ++;
			}
		}
		else if (ret == -1){
			r[ERR] ++;
		}
		else {
			
		}
	}

	printf("%d,%d,%d,%d,%d,%d,%d\n",r[A], r[B], r[C], r[D], r[E], r[ERR], r[PRI]);

	return 0;
}
