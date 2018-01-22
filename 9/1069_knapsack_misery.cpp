#include<cstdio>
#include<iostream>
#include<cstring>
// 做这道题时 因为写错了多重背包，花费了快一天的时间来debug; tmd写代码的时候带着脑子啊！！！
// 像 z*=2 你写成 z<<=1 没有问题， 但是！ 你tm写成 z<<=idx idx可是在递增的呀！老哥！
// 还有多重背包 的 bit trick 你光是增大比特位数而不减小相应的背包数，还玩个鸡儿！！
// 还没完。。。。 在完全背包的情况下你让 循环范围为从 t开始到 m,这就把 t之前的叠加数给搞没啦！
// 这并不是 完全的背包它还是有变化的 老哥， 码的时候多想想。。
using namespace std;
struct coin
{
	int val;
	int num;
};
coin coins[101];
int note[100001];
int main()
{
	int n,m,ans,t;
	scanf("%d%d",&n,&m);
	while(n&&m)
	{
		ans=0;
		for(int i=1;i<=m;i++) 
		{
			note[i]=0;
		}
		note[0]=1;
		for(int i=0;i<n;i++)
			scanf("%d",&coins[i].val);
		for(int i=0;i<n;i++)
			scanf("%d",&coins[i].num);
		for(int i=0;i<n;i++)
		{
			t=coins[i].val;
			if(t>m) continue;
			if(t*coins[i].num>=m)
			{
				for(int j=0;j<=m;j++)
				{
					if(note[j])
					{
						if(j+t<=m&&!note[j+t])
						{
							note[j+t]=1;
							ans++;
						}
					}	
				}
			}
			else
			{
				int idx=0,z=t;
				while(coins[i].num>(1<<idx))
				{
					coins[i].num-=(1<<idx);
					for(int j=m;j>=z;j--)
					{
						if(!note[j]&&note[j-z])
						{
							note[j]=1;
							ans++;
						}
					}
					// if(i==11)
					// {
					// 	cout<<i<<'.'<<idx<<": "<<z<<endl;
					// 	for(int ii=1;ii<=m;ii++)
					// 	{
					// 		cout<<ii<<":"<<note[ii]<<"  ";
					// 	}
					// 	cout<<endl;
					// }
					idx++;z<<=1;
				}
				z=t*coins[i].num;
				if(z)
				for(int j=m;j>=z;j--)
				{
					if(!note[j]&&note[j-z])
					{
						note[j]=1;
						ans++;
					}
				}
			}
			// cout<<i<<": "<<coins[i].val<<endl;
			// for(int ii=1;ii<=m;ii++)
			// {
			// 	cout<<ii<<":"<<note[ii]<<"  ";
			// }
			// cout<<endl;
		}
		printf("%d\n", ans);
		// int xx=0;
		// for(int i=1;i<=m;i++)
		// 	if(note[i])
		// 	{
		// 		xx++;
		// 		cout<<i<<" ";
		// 	}
		//printf("\n%d\n",xx);
		scanf("%d%d",&n,&m);
	}
}