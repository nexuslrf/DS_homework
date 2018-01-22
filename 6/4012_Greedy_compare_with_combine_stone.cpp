#include<cstdio>
using namespace std;
class Heap
{
	int maxSize;
	int currentSize;
	int *array;
	void percalateDown(int hole)
	{
		int child;
		int temp=array[hole];
		while(hole*2<=currentSize)
		{
			child=2*hole;
			if(child+1<=currentSize&&array[child]>array[child+1])
				child+=1;
			if(array[child]<temp)
			{
				array[hole]=array[child]; hole=child;
			}
			else break;
		}
		array[hole]=temp;
	}
public:
	Heap(int n)
	{
		maxSize=n;
		array=new int[n+1];
		currentSize=0;
	}
	~Heap() {delete[] array;}
	void insert(int x)
	{
		int i=++currentSize;
		while(i/2&&array[i/2]>x)
		{
			array[i]=array[i/2]; i=i/2;
		}
		array[i]=x;
	}
	int pop()
	{
		int t=array[1];
		array[1]=array[currentSize--];
		percalateDown(1);
		return t;
	}
	bool isEmpty(){return currentSize==0;}
};
int main()
{
	int n,ans=0,dx;
	scanf("%d",&n);
	int *a=new int[n];
	Heap heap(n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		heap.insert(a[i]);
	}
	for(int i=0;i<n-1;i++)
	{
		dx=heap.pop()+heap.pop();
		//printf("%d\n", dx);
		ans+=dx;
		heap.insert(dx);
	}
	printf("%d", ans);
	return 0;
}