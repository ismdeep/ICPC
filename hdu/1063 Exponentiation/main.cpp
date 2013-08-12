#include <iostream>
using namespace std;

class Number
{
public:
    int* iLeft;
    int  iTopLeft;
    int* iRight;
    int  iTopRight;

    void setValue(string);
    void setvalueExponentiation(Number,int);
    void showValue();
};

void Number::setValue(string s)
{
    iLeft  = new int[s.length()];
    iRight = new int[s.length()];
}

void Number::setvalueExponentiation(Number num, int k)
{
}

void Number::showValue()
{
}

int main()
{
    string s;
    int    k;
    while (cin >> s >> k)
    {
        Number iNum;
        iNum.setValue(s);

        Number iSum;
        iSum.setvalueExponentiation(iNum, k);

        iNum.showValue();
    }
    return 0;
}

// end
// ism

