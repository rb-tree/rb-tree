# include <cstdio>
# include <algorithm>

using namespace std ;

const int N = 20005 ;

int chicken [ N ] ;
bool visit [ N ] ;

struct Cow
{
    int l , r ;
};

bool operator < ( Cow a , Cow b ) // 按右端点升序排序
{
    return a . r < b . r ;
}

Cow cow [ N ] ;

int read ( ) // 事实上在本题优化不大，但还是加上
{
    int a = 0 ;
    char c = getchar ( ) ;
    
    while ( c < '0' || c > '9' )
    {
        c = getchar ( ) ;
    }
    
    while ( c >= '0' && c <= '9' )
    {
        a = a * 10 + c - '0' ;
        c = getchar ( ) ;
    }
    
    return a ;
}

int main ( )
{
    int n = read ( ) , m = read ( ) ;
    
    for ( int i = 1 ; i <= n ; ++ i )
    {
        chicken [ i ] = read ( ) ;
    }
    
    sort ( chicken + 1 , chicken + n + 1 ) ;
    
    for ( int i = 1 ; i <= m ; ++ i )
    {
        cow [ i ] . l = read ( ) ;
        cow [ i ] . r = read ( ) ;
    }
    
    sort ( cow + 1 , cow + m + 1 ) ;
    
    int ans = 0 ;
    
    for ( int i = 1 ; i <= m ; ++ i )
    {
        for ( int j = 1 ; j <= n ; ++ j )
        {
            if ( chicken [ j ] < cow [ i ] . l ) // 还没进区间就下一个
            {
                continue ;
            }
            
            if ( chicken [ j ] > cow [ i ] . r ) // 过了区间就直接结束
            {
                break ;
            }
            
            if ( visit [ j ] ) // 因为要一一对应，已经匹配过的就不能再匹配了
            {
                continue ;
            }
            
            ++ ans ;
            visit [ j ] = 1 ;
            break ;
        }
    }
    
    printf ( "%d" , ans ) ;
}
