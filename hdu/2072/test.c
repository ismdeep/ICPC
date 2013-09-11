#include <iostream>
#include <set>
#include <iterator>
#include <sstream>
#include <string>
int main(){
using namespace std;
string line;
while(getline(cin,line),line!="#"){
  istringstream iss(line);
  set<string> s((istream_iterator<string>(iss)),istream_iterator<string>());
  cout<<s.size()<<endl;
}
return !cout;
}

