#include <iostream>
#include <fstream>
using namespace std;
const static char ip[] = {                   //IP置换
	   58, 50, 42, 34, 26, 18, 10,  2,
	   60, 52, 44, 36, 28, 20, 12,  4,
	   62, 54, 46, 38, 30, 22, 14,  6,
	   64, 56, 48, 40, 32, 24, 16,  8,
	   57, 49, 41, 33, 25, 17,  9,  1,
	   59, 51, 43, 35, 27, 19, 11,  3,
	   61, 53, 45, 37, 29, 21, 13,  5,
	   63, 55, 47, 39, 31, 23, 15,  7
};                                          
const static char fp[] = {					//zuizhongzhihuan 
	   40,  8, 48, 16, 56, 24, 64, 32,
	   39,  7, 47, 15, 55, 23, 63, 31,
	   38,  6, 46, 14, 54, 22, 62, 30,
	   37,  5, 45, 13, 53, 21, 61, 29,
	   36,  4, 44, 12, 52, 20, 60, 28,
	   35,  3, 43, 11, 51, 19, 59, 27,
	   34,  2, 42, 10, 50, 18, 58, 26,
	   33,  1, 41,  9, 49, 17, 57, 25
};
const static char sbox[8][64] = {				//s_box
	   /* S1 */
	   14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7,
		0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8,
		4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0,
	   15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13,

	   /* S2 */
	   15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10,
		3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5,
		0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15,
	   13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9,

	   /* S3 */
	   10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8,
	   13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1,
	   13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7,
		1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12,

	   /* S4 */
		7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15,
	   13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9,
	   10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4,
		3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14,

	   /* S5 */
		2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9,
	   14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6,
		4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14,
	   11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3,

	   /* S6 */
	   12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11,
	   10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8,
		9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6,
		4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13,

	   /* S7 */
		4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1,
	   13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6,
		1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2,
		6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12,

	   /* S8 */
	   13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7,
		1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2,
		7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8,
		2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11
};
const static char rar[] = {				//ya suo zhi huan
	   14, 17, 11, 24,  1,  5,
		3, 28, 15,  6, 21, 10,
	   23, 19, 12,  4, 26,  8,
	   16,  7, 27, 20, 13,  2,
	   41, 52, 31, 37, 47, 55,
	   30, 40, 51, 45, 33, 48,
	   44, 49, 39, 56, 34, 53,
	   46, 42, 50, 36, 29, 32
};
const static char ei[] = {				//kuo zhan zhi huan
	   32,  1,  2,  3,  4,  5,
		4,  5,  6,  7,  8,  9,
		8,  9, 10, 11, 12, 13,
	   12, 13, 14, 15, 16, 17,
	   16, 17, 18, 19, 20, 21,
	   20, 21, 22, 23, 24, 25,
	   24, 25, 26, 27, 28, 29,
	   28, 29, 30, 31, 32,  1
};
const static char Pzh[]={					//P置换
	   16,  7, 20, 21,
	   29, 12, 28, 17,
		1, 15, 23, 26,
		5, 18, 31, 10,
		2,  8, 24, 14,
	   32, 27,  3,  9,
	   19, 13, 30,  6,
	   22, 11,  4, 25
};
const static char Keyrar[]={
	   57, 49, 41, 33, 25, 17,  9,
		1, 58, 50, 42, 34, 26, 18,
	   10,  2, 59, 51, 43, 35, 27,
	   19, 11,  3, 60, 52, 44, 36,

	   63, 55, 47, 39, 31, 23, 15,
		7, 62, 54, 46, 38, 30, 22,
	   14,  6, 61, 53, 45, 37, 29,
	   21, 13,  5, 28, 20, 12,  4
};
bool key[16][48]={0};/*rekey[16][48],*/
char key_in[8];
void ByteToBit(bool *Out,char *In,int bits)		//字节到位的转换
{
	int i;
	for(i=0;i<bits;i++)
		Out[i]=(In[i/8]>>(i%8))&1;
}
void BitToByte(char *Out,bool *In,int bits)			//位到字节转换
{
	for(int i=0;i<bits/8;i++)
		Out[i]=0;
	for(int i=0;i<bits;i++)
		Out[i/8]|=In[i]<<(i%8);			//"|="组合了位操作符和赋值操作符的功能
}
void Xor(bool *InA,const bool *InB,int len)    //按位异或
{
	for(int i=0;i<len;i++)
		InA[i]^=InB[i];
}
void keyfc(char *In)              //获取密钥函数
{
	int i,j=0,mov,k;
	bool key0[56],temp,keyin[64];
	ByteToBit(keyin,In,64);           //字节到位的转换
	for(i=0;i<56;i++)                      //密钥压缩为56位
		key0[i]=keyin[Keyrar[i]-1];
	for(i=0;i<16;i++)       //16轮密钥产生
	{
		if(i==0||i==1||i==8||i==15)
			mov=1;
		else
			mov=2;
		for(k=0;k<mov;k++)    //分左右两块循环左移
		{
			for(int m=0;m<8;m++)
			{
				temp=key0[m*7];
				for(j=m*7;j<m*7+7;j++)
					key0[j]=key0[j+1];
				key0[m*7+6]=temp;
			}
			temp=key0[0];
			for(int m=0;m<27;m++)
				key0[m]=key0[m+1];
			key0[27]=temp;
			temp=key0[28];
			for(int m=28;m<55;m++)
				key0[m]=key0[m+1];
			key0[55]=temp;
		}

		for(j=0;j<48;j++)         //压缩置换并储存
		 	key[i][j]=key0[rar[j]-1];
	}
}

