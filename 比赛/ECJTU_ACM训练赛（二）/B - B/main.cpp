#include <iostream>

using namespace std;

int main()
{
    string str;
    while (cin >> str)
    {
        int left_index = 0;
        int right_index = str.length() - 1;
        int count = 0;
        int output_blank_just_now = false;
        for (int index = left_index; index <= right_index; index++)
        {
            if (str[index] == 'W' && str[index+1] == 'U' && str[index+2] == 'B')
            {
                if (count && !output_blank_just_now)
                {
                    cout << " ";
                    output_blank_just_now = true;
                }
                count++;
                index += 2;
            }
            else
            {
                cout << str[index];
                output_blank_just_now = false;
            }
        }
    }
    return 0;
}
