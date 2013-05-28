#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
int t, n, wid, hig1, hig2;
char s;
cin >> t;
while(t--){
   cin >> s >> n;
   hig2 = hig1 = (n - 3)/2;
   if(n%2-1) hig2++;
   wid = n/6 + 1;
   cout << setfill(' ') << setw(wid) << ' ' << setw(hig2+1) << setfill(s) << '\n';
     for(int i=0; i<(hig1+hig2); i++){
    cout << setfill(s) << setw(wid) << s
        << setfill(' ') << setw(hig2) << ' '
        << setfill(s) << setw(wid) << s << endl;
    if(i==hig1-1 || i==hig1+hig2-1)
          cout << setfill(' ') << setw(wid) << ' ' << setw(hig2+1) << setfill(s) << '\n';
     }
   if(t) cout << endl;
}
}
