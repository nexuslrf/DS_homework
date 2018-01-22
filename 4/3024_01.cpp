#include<cstdio>
using namespace std;
int note[2001][1001];
int main()
{
	int n,m;
	int p,w,v;
	scanf("%d%d",&n,&m);
	int idx=1;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&p,&w,&v);
		for(int j=0;j<p;j++)
		{
			for(int k=0;k<=m;k++)
			{
				if(k<w)
					note[idx][k]=note[idx-1][k];
				else if(note[idx-1][k]<note[idx-1][k-w]+v)
					note[idx][k]=note[idx-1][k-w]+v;
				else
					note[idx][k]=note[idx-1][k];
			}
			idx++;
		}
	}
	printf("%d ", note[idx-1][m]);
	return 0;
}