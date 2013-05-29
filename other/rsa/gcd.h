//File name : gcd.h
//Author:¼üÅÌÉ±ÊÖ

/************************int gcd(int,int)***************************/
int gcd(int a,int b)
{
    if( a > b )
	{
	    int temp;
		temp = a;
		a = b;
		b = temp;
	}
	
	while( a != 0)
	{
	    int temp;
		temp = b % a;
		b = a;
		a = temp;
	}
	
	return b;
}
