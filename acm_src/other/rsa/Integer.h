//File name:Integer.h
//Author:键盘杀手
//Creat Date & Time:Wed Apr 19 10:38:45 2012

#include <iostream>
using namespace std;

#define ONE_LENGTH 1000

class Integer
{
private:
    short *a;//存放数据的数组
	
	//数组暂时可以储存数据的长度 容错，
	//如果即将越界 那么就要重新分配计算. 
	//初始值 1000 以后如果不够则按此数倍数进行扩大
	int length;
	
	int top;//作为 高精度数 的 最高位标记
public:
    Integer();
	Integer(int);
	Integer(string);
	~Integer(){ delete[] a;}
	
	int getLength(){return this->length;}
	int getTop(){return this->top;}
	short getBit(int k){return this->a[k];}
};

/************************Integer::Integer()***************************/
Integer::Integer()
{
    a = new short[ONE_LENGTH];
	length = ONE_LENGTH;
	top = -1;
	for(int i = 0; i < length; i++)
	{
	    a[i] = 0;
	}
	
}

/************************Integer::Integer(int)*************************/
Integer::Integer(int integer)
{
    a = new short[ONE_LENGTH];
	length = ONE_LENGTH;
	for(int i = 0; i < length; i++)
	{
	    a[i] = 0;
	}
	
	top = -1;
	while(integer)
	{
	    top++;
		a[top] = integer % 10;
		integer = integer /10;
	}
	
}


/***********************Integer::Integer(string)*************************/
Integer::Integer(string s)
{
    a = new short[ONE_LENGTH];
	length = ONE_LENGTH;
	int top = -1;
	for(int i = 0; i < length; i++)
	{
	    a[i] = 0;
	}
	
	while(s[top] != '\0')
	{
	    top++;
	}
	
	cout << top << endl;
}

/*************************00***************************/
/*************************00***************************/
/*************************00***************************/
/*************************00***************************/
/*************************00***************************/
/*************************00***************************/
/*************************00***************************/

//end
//ism
