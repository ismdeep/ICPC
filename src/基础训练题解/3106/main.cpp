// project   : 3106
// file name : main.cpp

#include <iostream>
using namespace std;

#define SPACE 32

int main()
{
    int n;
    while (cin >> n && n)
    {
        string str;
        int s_time, j_time, b_time;
        
        // input data 
        cin >> str;
        cin >> s_time >> j_time >> b_time;
        
        int score = 0;
        
        /* 争取赢 */
        /* 石头 kill 剪刀 */
        for (int i = 0; i < n; i++)
        {
            if (str[i] == 'J' && s_time > 0)
            {
                str[i] = SPACE;
                s_time--;
                score++;
            }
        }
        /* 剪刀 kill 布 */
        for (int i = 0; i < n; i++)
        {
            if (str[i] == 'B' && j_time > 0)
            {
                str[i] = SPACE;
                j_time--;
                score++;
            }
        }
        /* 布   kill 石头 */
        for (int i = 0; i < n; i++)
        {
            if (str[i] == 'S' && b_time > 0)
            {
                str[i] = SPACE;
                b_time--;
                score++;
            }
        }
        
        /* 争取平局 */
        /* 石头 */
        for (int i = 0; i < n; i++)
        {
            if (str[i] == 'S' && s_time > 0)
            {
                str[i] == SPACE;
                s_time--;
            }
        }
        /* 剪刀 */
        for (int i = 0; i < n; i++)
        {
            if (str[i] == 'J' && j_time > 0)
            {
                str[i] == SPACE;
                j_time--;
            }
        }
        /* 布 */
        for (int i = 0; i < n; i++)
        {
            if (str[i] == 'b' && b_time > 0)
            {
                str[i] == SPACE;
                b_time--;
            }
        }
        
        /* 只能被kill咯 */
        /* 剪刀 kill 石头 */
        for (int i = 0; i < n; i++)
        {
            if (str[i] == 'S' && j_time > 0)
            {
                str[i] = SPACE;
                j_time--;
                score--;
            }
        }
        /* 布 kill 剪刀 */
        for (int i = 0; i < n; i++)
        {
            if (str[i] == 'J' && b_time > 0)
            {
                str[i] = SPACE;
                b_time--;
                score--;
            }
        }
        /* 石头 kill 布 */
        for (int i = 0; i < n; i++)
        {
            if (str[i] == 'B' && s_time > 0)
            {
                str[i] = SPACE;
                s_time--;
                score--;
            }
        }
        
        cout << score << endl;
        
    }
    
    return 0;
}
// end 
// ism 

