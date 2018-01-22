#include<cstdio>
#include<iostream>
using namespace std;
int lowbit(int n)
{
	return n&-n;
}
class treeArry
{
	int size;
	long long* elem;
	public:
		treeArry(int n):size(n)
		{
			elem=new long long[n+1];
			for(int i=0;i<=n;i++)
				elem[i]=0;
		}
		~treeArry()
		{
			delete[] elem;
		}
		void update(int x,int y)
		{
			while(x<=size)
			{
				elem[x]+=y;
				x+=lowbit(x);
			}
		}
		int sum(int k)
		{
			int t=0;
			while(k>0)
			{
			//	printf("%d#%d ",t,k);
				t+=elem[k];
				k-=lowbit(k);
				
			}
			return t;
		}
};
int main()
{
	int n;
	scanf("%d",&n);
	treeArry tree(n);
	int temp; 
	long long total=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&temp);
		tree.update(temp,1);
		total+=i-tree.sum(temp);
	 }	
	cout<<total;
	return 0;
}
