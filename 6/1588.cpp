#include<cstdio>
using namespace std;
int search(int *b,int s,int e,int x)
{
	int mid;
	while(s<e)
	{
		mid=(s+e)/2;
		if(b[mid]>x) s=mid+1;
		else e=mid-1;
	}
	if(b[s]>x)
		return s;
	else return s-1;
}
int main()
{
	int n,idx=1,ans=1,pos=-1,temp;
	scanf("%d",&n);
	int *a=new int[n],*b=new int[n];
	b[0]=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		int j=search(b,0,idx-1,a[i]);
		//printf("%d %d %d ans:%d\n", j,pos,temp,ans7);
		if(j==idx-1&&b[j]>a[i])
			b[idx++]=a[i];
		else if(b[j+1]<=a[i])
		{
			if(j==-1&&b[0])
			{
				ans++;temp=b[j+1];
				pos=j+1;
			}
			else if(pos==-1&&idx!=1)
			{
				ans++;temp=b[j+1];
				pos=j+1;
			}
			else if(pos>=0)
			{
				 if(pos<j+1)
				{ 
					temp=b[j+1];
					pos=j+1;
				}
				else if(pos>j+1)
				{
					ans++; temp=b[j+1];
					pos=j+1;
				}
				else if(pos==j+1)
				{
					if(b[j+1]>=temp)
					{ans++; temp=b[j+1];}
					else temp=b[j+1];
				}
			}
			b[j+1]=a[i];
		}
	}
	printf("%d\n%d", idx,ans);
	delete[] a,b;
	return 0;
}