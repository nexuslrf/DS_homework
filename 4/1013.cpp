#include<cstdio>
using namespace std;
int main()
{
	int v,n;
	scanf("%d %d",&v,&n);
	int c,w;
	int *ans=new int[v+1];
	for(int i=0;i<=v;i++)
		ans[i]=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&c,&w);
		for(int j=c;j<=v;j++)
		{
			if(ans[j]<ans[j-c]+w)
			{
				ans[j]=ans[j-c]+w;
			}
		}
	}
	printf("%d", ans[v]);
	delete[] ans;
	return 0;
}