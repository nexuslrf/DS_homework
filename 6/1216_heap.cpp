#include<cstdio>
using namespace std;
const int MAX_INT=2147483647;
class  Heap
{
	int currentSize;
	int *array;
	int maxSize;
	void percolateDown(int hole)
	{
		int child;
		int temp=array[hole];
		for(;hole*2<=currentSize;hole=child)
		{
			child=hole*2;
			if(child!=currentSize&&array[child+1]<array[child])
				child++;
			if(array[child]<temp)
				array[hole]=array[child];
			else
				break;
		}
		array[hole]=temp;
	}
public:
	 Heap(int n)
	 {
	 	currentSize=0;
	 	maxSize=n;
	 	array=new int[n];
	 }
	~ Heap() { delete[] array;}
	void insert(int x)
	{
		array[++currentSize]=x;
		int i=currentSize;
		while(i/2&&array[i/2]>array[i])
		{
			int temp=array[i];
			array[i]=array[i/2];
			array[i/2]=temp;
			i=i>>1;
		}
	}
	int find(int x,int hole,int &pos)
	{
		if(hole>currentSize)
		{
			pos=0; return MAX_INT;
		}
		if(array[hole]>x)
		{
			pos=hole;
			return array[hole];
		}
		else
		{
			int i,j,a,b;
			a=find(x,hole*2,i);
			b=find(x,hole*2+1,j);
			if(a<b){pos=i;return a;}
			else if(a>b) {pos=j;return b;}
			else {pos=i<j?i:j;return a;}
		}
	}
	void decrease(int i,int v)
	{
		if(i>currentSize) return;
		array[i]-=v;
		if(v>0)
		{
			int p=i; 
			while(p/2&&array[p/2]>array[p])
			{
				int temp=array[p];
				array[p]=array[p/2];
				array[p/2]=temp;
				p=p>>1;
			}
		}
		else if(v<0)
			percolateDown(i);
	}
};
int main()
{
	int m;
	scanf("%d",&m);
	char commd[10];
	int x,y,pos;
	Heap heap(20001);
	for(int i=0;i<m;i++)
	{
		scanf("%s",commd);
		switch(commd[0])
		{
			case 'i': scanf("%d",&x); heap.insert(x);break;
			case 'f': scanf("%d",&x); heap.find(x,1,pos);printf("%d\n", pos); break;
			case 'd': scanf("%d%d",&x,&y); heap.decrease(x,y);break;
		}
	}
	return 0;
}