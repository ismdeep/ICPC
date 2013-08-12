#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
class Node
{
public:
     int l,r,l_value,r_value;
     int cover,max;
};
class List
{
public:
     int start,end;
};
vector<List>list;
Node tree[250000];
int Max( int a, int b )
{
   return a > b ? a:b;
}
void Maketree( int l , int r, int cnt )
{
   tree[cnt].l = l;
   tree[cnt].r = r;
   tree[cnt].l_value = tree[cnt].r_value = tree[cnt].max = r - l +1;
   tree[cnt].cover = 0;
   if( l==r )
   {
        return ;
   }
   int mid = ( l + r )>>1;
   Maketree( l , mid, cnt*2 );
   Maketree( mid + 1 , r ,cnt*2+1 );
}
void fun( int cnt )
{
    if( tree[cnt].cover == 0 )
        tree[cnt].l_value = tree[cnt].r_value = tree[cnt].max = tree[cnt].r - tree[cnt].l +1;
    else
        tree[cnt].l_value = tree[cnt].r_value = tree[cnt].max = 0;
}
void Update( int l , int r , int cnt ,int num )
{
    if( l > tree[cnt].r || tree[cnt].l > r)
        return ;
    if( tree[cnt].l >= l &&tree[cnt].r <= r )
    {
         tree[cnt].cover = num;
         fun( cnt );
         return ;
    }
    if( tree[cnt].cover != -1 )
    {
         tree[cnt*2].cover = tree[cnt*2+1].cover =tree[cnt].cover;
         fun( cnt*2 );
         fun( cnt*2+1 );
         tree[cnt].cover = -1;
    }
    Update( l , r, cnt*2 , num );
    Update( l ,r ,cnt*2+1 , num );
    if( tree[cnt*2].cover==tree[cnt*2+1].cover )
        tree[cnt].cover = tree[cnt*2].cover;
    else tree[cnt].cover = -1;
    tree[cnt].l_value =  tree[cnt*2].l_value + (  tree[cnt*2].cover==0?tree[cnt*2+1].l_value:0 );
    tree[cnt].r_value =  tree[cnt*2+1].r_value + ( tree[cnt*2+1].cover == 0? tree[cnt*2].r_value:0 );
    tree[cnt].max = Max( Max( tree[cnt*2].max , tree[cnt*2+1].max ), tree[cnt*2].r_value + tree[cnt*2+1].l_value );
}

int Query( int num, int cnt )
{
    if( tree[cnt].l_value >= num &&tree[cnt].cover ==0 )
    {

        Update( tree[cnt].l, tree[cnt].l+num -1 , 1, 1 );//    printf( "asfasfa" );
        return tree[cnt].l;
    }
    if( tree[cnt].cover == 1) return 0;
    if( tree[cnt].max>=num && tree[cnt].cover == -1 )
    {
        if( tree[cnt*2].max >= num )
        {
            return Query( num , cnt*2 );
        }
        else if( tree[cnt*2].r_value + tree[cnt*2+1].l_value >= num )
        {
            int t = tree[cnt*2].r - tree[cnt*2].r_value;
            Update( t +1, t + num  , 1 , 1 );
            return  t+1 ;
        }
        else return Query( num , cnt*2+1 );
    }
    return 0;
}
int find( int  n  )
{
     int begin = 0 ;
     int end = list.size()-1;
     while( begin <= end )
     {
         int mid = ( begin + end )>>1;
         if( list[mid].start > n )
            end = mid -1;
         else     begin = mid + 1;
     }
     return begin;
}
int main( )
{
   int n , m , num,left ,right;
   char str[10];
   while( scanf( "%d%d",&n,&m )==2 )
   {
      Maketree( 1 , n , 1 );
      list.clear();
      while( m-- )
      {
         scanf( "%s" ,str  );
         if( str[0]=='R' )
         {
                 printf( "Reset Now\n" );
                 Update(1 , n , 1,0 );
                 list.clear();
         }
         else
         {
            scanf( "%d",&num );
             switch( str[0] )
             {
                case 'N':  left = Query( num ,1 );

                          if( left ==0 ) printf( "Reject New\n" );
                          else
                          { right = find( left );
                            List  t; t.start = left ; t.end = left + num -1;
                            list.insert( list.begin() + right , t );
                            printf( "New at %d\n",left );
                          }
                          break;
                case 'F': right = find( num ) -1;
                          if( right ==-1||list[right].end < num )
                              printf( "Reject Free\n" );
                          else
                          {
                              printf( "Free from %d to %d\n",list[right].start , list[right].end );
                              Update( list[right].start, list[right].end ,1, 0);
                              list.erase( list.begin() + right   );
                          }
                          break;
                case 'G':
                        if( num > list.size() )
                            printf( "Reject Get\n" );
                        else printf( "Get at %d\n",list[num-1].start );
                        break;
             }
        }
      }
   }
   return 0;
}

