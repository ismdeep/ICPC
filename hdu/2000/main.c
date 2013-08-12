/*
 * Project     : 2000
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Mon Aug 27 21:02:16 2012 
 *
 */

#include <stdio.h>

char ch[100];


int main()
{
	int i;
	char ch_tmp;
	while (scanf("%s", &ch) != EOF)
	{
		//
		if (ch[0] > ch[1])
		{
			ch_tmp = ch[0];
			ch[0]  = ch[1];
			ch[1]  = ch_tmp;
		}
		if (ch[0] > ch[2])
		{
			ch_tmp = ch[0];
			ch[0]  = ch[2];
			ch[2]  = ch_tmp;
		}
		if (ch[1] > ch[2])
		{
			ch_tmp = ch[1];
			ch[1]  = ch[2];
			ch[2]  = ch_tmp;
		}
		//
		//
		printf("%c %c %c\n", ch[0], ch[1], ch[2]);
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

