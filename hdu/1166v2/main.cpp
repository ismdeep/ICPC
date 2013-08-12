#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
namespace ismdebug
{
    using namespace std;
    ifstream cin ("in.dat", ios::in);
    void debug()
    {
        cout << "--debug msg!" << endl;
    }
};

//using ismdebug::cin;
//using ismdebug::debug;
using std::cin;
using std::cout;
using std::endl;
using std::string;

#define MAXN 50050

int n;
int iMap[MAXN * 4];

int iSetNode(int iStart, int iEnd, int iID)
{
    if (iStart == iEnd)
    {
        //cout << "--" << iStart << "--" << endl;
        int iTmp;
        cin >> iTmp;
        iMap[iID] = iTmp;
        return iTmp;
    }
    else
    {
        int iMid;
        iMid = (iStart + iEnd) / 2;
        int iLeftSum,iRightSum;
        iLeftSum  = iSetNode(iStart, iMid, iID*2);
        iRightSum = iSetNode(iMid+1, iEnd, iID*2+1);
        iMap[iID] = iLeftSum + iRightSum;
        //cout << "--" << iStart << " , " << iEnd << "--" << iMap[iID] << " :id:" << iID << endl;
        return iMap[iID];
    }
}

void iShowMap()
{
    for (int i = 1; i <= n * 4; i++)
    {
        cout << iMap[i] << " ";
    }
    cout << endl;
}

void iCreator()
{
    memset(iMap,0,sizeof(iMap));
    iSetNode(1,n,1);
}

int iQuery(int iStart, int iEnd, int iID, int iStartQuery, int iEndQuery)
{
    if (iStart == iStartQuery && iEnd == iEndQuery)
    {
        //cout << iStart << "--" << iEnd << "=" << iMap[iID] << endl;
        //cout << "--------" << iStart << "-" << iEnd << ":" << iMap[iID] << endl;
        return iMap[iID];
    }
    else
    {
        int iMid = (iStart+iEnd) / 2;
        if (iMid >= iEndQuery)
        {
            return iQuery(iStart, iMid, iID*2, iStartQuery, iEndQuery);
        }
        else if (iMid+1 <= iStartQuery)
        {
            return iQuery(iMid+1,iEnd, iID*2+1, iStartQuery, iEndQuery);
        }
        else
        {
            int iLeftSum;
            int iRightSum;
            iLeftSum  = iQuery(iStart, iMid, iID*2,   iStartQuery, iMid);
            iRightSum = iQuery(iMid+1, iEnd, iID*2+1, iMid+1,      iEndQuery);
            return iLeftSum+iRightSum;
        }
    }
}

void iAdd(int iStart, int iEnd,int iID, int iFlag, int num)
{
    if (iStart == iEnd)
    {
        iMap[iID] += num;
    }
    else
    {
        int iMid = (iStart + iEnd) / 2;
        if (iFlag <= iMid)
        {
            iAdd(iStart, iMid, iID*2,   iFlag, num);
        }
        else
        {
            iAdd(iMid+1, iEnd, iID*2+1, iFlag, num);
        }
        iMap[iID] += num;
    }
}

void iSub(int iStart, int iEnd, int iID, int iFlag, int num)
{
    if (iStart == iEnd)
    {
        iMap[iID] -= num;
    }
    else
    {
        int iMid = (iStart + iEnd) / 2;
        if (iFlag <= iMid)
        {
            iSub(iStart, iMid, iID*2, iFlag, num);
        }

        else
        {
            iSub(iMid+1, iEnd, iID*2+1, iFlag, num);
        }
        iMap[iID] -= num;
    }
}



int main()
{
    int t;
    cin >> t;
    int iCaseCount;
    for (iCaseCount = 1; iCaseCount <= t; iCaseCount++)
    {
        //cout << "Case " << iCaseCount << ":" << endl;
        printf("Case %d:\n", iCaseCount);
        //cin >> n;
        scanf("%d", &n);
        iCreator();
        char iInstruction[100];
        while (scanf("%s", iInstruction) != EOF && strcmp(iInstruction, "End") != 0/*cin >> iInstruction && iInstruction != "End"*/)
        {
            if (strcmp(iInstruction,"Query") == 0/*iInstruction == "Query"*/)
            {
                int iQueryStart,iQueryEnd;
                //cin >> iQueryStart >> iQueryEnd;
                scanf("%d%d", &iQueryStart, &iQueryEnd);
                //cout << iQuery(1,n,1,iQueryStart,iQueryEnd) << endl;
                printf("%d\n", iQuery(1,n,1,iQueryStart,iQueryEnd));
            }
            if (strcmp(iInstruction, "Add") == 0/*iInstruction == "Add"*/)
            {
                int iFlag, iNum;
                //cin >> iFlag >> iNum;
                scanf("%d%d", &iFlag, &iNum);
                iAdd(1,n,1,iFlag,iNum);
                //iShowMap();
            }
            if (strcmp(iInstruction, "Sub") == 0/*iInstruction == "Sub"*/)
            {
                int iFlag, iNum;
                //cin >> iFlag >> iNum;
                scanf("%d%d", &iFlag, &iNum);
                iSub(1,n,1,iFlag,iNum);
            }
        }
    }
    return 0;
}

// end
// ism
