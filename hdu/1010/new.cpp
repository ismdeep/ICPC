
 #include<iostream>
 #include<cstring>
 #define N 10
 
 using namespace std;
 
 int n,m,t,end_i,end_j;
 bool visited[N][N],flag,ans;
 char map[N][N];
 
 int abs(int a,int b)
 {
     if(a<b) return b-a;
     else return a-b;
 }
 
 void DFS(int i,int j,int c)
 {
     if(flag) return ;
     if(c>t) return ;    
     if(i<0||i>=n||j<0||j>=m) {return ;}
     if(map[i][j]=='D'&&c==t) {flag=ans=true; return ;}
     int temp=abs(i,end_i)+abs(j,end_j);
     temp=t-temp-c;
     if(temp&1) return ;//奇偶剪枝
 
     if(!visited[i-1][j]&&map[i-1][j]!='X') 
     {
         visited[i-1][j]=true;
         DFS(i-1,j,c+1);
         visited[i-1][j]=false;
     }
     if(!visited[i+1][j]&&map[i+1][j]!='X') 
     {
         visited[i+1][j]=true;
         DFS(i+1,j,c+1);
         visited[i+1][j]=false;
     }
     if(!visited[i][j-1]&&map[i][j-1]!='X') 
     {
         visited[i][j-1]=true;
         DFS(i,j-1,c+1);
         visited[i][j-1]=false;
     }
     if(!visited[i][j+1]&&map[i][j+1]!='X') 
     {
         visited[i][j+1]=true;
         DFS(i,j+1,c+1);
         visited[i][j+1]=false;
     }
 }
 
 int main()
 {
     int i,j,x,y,k;
     while(cin>>m>>n>>t&&(m||n||t))
     {
         memset(visited,false,sizeof(visited));
         k=0;
         for(i=0;i<n;i++)
         {
             for(j=0;j<m;j++)
             {
                 cin>>map[i][j];
                 if(map[i][j]=='S')
                 {
                     x=i;y=j;
                     visited[i][j]=true;
                 }
                 if(map[i][j]=='D')
                 {
                     end_i=i;end_j=j;
                 }
                 if(map[i][j]=='X')k++;
             }
         }
         ans=flag=false;
         if(n*m-k-1>=t) DFS(x,y,0);
         if(ans) cout<<"YES"<<endl;
         else cout<<"NO"<<endl;
     }
     return 0;
 }
 
