#include <iostream>
using namespace std;

template <class T> T add_two_value(T a, T b)
{
    T result;
    result = a + b;
    return result;
}

int main()
{
    int int_a, int_b, int_sum;
    int_a = 11;
    int_b = 645;
    int_sum = add_two_value(int_a, int_b);
    cout << int_a << " + " << int_b << " = " << int_sum << endl;
    //
    double dou_a, dou_b, dou_sum;
    dou_a = 2.718;
    dou_b = 34.23;
    dou_sum = add_two_value(dou_a, dou_b);
    cout << dou_a << " + " << dou_b << " = " << dou_sum << endl;
    //
    //
    return 0;
}

// end 
// iCoding
//

