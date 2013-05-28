// project name : 2043 (密码)
// file name : main.cpp
// author : 键盘杀手
// date & time : 2012 5 14 -> 16:42

#include <iostream>
using namespace std;

class Mass
{
public:
    int top;
    char ch[40];
    bool exist(char);
    void print();
};

//////////////////////////////////////////////////////////////////////////////
void Mass::print()
{
    for(int i = 0; i <= top; i++)
    {
        cout << ch[i] << " ";
    }
    cout << endl;
}
//////////////////////////////////////////////////////////////////////////////
bool Mass::exist(char c)
{
    bool found = false;
    for(int i = 0; !found && i <= top; i++)
    {
        if(ch[i] == c)
        {
            found = true;
        }
    }
    return found;
}
//////////////////////////////////////////////////////////////////////////////
/*
mass[4] of Mass 
-->mass[0] 'A' ~ 'Z'
-->mass[1] 'a' ~ 'z'
-->mass[2] '0' ~ '9'
-->mass[3] ~,!,@,#,$,%,^;
*/
Mass mass[4];

void init()
{
    mass[0].ch[0] = 'A';
    for(int i = 0; i < 26; i++)
    {
        mass[0].ch[i] = mass[0].ch[0] + i;
    }
    mass[0].top = 25;
    
    mass[1].ch[0] = 'a';
    for(int i = 0; i < 26; i++)
    {
        mass[1].ch[i] = mass[1].ch[0] + i;
    }
    mass[1].top = 25;
    
    mass[2].ch[0] = '0';
    for(int i = 0; i < 10; i++)
    {
        mass[2].ch[i] = mass[2].ch[0] + i;
    }
    mass[2].top = 9;
    
    mass[3].ch[0] = '~';
    mass[3].ch[1] = '!';
    mass[3].ch[2] = '@';
    mass[3].ch[3] = '#';
    mass[3].ch[4] = '$';
    mass[3].ch[5] = '%';
    mass[3].ch[6] = '^';
    mass[3].top = 6;
}

int main()
{
    init();// 初始化数据
    
    int t;
    cin >> t;
    while( t-- )
    {
        string s;
        cin >> s;
        bool yes = false;
        
        int current = 0;
        while( s[current] != '\0' ){current++;}
        if(current >=8 && current <= 16 )
        {
            yes = true;
        }
        
        int count = 0;
        bool found = false;
        for(int i = 0; !found && i < current; i++)
        {
            if(mass[0].exist(s[i]))
            {
                found = true;
                count++;
            }
        }
        
        found = false;
        for(int i = 0; !found && i < current; i++)
        {
            if(mass[1].exist(s[i]))
            {
                found = true;
                count++;
            }
        }
        
        found = false;
        for(int i = 0; !found && i < current; i++)
        {
            if(mass[2].exist(s[i]))
            {
                found = true;
                count++;
            }
        }
        
        found = false;
        for(int i = 0; !found && i < current; i++)
        {
            if(mass[3].exist(s[i]))
            {
                found = true;
                count++;
            }
        }
        
        if(count < 3)
        {
            yes =false;
        }
        
        
        
        //judge it
        if(yes) cout << "YES" << endl;
        else cout << "NO" << endl;
        
    }
    return 0;
}
//end
//ism