void DES(char Out[8],char In[8],bool MS)//加密核心程序,ms=0时加密，反之解密
{
	bool MW[64],tmp[32],PMW[64];	//注意指针
	bool kzmw[48],keytem[48],ss[32];
	int hang,lie;
	ByteToBit(PMW,In,64);
	for(int j=0;j<64;j++)
	{
		MW[j]=PMW[ip[j]-1];          //初始置换
	}
	bool *Li=&MW[0],*Ri=&MW[32];
	for(int i=0;i<48;i++)							//右明文扩展置换
		kzmw[i]=Ri[ei[i]-1];							//注意指针	

	if(MS==0)										//DES加密过程
	{
		for(int lun=0;lun<16;lun++)
		{
			for(int i=0;i<32;i++)
				ss[i]=Ri[i];
			for(int i=0;i<48;i++)							//右明文扩展置换
				kzmw[i]=Ri[ei[i]-1];							//注意指针
			for(int i=0;i<48;i++)
				keytem[i]=key[lun][i];						//轮密钥
			Xor(kzmw,keytem,48);
			/*S盒置换*/
			for(int i=0;i<8;i++)
			{
				hang=kzmw[i*6]*2+kzmw[i*6+5];
				lie =kzmw[i*6+1]*8+kzmw[i*6+2]*4+kzmw[i*6+3]*2+kzmw[i*6+4];
				tmp[i*4+3]=sbox[i][(hang+1)*16+lie]%2;
				tmp[i*4+2]=(sbox[i][(hang+1)*16+lie]/2)%2;
				tmp[i*4+1]=(sbox[i][(hang+1)*16+lie]/4)%2;
				tmp[i*4]=(sbox[i][(hang+1)*16+lie]/8)%2;
			}


			for(int i=0;i<32;i++)		//P置换		
				Ri[i]=tmp[Pzh[i]-1];
			Xor(Ri,Li,32);				//异或
			for(int i=0;i<32;i++)		//交换左右明文
			{
				Li[i]=ss[i];
			}
		}
		for(int i=0;i<32;i++)
		{
			tmp[i]=Li[i];
			Li[i]=Ri[i];
			Ri[i]=tmp[i];
		}
		for(int i=0;i<64;i++)
			PMW[i]=MW[fp[i]-1];
		BitToByte(Out,PMW,64);		//位到字节的转换	
	}
	else										//DES解密过程
	{
			
		for(int lun=15;lun>=0;lun--)
		{
		for(int i=0;i<32;i++)
			ss[i]=Ri[i];
		for(int i=0;i<48;i++)							//右明文扩展置换
			kzmw[i]=Ri[ei[i]-1];							//注意指针
		for(int i=0;i<48;i++)
			keytem[i]=key[lun][i];						//轮密钥
		Xor(kzmw,keytem,48);
		/*S盒置换*/
		for(int i=0;i<8;i++)
		{
			hang=kzmw[i*6]*2+kzmw[i*6+5];
			lie =kzmw[i*6+1]*8+kzmw[i*6+2]*4+kzmw[i*6+3]*2+kzmw[i*6+4];
			tmp[i*4+3]=sbox[i][(hang+1)*16+lie]%2;
			tmp[i*4+2]=(sbox[i][(hang+1)*16+lie]/2)%2;
			tmp[i*4+1]=(sbox[i][(hang+1)*16+lie]/4)%2;
			tmp[i*4]=(sbox[i][(hang+1)*16+lie]/8)%2;
		}


		for(int i=0;i<32;i++)		//P置换		
			Ri[i]=tmp[Pzh[i]-1];
		Xor(Ri,Li,32);				//异或
		for(int i=0;i<32;i++)		//交换左右明文
		{
				Li[i]=ss[i];
		}
			
		}
		for(int i=0;i<32;i++)
		{
			tmp[i]=Li[i];
			Li[i]=Ri[i];
			Ri[i]=tmp[i];
		}
		for(int i=0;i<64;i++)
			PMW[i]=MW[fp[i]-1];
		BitToByte(Out,PMW,64);		//位到字节的转换
	}
}
int main()
{
	char Ki[8],jm[8],final[8];
	int i0;
	cout<<"请输入密钥（8字节）："<<endl;
	for(i0=0;i0<8;i0++)
	cin>>Ki[i0];
//	if(i0<8)
//		for(i0=0;i0<8;i0++)
//		cin//[i0];
	keyfc(Ki);
	cout<<"请输入明文："<<endl;
	for(i0=0;i0<8;i0++)
	cin>>jm[i0];
	DES(final,jm,0);
	cout<<"加密后："<<endl;//加密
	for(i0=0;i0<8;i0++)
	cout<<final[i0];
	cout<<endl;
	cout<<"解密后："<<endl;
	DES(jm,final,1);			//解密
		for(i0=0;i0<8;i0++)
	cout<<jm[i0];
		cout<<endl;
		
		
	return 0;
}

// end 
// ism 
