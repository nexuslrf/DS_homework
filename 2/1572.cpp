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
	int tail;
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
struct Pair
{
	int val,pos;
 };
void merge(Pair* num,int a,int mid,int b)
{
	Pair* temp=new Pair[b-a+1];
	int i=a,j=mid,k=0;
	while(i<mid&&j<=b)
		if(num[i].val<num[j].val)
			temp[k++]=num[i++];
		else temp[k++]=num[j++];
	while(i<mid) temp[k++]=num[i++];
	while(j<=b) temp[k++]=num[j++];
	for(i=0,k=a;k<=b;)
		num[k++]=temp[i++];
	delete[] temp;
}
void mergesort(Pair* num,int a,int b)
{
	int mid=(a+b)/2;
	if(a==b) return;
	mergesort(num,a,mid);
	mergesort(num,mid+1,b);
	merge(num,a,mid+1,b);
}
int main()
{
	int n,indx=1;
	scanf("%d",&n);
	Pair* num=new Pair[n+1];
	int* track=new int[n+1];
	treeArry tree(n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i+1].val);
		num[i+1].pos=i+1;
	 }
	mergesort(num,1,n);
	//printf("zz");
	for(int i=1;i<=n;i++)
	{
	//	printf("%d@%d ",num[i].val,num[i].pos);
		track[num[i].pos]=indx++;
	}
	long long total=0;
	for(int i=1;i<=n;i++)
	{
		tree.update(track[i],1);
		total+=i-tree.sum(track[i]);
	}
	cout<<total;
	delete[] num;
	delete[] track;
	return 0;
}
