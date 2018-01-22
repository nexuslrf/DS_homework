#include<cstdio>
using namespace std;
struct Node
{
	int val;
	int money;
	int pos;
};
class priorityQueue
{
	int currentSize;
	Node *elem;
	int maxSize;
	int mod; //1 > 0<
	void doubleSpace()
	{
		Node *temp=new Node[2*maxSize];
		for(int i=0;i<maxSize;i++)
		{
			temp[i]=elem[i];
		}
		delete[] elem;
		elem=temp;
		maxSize*=2;
	}
	void percolateDown(int hole)
	{
		int child;
		Node tmp=elem[hole];
		if(mod)
			while(2*hole<=currentSize)
			{
				child=2*hole;
				if(child<currentSize&&elem[child+1].money>elem[child].money)
					child++;
				if(elem[child].money>tmp.money)
					elem[hole]=elem[child];
				else
					break;
				hole=child;
			}
		else
			while(2*hole<=currentSize)
			{
				child=2*hole;
				if(child<currentSize&&elem[child+1].money<elem[child].money)
					child++;
				if(elem[child].money<tmp.money)
					elem[hole]=elem[child];
				else
					break;
				hole=child;
			}
		elem[hole]=tmp;
	}
	void buildHeap()
	{
		for (int i = currentSize/2; i > 0; i--)
		{
			percolateDown(i);
		}
	}
public:
	priorityQueue(int c=100)
	{
		elem=new Node[c];
		maxSize=c;
		currentSize=0;
		mod=1;
	}
	priorityQueue(Node *p,int size,int m=1)
	{
		maxSize=size+10;
		currentSize=size;
		mod=m;
		elem=new Node[maxSize];
		for (int i = 0; i < currentSize; i++)
		{
			elem[i+1]=p[i];
		}
		buildHeap();
	}
	~priorityQueue(){ delete[] elem;}
	bool isEmpty(){return currentSize==0;}
	void enQueue(Node &x)
	{
		if(currentSize==maxSize-1) doubleSpace();
		int hole=++currentSize;
		if(mod)			
			while(hole/2&&elem[hole/2].money<x.money)
			{
				elem[hole]=elem[hole/2];
				hole/=2;
			}
		else
			while(hole/2&&elem[hole/2].money>x.money)
			{
				elem[hole]=elem[hole/2];
				hole/=2;
			}
		elem[hole]=x;
	}
	int deQueue()
	{
		int temp=elem[1].money;
		elem[1]=elem[currentSize--];
		percolateDown(1);
		return temp;
	}
	int getTop()
	{
		return elem[1].money;
	}
	int getToppos(){return elem[1].pos;}
};
void merge(Node *a,int s,int e,int mid)
{
	Node *temp=new Node[e-s+1];
	int i=s,j=mid+1,k=0;
	while(i<=mid&&j<=e)
	{
		if(a[i].val>a[j].val)
		{
			temp[k++]=a[i++];
		}
		else
			temp[k++]=a[j++];
	}
	while(i<=mid)
	{
		temp[k++]=a[i++];
	}
	while(j<=e)
		temp[k++]=a[j++];
	for(int i=0;i<k;i++)
	{
		a[s+i]=temp[i];
	}
	delete[] temp;
}
void mergesort(Node *a,int s,int e)
{
	if(s==e)
		return;
	int mid=(s+e)/2;
	mergesort(a,s,mid);
	mergesort(a,mid+1,e);
	merge(a,s,e,mid);
}
int main()
{
	int c,n,f;
	scanf("%d%d%d",&n,&c,&f);
	Node *stu=new Node[c];
	bool *note=new bool[c];
	for(int i=0;i<c;i++)
	{
		scanf("%d%d",&stu[i].val,&stu[i].money);
		stu[i].pos=i;
		note[i]=0;
	}
	mergesort(stu,0,c-1);
	priorityQueue front(stu,n/2,1);
	priorityQueue back(stu+n/2+1,c-n/2-1,0);
	int fsum=0,bsum=0;
	for(int i=0;i<n/2;i++)
	{
		fsum+=stu[i].money;
		note[back.getToppos()]=1;
		bsum+=back.deQueue();
	}
	//printf("%d %d\n",fsum,bsum);
	bool flag=1;
	if(fsum+bsum+stu[n/2].money<=f)
	{
		printf("%d", stu[n/2].val);
		flag=0;
	}
	for(int i=n/2+1;flag&&i<c-n/2;i++)
	{
		if(front.getTop()>stu[i-1].money)
		{
			fsum-=front.deQueue();
			fsum+=stu[i-1].money;
			front.enQueue(stu[i-1]);
		}
		if(note[stu[i].pos])
		{
			while(note[back.getToppos()])
				back.deQueue();
			note[back.getToppos()]=1;
			bsum+=back.deQueue();
		}
		else
			note[stu[i].pos]=1;
		if(fsum+bsum+stu[i].money<=f)
		{
			printf("%d", stu[i].val);
			flag=0;
			break;
		}
	}
	if(flag)
		printf("-1");
	delete[] stu,note;
	return 0;
}