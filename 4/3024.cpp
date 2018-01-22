#include<cstdio>
using namespace std;
int note[1001];
int main()
{
	int n,m;
	int p,w,v;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&p,&w,&v);
		for(int k=0;k<p;k++)
		{
			for(int j=m;j>=w;j--)
			{
				if(note[j]<note[j-w]+v)
					note[j]=note[j-w]+v;
			}
		}
	}
	printf("%d ", note[m]);
	return 0;
}
