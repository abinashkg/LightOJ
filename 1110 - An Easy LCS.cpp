//Abinash Ghosh(Om)
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <sstream>
#include <algorithm>
using  namespace  std;

#define PI acos(-1.0)
#define MAX 10000007
#define EPS 1e-9
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define Sort(x) sort(x.begin(),x.end())
#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define pr(x) cout<<x<<"\n"
#define pr2(x,y) cout<<x<<" "<<y<<"\n"
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

typedef  long long ll;
typedef  pair <int, int> pii;
typedef  pair <double , double> pdd;
typedef  pair <ll , ll > pll;
typedef  vector <int> vi;
typedef  vector <pii> vpii;
typedef  vector <ll > vl;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};
//int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
#define M 105
char a[M],b[M];
string s[M][M];
int dp[M][M];
int solve(int i,int j)
{
    if(i<=0||j<=0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(a[i-1]==b[j-1])
    {
        dp[i][j]=1+solve(i-1,j-1);
        s[i][j]=s[i-1][j-1]+a[i-1];
    }
    else
    {
        dp[i-1][j]=solve(i-1,j);
        dp[i][j-1]=solve(i,j-1);
        if(dp[i-1][j]>dp[i][j-1])
        {
            dp[i][j]=dp[i-1][j];
            s[i][j]=s[i-1][j];
        }
        else if(dp[i][j-1]>dp[i-1][j])
        {
            dp[i][j]=dp[i][j-1];
            s[i][j]=s[i][j-1];
        }
        else
        {
            dp[i][j]=dp[i][j-1];
            if(s[i-1][j]>s[i][j-1])s[i][j]=s[i][j-1];
            else s[i][j]=s[i-1][j];
        }
    }
    return dp[i][j];
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T;
    scanf("%d",&T);
    FOR(t,1,T)
    {
        scanf("%s%s",&a,&b);
        mem(dp,-1);
        int x=strlen(a);
        int y=strlen(b);
        solve(x,y);
        printf("Case %d: ",t);
        if(s[x][y].length()>0)
        printf("%s\n",s[x][y].c_str());
        else printf(":(\n");
    }
    return 0;
}
/*
3
ab
ba
zxcvbn
hjgasbznxbzmx
you
kjhs
*/
