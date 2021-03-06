#include<cstdio>
#include<iostream>
using namespace std;
class HeapSmall
{
	long long *array;
	int currentSize;
	int maxSize;
	void percolateDown(int hole)
	{
		long long temp=array[hole];
		int child;
		while(2*hole<=currentSize)
		{
			child=2*hole;
			if(child<currentSize) 
				child=array[child+1]<array[child]?child+1:child;
			if(array[child]<temp)
			{
				array[hole]=array[child];
				hole=child;
			}
			else break;
		}
		array[hole]=temp;
	}
public:
	HeapSmall(int n):currentSize(0),maxSize(n)
	{
		array=new long long[n+1];
	}
	~HeapSmall(){delete[] array;}
	void insert(long long x)
	{
		int hole=++currentSize;
		while(hole/2&&array[hole/2]>x)
		{
			array[hole]=array[hole/2];
			hole>>=1;
		}
		array[hole]=x;
	}
	long long pop()
	{
		long long temp=array[1];
		array[1]=array[currentSize];
		currentSize--;
		percolateDown(1);return temp;
	}
	long long top()
	{
		return array[1];
	}
	bool isEmpty(){return currentSize==0;}
};
class HeapBig
{
	struct Stu
	{
		long long ac,w;
	};
	Stu* array;
	int currentSize;
	int maxSize;
	void percolateDown(int hole)
	{
		Stu temp=array[hole];
		int child;
		while(2*hole<=currentSize)
		{
			child=2*hole;
			if(child<currentSize) 
				child=array[child+1].ac>array[child].ac?child+1:child;
			if(array[child].ac>temp.ac)
			{
				array[hole]=array[child];
				hole=child;
			}
			else break;
		}
		array[hole]=temp;
	}
public:
	HeapBig(int n):currentSize(0),maxSize(n)
	{
		array=new Stu[n+1];
	}
	~HeapBig(){delete[] array;}
	void insert(long long x,long long y)
	{
		int hole=++currentSize;
		Stu temp;
		temp.ac=x;temp.w=y;
		while(hole/2&&array[hole/2].ac<temp.ac)
		{
			array[hole]=array[hole/2];
			hole>>=1;
		}
		array[hole]=temp;
	}
	void pop()
	{
		array[1]=array[currentSize];
		currentSize--;
		percolateDown(1);
	}
	long long top_ac(){return array[1].ac;}
	long long top_w(){return array[1].w;}
	bool isEmpty(){return currentSize==0;}
};
int main()
{
	int n;
	scanf("%d",&n);
	long long *ac=new long long[n],*w=new long long[n];
	HeapBig heapB(n);
	HeapSmall heapS(n);
	for(int i=0;i<n;i++)
		scanf("%lld%lld",ac+i,w+i);
	long long myScore=ac[0];
	int rank=1;
	for(int i=1;i<n;i++)
	{
		if(ac[i]>myScore)
		{
			rank++;
			heapS.insert(w[i]-ac[i]);
		}
		else heapB.insert(ac[i],w[i]);
	}
	int ans=rank;
	while(myScore&&!heapS.isEmpty()&&heapS.top()+1<=myScore)
	{
		myScore-=(heapS.pop()+1);
		rank--;
		while(!heapB.isEmpty()&&myScore<heapB.top_ac())
		{
			rank++;
			heapS.insert(heapB.top_w()-heapB.top_ac());
			heapB.pop();
		}
		if(ans>rank) ans=rank;
	}
	printf("%d\n", ans);
	return 0;
}