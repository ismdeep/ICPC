#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;
//关键字数组
char KEYWORD[55][15] = {"auto","bool","break","case","catch","char","class","const","continue","default","delete","do","double","else","enum","explicit","extern","false","float","for","friend","goto","if","inline","int","long","mutable","namespace",
"new","operator","private","protected","public","register","return","short","signed","sizeof","static","struct","switch","template","this","true","try",
"typedef","typeid","typename","union","unsigned","using","virtual","void","volatile","while"};


//函数名：CmpStr,比较两个字符串
//参数：strS,待比较的数组指针.strK,用来比较的数组指针，这里是关键字
//返回值：若待比较的数组后的几个字母和关键字的一样则返回真
//描述:只是用后面的来测试前面的看一部分是否相等，不同是strcmp
bool CmpStr(char *strS, char *strK)
{
    int i;
    if (strlen(strS) >= strlen(strK))
    {
        for (i=0; i<(int)strlen(strK); i++)
        {
            if (*(strS+i) != *(strK+i))
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}


//函数名：ForKey，由判断字符串之前来决定此字符串是否是从指针除开始的
//参数：str，字符串指针。len，字符串长度
//返回值：如果符合条件返回真
bool ForKey(char *str, int len)
{
    if ((int)strlen(str) < len)
    {
        if ( (*(str-1) != ';') && (*(str-1) != '\x28') && (*(str-1) != '*') )
        {
            return false;
        }
        return true;
    }
    return true;
}


//函数名：ChangeType,改变文本形式
//参数：某字符串的指针
//返回值：无
void ChangeType(char *str)
{
    int sCounter;  //原数组元素指示
    int dCounter = 0;  //转换数组的元素指示
    char strCopy[700] = {'\0'};     //
    for (sCounter=0; sCounter<(int)strlen(str); sCounter++)
    {
        switch(str[sCounter])
        {
            case ' ':
                 strcpy(&strCopy[dCounter],"&nbsp;");
                 dCounter += 6;
                 break;
            case '<':
                 strcpy(&strCopy[dCounter],"&lt;");
                 dCounter += 4;
                 break;
            case '>':
                 strcpy(&strCopy[dCounter],"&gt;");
                 dCounter += 4;
                 break;
            case '"':
                 strcpy(&strCopy[dCounter],"&quot;");
                 dCounter += 6;
                 break;
            case '&':
                 strcpy(&strCopy[dCounter],"&amp;");
                 dCounter += 5;
                 break;
            case '/':
                 strcpy(&strCopy[dCounter],"&#47;");
                 dCounter += 5;
                 break;
            default:
                 strCopy[dCounter] = str[sCounter];
                 dCounter +=1;
                 break;
        }
    }
    strcpy(&str[0], &strCopy[0]);
}


//函数名：ChangeColor,改变文本的颜色
//参数：字符串的指针
//返回值：无
void ChangeColor(char *str)
{
    int sCounter;
    int sCounter2;
    int dCounter = 0;
    int keywordC;

    static bool fNotes = false;

    char strCopy[700] = {'\0'};
    for (sCounter=0; sCounter<(int)strlen(str); sCounter++)
    {
        if (CmpStr(&str[sCounter], "&#47;*"))
        {
            fNotes = true;
            strcpy(&strCopy[dCounter], "<span style=\"color:#008000;\">");
            dCounter += 29;
            strncpy(&strCopy[dCounter], &str[sCounter], strlen(&str[0])-sCounter);
            dCounter += strlen(&str[0])-sCounter;
            strcpy(&strCopy[dCounter], "</span>");
            sCounter = sCounter + strlen(&str[0])-sCounter-1;
            dCounter += 7;
            goto FF1;
        }

        for (sCounter2=0; sCounter2<strlen(&str[0]); sCounter2++)
        {
            if (CmpStr(&str[sCounter2], "*&#47;"))
            {
                fNotes = false;
                strcpy(&strCopy[dCounter], "<span style=\"color:#008000;\">");
                dCounter += 29;
                strncpy(&strCopy[dCounter], &str[sCounter], strlen(&str[0]));
                dCounter += strlen(&str[0]);
                strcpy(&strCopy[dCounter], "</span>");
                sCounter = sCounter + strlen(&str[0])-1;
                dCounter += 7;
                goto FF1;
            }
        }


        if (fNotes == true)
        {
            strcpy(&strCopy[dCounter], "<span style=\"color:#008000;\">");
            dCounter += 29;
            strncpy(&strCopy[dCounter], &str[sCounter], strlen(&str[0]));
            dCounter += strlen(&str[0]);
            strcpy(&strCopy[dCounter], "</span>");
            sCounter = sCounter + strlen(&str[0])-1;
            dCounter += 7;
            goto FF1;
        }


        if (CmpStr(&str[sCounter], "&#47;&#47;"))
        {
            strcpy(&strCopy[dCounter], "<span style=\"color:#008000;\">");
            dCounter += 29;
            strncpy(&strCopy[dCounter], &str[sCounter], strlen(&str[0])-sCounter);
            dCounter += strlen(&str[0])-sCounter;
            strcpy(&strCopy[dCounter], "</span>");
            sCounter = sCounter + strlen(&str[0])-sCounter-1;
            dCounter += 7;
            goto FF1;
        }

        for (keywordC=0; keywordC<55; keywordC++)
        {
            if ( CmpStr(&str[sCounter], KEYWORD[keywordC]) && ( CmpStr(&str[sCounter+strlen(KEYWORD[keywordC])], "&nbsp;") || str[sCounter+strlen(KEYWORD[keywordC])] == '(' || str[sCounter+strlen(KEYWORD[keywordC])] == '\0' || str[sCounter+strlen(KEYWORD[keywordC])] == '*' ) && ForKey(&str[sCounter], strlen(&str[0])) )
            {
                strcpy(&strCopy[dCounter], "<span style=\"color:#0000ff;\">");
                dCounter += 29;
                strncpy(&strCopy[dCounter], &str[sCounter], strlen(KEYWORD[keywordC]));
                dCounter += strlen(KEYWORD[keywordC]);
                strcpy(&strCopy[dCounter], "</span>");
                sCounter = sCounter + strlen(KEYWORD[keywordC]) - 1;
                dCounter += 7;
                goto FF1;
            }
        }
        strCopy[dCounter] = str[sCounter];
        dCounter +=1;
        FF1:  ;
    }
    strcpy(&str[0], &strCopy[0]);
}


//主函数
int main()
{
    ifstream fin("in.cpp");
    ofstream fout("2.html");

    fout << "<div style=\"font:14px/16px Consolas,Fixedsys,Arial;\">" << endl;

    while (!fin.eof())
    {
        char sentence[700] = {'\0'};
        fin.getline(&sentence[0], 700);
        ChangeType(sentence);
        ChangeColor(sentence);
        fout << &sentence[0] << "<br />";
    }

    fout << "</div>";

    fout.close();
    return 0;
}
