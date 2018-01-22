#include<cstdio>
#include<iostream>
using namespace std;
int dp[1001];
int n,m;

void ZeroOne_Pack(int cost,int weight,int n)
{
    for(int i=n; i>=cost; i--)
        dp[i] = max(dp[i],dp[i-cost] + weight);
}

void Complete_Pack(int cost,int weight,int n)
{
    for(int i=cost; i<=n; i++)
        dp[i] = max(dp[i],dp[i-cost] + weight);
}

int Multi_Pack(int c[],int w[],int num[],int n,int m)
{
   // memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++)
    {
        if(num[i]*c[i] > m)
            Complete_Pack(c[i],w[i],m);
        else
        {
            int k = 1;
            while(k < num[i])
            {
                ZeroOne_Pack(k*c[i],k*w[i],m);
                num[i] -= k;
                k <<= 1;
            }
            ZeroOne_Pack(num[i]*c[i],num[i]*w[i],m);
        }
    }
    return dp[m];
}

int main()
{
    scanf("%d%d",&n,&m);
    int p,w,v;
    for(int i=1; i<=n; i++)
    {
    	scanf("%d%d%d",&p,&w,&v);
        if(p*w > m)
            Complete_Pack(w,v,m);
        else
        {
            int k = 1;
            while(k < p)
            {
                ZeroOne_Pack(k*w,k*v,m);
                p -= k;
                k <<= 1;
            }
            ZeroOne_Pack(p*w,p*v,m);
        }
    }
    printf("%d", dp[m]);
    return 0;
}

// 5 40
// 3 4 5
// 4 5 6
// 3 6 8
// 3 3 2
// 4 9 10