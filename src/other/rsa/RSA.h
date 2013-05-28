//project name:rsa ( rsa )
//Author:键盘杀手
//Creat Date & Time:Wed Apr 18 18:38:02 2012

#include <iostream>
#include "Integer.h"
#include "gcd.h"
#include "KU.h"
#include "KR.h"
using namespace std;

/****************************class RSA******************************/
class RSA/*RSA*/
{
private:
    KU ku;
	KR kr;
	long long int plaintext;/*明文*/
	long long int ciphertext;/*密文*/
public:
    void Decode();/*加密函数*/
	void Encode();/*解密函数*/
	
	//接下来是设置值的一些set函数
	void setKU(int,int);
	void setKR(int,int,int);
	void setPlaintext(long long int);
	void setCiphertext(long long int);
	
	//output for test
	//输出测试代码
	void outputForTest();
	
};

//void setKU(int e, int n)
void RSA::setKU(int e, int n)
{
    this->ku.e = e;
	this->ku.n = n;
}
//void setKR(int d, int p, int q)
void RSA::setKR(int d, int p, int q)
{
    this->kr.d = d;
	this->kr.p = p;
	this->kr.q = q;
}
//void setPlaintext(int plaintext)
void RSA::setPlaintext(long long int plaintext)
{
    this->plaintext = plaintext;
}
//void setCiphertext(int ciphertext)
void RSA::setCiphertext(long long int ciphertext)
{
    this->ciphertext = ciphertext;
}
//void outputForTest()
void RSA::outputForTest()
{
    cout<<"ku"<<endl;
	cout<<" "<<"e:"<<ku.e<<endl;
	cout<<" "<<"n:"<<ku.n<<endl;
	
	cout<<"kr"<<endl;
	cout<<" "<<"d:"<<kr.d<<endl;
	cout<<" "<<"p:"<<kr.p<<endl;
	cout<<" "<<"q:"<<kr.q<<endl;
	
	cout<<"plaintext:";
	cout<<" "<<plaintext<<endl;
	
	cout<<"ciphertext:";
	cout<<" "<<ciphertext<<endl;
	
}

//void Decode():加密函数 plainetext to ciphertext
void RSA::Decode()
{
    ku.n = kr.p * kr.q;/*公开的*/
	int phiN;
	phiN = (kr.p-1)*(kr.q-1);
	
	int *mapE;//创建一个数组，存放e，
	mapE = new int[phiN];//phiN个数字。
	int top_mapE = -1;//mapE[] 的上界
	
	for(int i = 2; i < phiN; i++)
	{
	    if(gcd(i,phiN)==1)
		{
		    top_mapE++;
			mapE[top_mapE] = i;
		}
	}
	
	// output for test :
	for(int i = 0; i <= top_mapE; i++)
	{
	    cout << mapE[i] << " " << endl;
	}
	
	delete[] mapE;
}

//void Encode():解密函数 ciphertext to plaintext
void RSA::Encode()
{

}

//end
//ism
