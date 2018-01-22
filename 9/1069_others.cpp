#include"stdio.h"
#include<iostream>
using namespace std;
int main(){
    int dp[100005];
    int n,m=100005,i,j,k,price[105],num[105],count;
    while(scanf("%d %d",&n,&m)!=EOF){
        count=0;
        for(i=1;i<=m;i++) dp[i]=0;
        if(n==0&&m==0) break;
        for(i=1;i<=n;i++){
            scanf("%d",&price[i]);
        }
        for(i=1;i<=n;i++){
            scanf("%d",&num[i]);
        }
        for(i=1;i<=n;i++){
            for(k=1;k<=num[i]/2;k=k*2){
                for(j=m;j>=price[i]*k;j--){   
                if(dp[j-price[i]*k]+price[i]*k>dp[j])
                    dp[j]=dp[j-price[i]*k]+price[i]*k;
                }       
            }
                k=num[i]-k+1;
                for(j=m;j>=price[i]*k;j--){
                    if(dp[j-price[i]*k]+price[i]*k>dp[j])
                    dp[j]=dp[j-price[i]*k]+price[i]*k;
                }
           
        }
        for(i=1;i<=m;i++){
            if(dp[i]==i)    count++;
        }
       
        printf("%d\n",count);
       // int xx=0;
       //  for(int i=1;i<=m;i++)
       //      if(dp[i]==i)
       //      {
       //          xx++;
       //          cout<<i<<" ";
       //      }
       //  printf("\n%d\n",xx);
    }
    return 0;
}